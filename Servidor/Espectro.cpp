//
// Created by brayan on 3/7/20.
//
#include <z3.h>
#include <limits>
#include "Espectro.h"
#include "TList.h"
#include <cmath>
#include "Jugador.h"
#include "Matrix.h"



bool Espectro::checkearVision() {
    Jugador j=*Jugador::getJugador();
    return sqrt(pow(x - j.getX(), 2) + pow(y - j.getY(), 2)) < vision;
}

double f(int xi, int yi, int xf, int yf, float currentSteps){
    return currentSteps+sqrt(pow(xf-xi,2) +pow(yf-yi,2));
}

void Espectro::A(int xi, int yi, int xf, int yf){
    double min =std::numeric_limits<double>::max();
    double minTemp;

    //map[xf][yf]=9;

    int xmin;
    int ymin;

    int xtemp;
    int ytemp;

    int indexPos;
    string nodeValue;

    //Lista del camino seguido hasta cada nodo de la lista
    TList<string> paths=*new TList<string>;
    //Lista de nodos posibles
    TList<string> open=*new TList<string>;
    //LIsta de nodos evaluados
    TList<string> close=*new TList<string>;
    //Lista de cantidad de pasos antes de cada nodo
    TList<string> steps=*new TList<string>;

    //Nota: Para steps y paths, el indice es el mismo que tiene el nodo en la open list

    //Se agrega el nodo inicial a las listas
    steps.addLast("0");
    paths.addLast(to_string(xi) + ";" + to_string(yi));
    open.addLast(to_string(xi) + ";" + to_string(yi));

    while(open.largo!=0){
        //Se obtiene el nodo mas prometedor de los que estan en la open list
        min =std::numeric_limits<double>::max();
        for(int i=0;i<open.largo;i++){

            nodeValue=open.getNodoPos(i)->getValue();
            indexPos=nodeValue.find_first_of(';');
            xtemp=std::stoi(nodeValue.substr(0,indexPos));
            ytemp=std::stoi(nodeValue.substr(indexPos+1,nodeValue.length()-indexPos));
            minTemp=f(xtemp, ytemp, xf, yf, stof(steps.getNodoPos(i)->getValue()));

            if(min>minTemp){
                xmin=xtemp;
                ymin=ytemp;
                min=minTemp;
            }
        }

        //Se elimina el nodo escogido de la open list y se agrega a la close list
        int parentPos=open.getPos(to_string(xmin)+";"+to_string(ymin));
        open.deletePos(parentPos);
        close.addLast(to_string(xmin)+";"+to_string(ymin));
/**
        map[xmin][ymin]=3;
        for(int u=0;u<100;u++){
            for(int p=0;p<100;p++){
                std::cout<<map[u][p];
            }
            std::cout<<"\n";
        }
*/
        //Si es el penultimo nodo entonces se termina el programa y se actualiza el mapa con el path
        if(abs(xmin-xf)<2 &&abs(ymin-yf)<2){
            string path= paths.getNodoPos(parentPos)->getValue()+";";
            while (!path.empty()){
                indexPos=path.find_first_of(';');
                xtemp=std::stoi(path.substr(0,indexPos));
                nextX->addLast(xtemp);

                path=path.substr(indexPos+1, path.length()-indexPos);
                indexPos=path.find_first_of(';');
                ytemp=std::stoi(path.substr(0,indexPos));
                nextY->addLast(ytemp);

                path=path.substr(indexPos+1, path.length()-indexPos);

                //map[xtemp][ytemp]= 2;
                open = *new TList<string>;
            }
            nextY->addLast(yf);
            nextX->addLast(xf);
           /** for(int u=0;u<100;u++){
                for(int p=0;p<100;p++){
                    std::cout<<map[u][p];
                }
                std::cout<<"\n";
            }*/
        }else{
            string nodeText;
            //Se analiza el vecindario del escogido
            //Los ifs verifican que no se haya salido de la cuadricula
            for (int i=-1;i<2;i++){
                if(xmin+i<Matrix::SIZEX && xmin+i>-1){
                    for(int j=-1;j<2;j++){
                        if(ymin+j<Matrix::SIZEY && ymin+j>-1 ) {
                            if(map[xmin + i][ymin + j] != 1) {

                                //Si no se ha agregado el nodo entonces se agrega
                                nodeText = to_string(xmin + i) + ";" + to_string(ymin + j);
                                float thisParentSteps = stof(steps.getNodoPos(parentPos)->getValue())+sqrt(i*i+j*j);
                                if (open.getNodoVal(nodeText) == nullptr
                                    && close.getNodoVal(nodeText) == nullptr) {

                                    //Se agrega el nodo
                                    open.addLast(nodeText);
                                    //Se agrega su path copiando el del padre
                                    paths.addLast(paths.getNodoPos(parentPos)->getValue()
                                                  + ";" + nodeText);
                                    //Se agregan los steps que se llevan sumando los del padre
                                    steps.addLast(to_string(thisParentSteps));
                                    //map[xmin + i][ymin+j]=2;
                                }
                            }
                        }
                    }
                }
            }

            paths.deletePos(parentPos);
            steps.deletePos(parentPos);
        }
    }
}

void Espectro::perseguirA() {
    this->proceso=PersiguiendoA;
    nextX=new TList<int>;
    nextY=new TList<int>;

    A(x, y, Jugador::getJugador()->getX(), Jugador::getJugador()->getY());
    nextX->deletePos(0);
    nextY->deletePos(0);
}

void Espectro::breadcumbing(int attemp){
    TList<std::pair<int, int>>* traces=Jugador::getJugador()->getTraces();

    int nx;
    int ny;

    for(int i=visited+1;i<traces->largo;i++){
        std::pair<int, int> p =traces->getNodoPos(i)->getValue();
        if(p.first==x && p.second==y){
            if(i>visited) {
                visited = i;
            }
        }
    }

    if(visited<traces->largo-1 && visited>=0){
        std::pair<int, int> p =traces->getNodoPos(visited+1)->getValue();
        nx=p.first;
        ny=p.second;
        cout<<"Jugadorx: "+to_string(Jugador::getJugador()->getX())+" E: "+ to_string(nx);
    }else if(visited==-1){
        nx=vistox;
        ny=vistoy;
    } else{
        nx=x;
        ny=y;
    }
    nextX->addLast(nx);
    nextY->addLast(ny);
}

void Espectro::perseguirBread() {
    nextX=new TList<int>;
    nextY=new TList<int>;
    this->proceso=PersiguiendoBread;
    breadcumbing(4);
}

/**
 * This function marks the neighborhood of (xi,yi) with mark, as long as it hasnt been marked
 * by previous steps
 * @tparam r Map rows
 * @tparam c Map columns
 * @param xi X position
 * @param yi Y position
 * @param map Map
 * @param mark New mark
 * @param step Step creating the mark
 */
void mark(int xi, int yi, int** map, int mark, int step){
    int tmp;
    for (int i=-1;i<2;i++){
        if(xi+i<Matrix::SIZEX && xi+i>-1){
            for(int j=-1;j<2;j++){
                tmp= map[xi+i][yi+j];
                if(yi+j<Matrix::SIZEY && yi+j>-1 && (tmp==0 || tmp==step)){
                    map[xi+i][yi+j]=mark;
                }
            }
        }
    }
}


/**
 *
 * @param xi Current x
 * @param yi Current y
 * @param xf Final x (goal)
 * @param yf Final y (goal)
 * @param step Number of current call to backtracking
 * @param map
 * @param done Boolean pointer that indicates if the goal has been reached
 * @return
 */
int Espectro::volverBacktrAux(int xi, int yi, int xf, int yf, int step, bool* done)
{
    //If object is on goal, exists
    if (xi==xf && yi==yf) {
        *done = true;
        return step;
    } else if(map[xi][yi]==1){
        nextX->addLast(xi);
        nextY->addLast(yi);
        return step-1;
    }else{
        //The possible steps from here are marked so that they won't be
        //reached by future calls
        int pos=nextX->largo;
        nextX->addLast(xi);
        nextY->addLast(yi);
        //Matrix::print(map);
        mark(xi, yi, map, step, step);
        int biggestStep=step;
        //Object tries every possible path
        for (int i=-1;i<2;i++)
        {
            //Checking for border
            if(xi+i<Matrix::SIZEX && xi+i>-1){
                for(int j=-1;j<2;j++){
                    //Checking for border, checking it's not gonna enter walls or previous marks
                    if (xi+i==xf && yi+j==yf) {
                        map[xf][yf]=step;
                    }
                    if((yi+j<Matrix::SIZEY && yi+j>-1)&&map[xi+i][yi+j]==step){
                        biggestStep=volverBacktrAux(xi+i, yi+j, xf, yf, biggestStep+1, done);
                        if(*done){
                            //Unmarks all marks made by this step because of success
                            //mark(xi, yi, map, 0, step);
                            //Marks the right path with a 2
                            //map[xi][yi]=2;
                            return step;
                        }
                    }
                }
            }
        }
        //Unmarks all marks made by this step because it failed
        //mark(xi, yi, map, 0, step);
        nextX->deletePos(pos);
        nextY->deletePos(pos);
        return step;
    }
}


void Espectro::devolverse(){
    //Test Map (1's are walls)
    //Calling backtracking
    this->proceso=Volviendo;
    if(nextY->largo==0){
        bool* done = new bool(false);
        //Note: Steps starts from 3 because 1 and 2 are taken for walls and final path
        volverBacktrAux(x, y, px, py,3, done);
        delete map;
        this->map=Matrix::generateMatrix1();
        nextX->deletePos(0);
        nextY->deletePos(0);
        lx=x;
        ly=y;
    }
    for(int i=0;i<nextX->largo;i++){
        map[nextX->getNodoPos(i)->getValue()][nextY->getNodoPos(i)->getValue()]=(2+i);
    }
    Matrix::print(map);
    for(int i=0;i<nextX->largo;i++){
        map[nextX->getNodoPos(i)->getValue()][nextY->getNodoPos(i)->getValue()]=0;
    }
    //The results on the map are asigned to the espectro
}

void Espectro::setX(int x){
    this->x=x;
}

void Espectro::setY(int y){
    this->y=y;
}

int Espectro::getX(){
    return x;
}

int Espectro::getY(){
    return y;
}

void Espectro::patrullar(){
    for (int i = -1; i < 2; i++) {
        if (x + i < Matrix::SIZEX && x + i > -1) {
            for (int j = -1; j < 2; j++) {
                if (y + j < Matrix::SIZEY && y + j > -1) {
                    bool condition;
                    if(x!=lx || y!=ly){
                        condition =(lx!=x+i ||ly!=y+j);
                    }else{
                        condition =(llx!=x+i ||lly!=y+j);
                    }
                    if(mapPatrullaje[x][y]!=espectro+1){
                        x=lx;
                        y=ly;
                    }
                    if (mapPatrullaje[x + i][y + j] == (espectro+1) && condition && (j!=0||i!=0)) {
                        if(lx!=llx || ly!=lly){
                            if(x!=lx || y!=ly){
                                llx=lx;
                                lly=ly;
                            }
                        }

                        lx=x;
                        ly=y;

                        x=x+i;
                        y=y+j;

                        return;
                    }
                }
            }
        }
    }
}


void Espectro::mover() {
    if(proceso==Normal) {
        patrullar();
    }else if( nextX->largo>0) {
        if(proceso==Volviendo){
            if(lx!=x||ly!=y ||(x == nextX->getFirst()->getValue() && y == nextY->getFirst()->getValue())) {
                nextX->deletePos(0);
                nextY->deletePos(0);
            }
            lx=x;
            ly=y;
        }
        if(nextX->largo>0){
            x = nextX->getFirst()->getValue();
            y = nextY->getFirst()->getValue();
        } else{
            proceso=Normal;
            lx=px;
            ly=py;
            llx=px;
            lly=py;
        }
    } else if(proceso == Volviendo){
        proceso=Normal;
        lx=px;
        ly=py;
        llx=px;
        lly=py;
    }
}

void Espectro::nextStep() {
    switch (proceso) {
        case Normal:
            break;
        case Volviendo:
            if(x==px && y==py){
                proceso=Normal;
                lx=px;
                ly=py;
                llx=px;
                lly=py;
            }else{
                devolverse();
            }
            break;
        case PersiguiendoA:
            this->perseguirA();
            break;
        case PersiguiendoBread:
            this->perseguirBread();
            break;
    }
    mover();
}

Proceso Espectro::getProceso()  {
    return proceso;
}

int Espectro::getVision()  {
    return vision;
}

ColorEspectro Espectro::getColor() const {
    return color;
}

void EspectroAzul::habilidad(int x, int y) {
    this->x=x;
    this->y=y;
}

Espectro::Espectro(ColorEspectro color, int velocidadRuta, int velocidadPersecusion, int vision
                ,int x, int y, int numEspectro, int** map, int** mapPatrullaje) {
    proceso=Normal;
    this->color=color;
    this->velocidadRuta=velocidadRuta;
    this->velocidadPersecusion=velocidadPersecusion;
    this->vision=vision;
    this->x=x;
    this->y=y;
    this->map=map;
    this->mapPatrullaje=mapPatrullaje;
    espectro=numEspectro;
    nextX=new TList<int>;
    nextY=new TList<int>;
}

int Espectro::getEspectro() const {
    return espectro;
}

bool Espectro::isVivo() const {
    return vivo;
}

void Espectro::setVivo(bool vivo) {
    Espectro::vivo = vivo;
}

void Espectro::habilidad(int x, int y) {

}

void Espectro::setProceso(Proceso proceso) {
    if(proceso==Volviendo){
        nextX=new TList<int>;
        nextY=new TList<int>;
    }
    Espectro::proceso = proceso;
}

void Espectro::setVistox(int vistox) {
    Espectro::vistox = vistox;
}

void Espectro::setVistoy(int vistoy) {
    Espectro::vistoy = vistoy;
}

int Espectro::getVelocidadRuta() const {
    return velocidadRuta;
}

int Espectro::getVelocidadPersecusion() const {
    return velocidadPersecusion;
}

EspectroGris::EspectroGris(int velocidadRuta, int velocidadPersecusion,
        int vision, int x, int y, int numEspectro, int** map, int** mapPatrullaje)
        : Espectro(Gris, velocidadRuta, velocidadPersecusion, vision, x, y, numEspectro, map, mapPatrullaje) {
    px=x;
    py=y;
    lx=x;
    ly=y;
    llx=x;
    lly=y;
}

EspectroRojo::EspectroRojo(int velocidadRuta, int velocidadPersecusion,
                           int vision, int x, int y, int numEspectro, int** map, int** mapPatrullaje)
        : Espectro(Rojo, velocidadRuta, velocidadPersecusion, vision, x, y, numEspectro, map, mapPatrullaje) {
    px=x;
    py=y;
    lx=x;
    ly=y;
    llx=x;
    lly=y;
}
EspectroAzul::EspectroAzul(int velocidadRuta, int velocidadPersecusion,
                           int vision, int x, int y, int numEspectro, int** map, int** mapPatrullaje)
        : Espectro(Azul, velocidadRuta, velocidadPersecusion, vision, x, y, numEspectro, map, mapPatrullaje) {

    px=x;
    py=y;
    lx=x;
    ly=y;
    llx=x;
    lly=y;
}
