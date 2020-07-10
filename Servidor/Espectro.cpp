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



bool Espectro::checkearVision() const{
    Jugador j=*Jugador::getJugador();
    return sqrt(pow(x - j.getX(), 2) + pow(y - j.getY(), 2)) < vision;
}

double f(int xi, int yi, int xf, int yf, float currentSteps){
    return currentSteps+sqrt(pow(xf-xi,2) +pow(yf-yi,2));
}

void Espectro::A(int xi, int yi, int xf, int yf){
    double min =std::numeric_limits<double>::max();
    double minTemp;


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

        //Si es el penultimo nodo entonces se termina el programa y se actualiza el mapa con el path
        if(abs(xmin-xf)<2 &&abs(ymin-yf)<2){
            string path= paths.getNodoPos(parentPos)->getValue()+";";
            while (!path.empty()){
                indexPos=path.find_first_of(';');
                xtemp=std::stoi(path.substr(0,indexPos));
                nextX.addLast(xtemp);

                path=path.substr(indexPos+1, path.length()-indexPos);
                indexPos=path.find_first_of(';');
                ytemp=std::stoi(path.substr(0,indexPos));
                nextY.addLast(ytemp);

                path=path.substr(indexPos+1, path.length()-indexPos);

                map[xtemp][ytemp]= 2;
            }

        } else{
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
    nextX=*new TList<int>;
    nextY=*new TList<int>;

    A(x, y, Jugador::getJugador()->getX(), Jugador::getJugador()->getY());
}

void Espectro::breadcumbing(int xi, int yi){
    int nextTrace=std::numeric_limits<int>::max();
    int nx;
    int ny;
    if(map[xi][yi]!=0){
        for (int i=-1;i<2;i++){
            if(xi+i<Matrix::SIZEX && xi+i>-1){
                for(int j=-1;j<2;j++){
                    if(yi+j<Matrix::SIZEY && yi+j>-1 ){
                        if(map[xi+i][yi+j]<nextTrace){
                            nextTrace=map[xi+i][yi+j];
                            nx=xi+i;
                            ny=yi+j;
                            nextX.addLast(nx);
                            nextY.addLast(ny);
                        }
                    }
                }
            }
        }
        //Move or something
        breadcumbing( nx, ny);
    }
}

void Espectro::perseguirBread() {
    //A* hasta ultimo trazo
    this->proceso=PersiguiendoBread;
    nextX=*new TList<int>;
    nextY=*new TList<int>;
    breadcumbing(x, y);
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
void Espectro::volverBacktrAux(int xi, int yi, int xf, int yf, int step, bool* done)
{
    //If object is on goal, exists
    if (xi==xf && yi==yf) {
        *done = true;
        map[xi][yi]=2;
        return;
    } else if(map[xi][yi]==1){
        return;
    }else{
        //The possible steps from here are marked so that they won't be
        //reached by future calls
        nextX.addLast(xi);
        nextY.addLast(yi);
        mark(xi, yi, map, step, step);
        //Object tries every possible path
        for (int i=-1;i<2;i++)
        {
            //Checking for border
            if(xi+i<Matrix::SIZEX && xi+i>-1){
                for(int j=-1;j<2;j++){
                    //Checking for border, checking it's not gonna enter walls or previous marks
                    if((yi+j<Matrix::SIZEY && yi+j>-1)&&map[xi+i][yi+j]==step){
                        volverBacktrAux(xi+i, yi+j, xf, yf, step+1, done);
                        if(*done){
                            //Unmarks all marks made by this step because of success
                            mark(xi, yi, map, 0, step);
                            nextX.deletePos(nextX.largo-1);
                            nextY.deletePos(nextY.largo-1);
                            //Marks the right path with a 2
                            map[xi][yi]=2;
                            return;
                        }
                    }
                }
            }
        }
        //Unmarks all marks made by this step because it failed
        mark(xi, yi, map, 0, step);
    }
}


void Espectro::devolverse(){
    //Test Map (1's are walls)
    //Calling backtracking
    this->proceso=Volviendo;
    nextX=*new TList<int>;
    nextY=*new TList<int>;
    bool* done = new bool(false) ;
    //Note: Steps starts from 3 because 1 and 2 are taken for walls and final path
    volverBacktrAux(x, y, 4, 6,3, done);
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
    int lx;
    int ly;
    for (int i = -1; i < 2; i++) {
        if (x + i < Matrix::SIZEX && x + i > -1) {
            for (int j = -1; j < 2; j++) {
                if (y + j < Matrix::SIZEY && y + j > -1) {
                    if (map[x + i][y + j] == espectro && (lx!=(x + i) || ly!=(y + j)) ) {
                        lx=x;
                        ly=y;
                        x += i;
                        y += j;
                    }
                }
            }
        }
    }
}


void Espectro::morir() {
    this->setVivo(false);
}

void Espectro::mover() {
    if(proceso==Normal){
        patrullar();
    }else if( nextX.largo>0) {
        x = nextX.getFirst()->getValue();
        nextX.deletePos(0);
        x = nextY.getFirst()->getValue();
        nextY.deletePos(0);
    }else{
        if(proceso==Volviendo){
            proceso=Normal;
        }
    }
}

void Espectro::nextStep() {
    bool found = false;

    switch (proceso) {
        case Normal:
            found = checkearVision();
            break;
        case Volviendo:
            found = checkearVision();
            break;
        case PersiguiendoA:
            this->perseguirA();
            break;
        case PersiguiendoBread:
            this->perseguirBread();
            break;
    }

    if(found){
        nextX=*new TList<int>;
        nextY=*new TList<int>;
        this->perseguirA();
    }else{
        mover();
    }
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
                ,int x, int y, int numEspectro, int** map) {
    proceso=Normal;
    this->color=color;
    this->velocidadRuta=velocidadRuta;
    this->velocidadPersecusion=velocidadPersecusion;
    this->vision=vision;
    this->x=x;
    this->y=y;
    vistax=0;
    vistay=1;
    this->map=map;
    espectro=numEspectro;
    nextX=*new TList<int>;
    nextY=*new TList<int>;
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

EspectroGris::EspectroGris(int velocidadRuta, int velocidadPersecusion,
        int vision, int x, int y, int numEspectro, int** map)
        : Espectro(Gris, velocidadRuta, velocidadPersecusion, vision, x, y, numEspectro, map) {}

EspectroRojo::EspectroRojo(int velocidadRuta, int velocidadPersecusion,
                           int vision, int x, int y, int numEspectro, int** map)
        : Espectro(Rojo, velocidadRuta, velocidadPersecusion, vision, x, y, numEspectro, map) {}
EspectroAzul::EspectroAzul(int velocidadRuta, int velocidadPersecusion,
                           int vision, int x, int y, int numEspectro, int** map)
        : Espectro(Azul, velocidadRuta, velocidadPersecusion, vision, x, y, numEspectro, map) {}
