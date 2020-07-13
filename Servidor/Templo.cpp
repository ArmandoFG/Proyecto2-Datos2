//
// Created by brayan on 4/7/20.
//

#include "Templo.h"
#include "Operaciones_Json.h"
#include "Matrix.h"
#include "iostream"
#include "string"
using namespace std;
int getPos(string name){
    if(name.compare("Player")==0){
        return 0;
    }else if(name.compare("01")==0){
        return 1;
    }else if(name.compare("02")==0){
        return 2;
    }else if(name.compare("03")==0){
        return 3;
    }else if(name.compare("Ojo1")==0){
        return 4;
    }else if(name.compare("Ojo2")==0){
        return 5;
    }else if(name.compare("Ojo3")==0){
        return 6;
    }else if(name.compare("Rata1")==0){
        return 7;
    }else if(name.compare("Rata2")==0){
        return 8;
    }else if(name.compare("Chuchu")==0){
        return 9;
    }else if(name.compare("21")==0){
        return 10;
    }else if(name.compare("22")==0){
        return 11;
    }else if(name.compare("23")==0){
        return 12;
    }else if(name.compare("11")==0){
        return 13;
    }else if(name.compare("11")==0){
        return 14;
    }else if(name.compare("11")==0){
        return 15;
    }else if(name.compare("EnemigoFinal")==0){
        return 16;
    }else if(name.compare("Nivel")==0){
        return 17;
    }
}

void Templo::startCiclo(){
    Nivel lvl=getNivel();
    auto* op=new Operaciones_Json;
    cout<<op->read(getPos("Nivel"), "level").substr(6)<<endl;
    if(nivel!=stoi(op->read(getPos("Nivel"), "level").substr(6))){
        this->nextNivel();
        nivel++;
        lvl= this->getNivel();
    }

    this->setPersonajes();

    Jugador j=*Jugador::getJugador();
    j.setvida(stoi(op->read(getPos("Nivel"), "vidas")));
    j.setmarcador(stoi(op->read(getPos("Nivel"), "puntos")));
    float x=stof(op->read(getPos("Player"), "posx"));
    float y=stof(op->read( getPos("Player"),"posy"));

    j.ubicacion(Matrix::toMatrixPosition(x,y,this->nivel, lvl.getMap()));

    if(j.getVida()==0){
        lvl=restartNivel();
        j.setvida(5);
        j.setmarcador(0);}
    for(int i=0; i<chuchus->largo;i++){
        Chuchu* c =chuchus->getNodoPos(i)->getValue();
        c->setVivo(op->read(getPos("Chuchu"), "vivo")=="true");
        if(c->isVivo()){
            std::pair<int, int> ubicacion = Matrix::toMatrixPosition(
                    stof(op->read(getPos("Chuchu"),
                                  "posx")),
                    stof(op->read(getPos("Chuchu"),
                                  "posy")),
                                    nivel, lvl.getMap());
            c->setPos(ubicacion.first,ubicacion.second);
            c->movimiento();
            std::pair<float,float> point = Matrix::toPoint(c->GetPosX(), c->GetPosY(), nivel);
            op->WRITE(getPos("Chuchu"),"posx", to_string(point.first));
            op->WRITE(getPos("Chuchu"),"posy", to_string(point.second));
        }
    }
    /**
     * NOta: podria no ser necesario
    for(int i=0; i<espectros->largo;i++) {
        op->WRITE("espectro"+to_string(espectros->getNodoPos(i)->getValue().getEspectro())
                , "teletransporte", "false");
    }
     */
    for(int i=0; i<ojos->largo;i++){

        Ojo* ojo =ojos->getNodoPos(i)->getValue();
        string name="ojo"+to_string(ojo->getOjo());
        ojo->setVivo(op->read(getPos("Ojo"+to_string(i+1)), "vivo")=="true");

        if(ojo->isVivo()){
            std::pair<int, int> ubicacion=Matrix::toMatrixPosition(stof(op->read(getPos("Ojo"+to_string(i+1)),"posx"))
                    , stof(op->read(getPos("Ojo"+to_string(i+1)),"posy"))
                    ,this->nivel, lvl.getMap());
           ojo->setPos(ubicacion.first, ubicacion.second);
            if(ojo->checkearVision()){
                persiguiendo= true;

               /**  Nota: Esto podria no ser necesario porque ta esta resuelto del lado del client
                    for(int m=0; m<espectros->largo;m++){
                    e=espectros->getNodoPos(m)->getValue();
                    if(e->getColor()==Azul){
                        e->setX(ojo.GetPosX());
                        e->setY(ojo.GetPosY());
                        op->WRITE("espectro"+to_string(e->getEspectro()), "teletransporte", "true");
                    }
                }*/
            }
        }
    }

    if(op->read(getPos("Nivel"), "personaje_zona_segura")=="true"){
        persiguiendo=false;
    }

    for(int i=0; i<espectros->largo;i++){
        Espectro* e = espectros->getNodoPos(i)->getValue();
        e->setVivo(op->read(getPos(to_string(e->getColor())+to_string(i+1)), "vivo")=="true");
        if(e->isVivo()){
        //Quitar el !!!
            std::pair<int, int> posicionReal= Matrix::toMatrixPosition(stof(op->read(getPos(to_string(e->getColor())+to_string(i+1)), "posx")),
                    stof(op->read(getPos(to_string(e->getColor())+to_string(i+1)), "posy")), nivel, lvl.getMap());
            e->setX(posicionReal.first);
            e->setY(posicionReal.second);

            if (persiguiendo) {
                if (e->getProceso() != PersiguiendoBread && e->getProceso() != PersiguiendoA) {
                    e->perseguirA();
                }
            } else{
                if(e->getProceso() == PersiguiendoBread || e->getProceso() == PersiguiendoA){
                    e->devolverse();
                }
            }

            if(!ratonCerca(e->getX(),e->getY(), e->getVision())){
                e->nextStep();
            }

            std::pair<float,float> point = Matrix::toPoint(e->getX(), e->getY(), nivel);
            op->WRITE(getPos(to_string(e->getColor())+to_string(i+1)), "posx",
                    to_string(point.first));
            op->WRITE(getPos(to_string(e->getColor())+to_string(i+1)), "posy",
                    to_string(point.second));
        }
    }
    for(int i=0; i<ratones->largo;i++){
        Raton* r =ratones->getNodoPos(i)->getValue();
        string name= "raton"+to_string(r->getRaton());
        r->setVivo(op->read(getPos("Rata"+to_string(i+1)),
                "vivo")=="true");

        if(r->isVivo()){
            std::pair<int, int> ubicacion = Matrix::toMatrixPosition(
                    stof(op->read(getPos("Rata"+to_string(i+1)),
                             "posx")),
                    stof(op->read(getPos("Rata"+to_string(i+1)),
                             "posy")),
                    nivel, lvl.getMap());
            r->setPos(ubicacion.first,ubicacion.second);

            //r->movimiento();
            //std::pair<float,float> point = Matrix::toPoint(r->GetPosX(),r->GetPosY(), nivel);
            //op->WRITE("Personajes",chuchus->largo+espectros->largo+ojos->largo,
            //        "posx",to_string(point.first));
            //op->WRITE("Personajes",chuchus->largo+espectros->largo+ojos->largo,
            //        "posy",to_string(point.second));
        }
    }

}

bool Templo::ratonCerca(int x, int y, int vision){
    for(int i=0; i<ratones->largo;i++){
        if(ratones->getNodoPos(i)->getValue()->checkearVision(x, y, vision)){
            return true;
        }
    }
    return false;
}

void Templo::nextNivel(){
    nivel+=1;
}

void Templo::setPersonajes(){
    Nivel lvl =getNivel();
    ratones=lvl.getRatones();
    ojos=lvl.getOjos();
    chuchus=lvl.getChuchus();
    espectros=lvl.getEspectros();
}

Nivel Templo::restartNivel(){
    Nivel* lvl= nullptr;
    Jugador j=*Jugador::getJugador();
    switch (nivel) {
        case 1:
            j.setTracesMap(Matrix::generateMatrix1());
            lvl= new Nivel1;
            nivel1=lvl;
            break;
        case 2:
            j.setTracesMap(Matrix::generateMatrix2());
            lvl= new Nivel2;
            nivel2=lvl;
            break;
        case 3:
            j.setTracesMap(Matrix::generateMatrix3());
            lvl= new Nivel3;
            nivel3=lvl;
            break;
        case 4:
            j.setTracesMap(Matrix::generateMatrix4());
            lvl= new Nivel4;
            nivel4=lvl;
            break;
        case 5:
            j.setTracesMap(Matrix::generateMatrix5());
            lvl= new Nivel5;
            nivel5=lvl;
            break;
    }
    ratones=lvl->getRatones();
    ojos=lvl->getOjos();
    chuchus=lvl->getChuchus();
    espectros=lvl->getEspectros();
    return *lvl;
}

Nivel Templo::getNivel(){
    switch (nivel) {
        case 1:
            Jugador::getJugador()->setTracesMap(Matrix::generateMatrix1());
            return *nivel1;
        case 2:
            Jugador::getJugador()->setTracesMap(Matrix::generateMatrix2());
            return *nivel2;
        case 3:
            Jugador::getJugador()->setTracesMap(Matrix::generateMatrix3());
            return *nivel3;
        case 4:
            Jugador::getJugador()->setTracesMap(Matrix::generateMatrix4());
            return *nivel4;
        case 5:
            Jugador::getJugador()->setTracesMap(Matrix::generateMatrix5());
            return *nivel5;
    }
}

Templo::Templo() {
    nivel=1;
}
