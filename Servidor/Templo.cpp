//
// Created by brayan on 4/7/20.
//

#include "Templo.h"
#include "Operaciones_Json.h"
#include "Matrix.h"
#include "iostream"
#include "string"
using namespace std;

/**
 * Funcion que indica la posicion del personaje en el json
 * @param name Nombre del personaje
 * @return Posicion en json
 */
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
    }else if(name.compare("11")==0){
        return 10;
    }else if(name.compare("12")==0){
        return 11;
    }else if(name.compare("13")==0){
        return 12;
    }else if(name.compare("21")==0){
        return 13;
    }else if(name.compare("22")==0){
        return 14;
    }else if(name.compare("23")==0){
        return 15;
    }else if(name.compare("31")==0){
        return 16;
    }else if(name.compare("Nivel")==0){
        return 17;
    }
}

/**
 * Funcion que se llama una vez cada nivel
 */
void Templo::startCiclo(){



    Nivel lvl=getNivel();
    auto* op=new Operaciones_Json;

    if(nivel!=stoi(op->read(getPos("Nivel"), "level").substr(6))){
        Jugador::getJugador()->setTraces(new TList<std::pair<int, int>>);
        persiguiendo=false;
        this->restartNivel();
        nivel=stoi(op->read(getPos("Nivel"), "level").substr(6));
        lvl= this->getNivel();
    }

    this->setPersonajes();

    Jugador* j=Jugador::getJugador();
    j->setvida(stoi(op->read(getPos("Nivel"), "vidas")));
    j->setmarcador(stoi(op->read(getPos("Nivel"), "puntos")));
    float x=stof(op->read(getPos("Player"), "posx"));
    float y=stof(op->read( getPos("Player"),"posy"));

    if(j->getVida()==0){
        lvl=restartNivel();
        j->setvida(5);
        j->setmarcador(0);
    }

    j->ubicacion(Matrix::toMatrixPosition(x,y,this->nivel, lvl.getMap()));

    for(int i=0; i<chuchus->largo;i++){
        Chuchu* c =chuchus->getNodoPos(i)->getValue();
        c->setVivo(op->read(getPos("Chuchu"), "vivo")=="true");
        if(c->isVivo()){
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
        op->WRITE(getPos("Ojo"+to_string(i+1)), "tamanoradio",
                  to_string(ojo->getVision()));
        if(ojo->isVivo()){
            std::pair<int, int> ubicacion=Matrix::toMatrixPosition(stof(op->read(getPos("Ojo"+to_string(i+1)),"posx"))
                    , stof(op->read(getPos("Ojo"+to_string(i+1)),"posy"))
                    ,this->nivel, lvl.getMap());
           ojo->setPos(ubicacion.first, ubicacion.second);
            if(ojo->checkearVision()){
                persiguiendo= true;
                    for(int m=0; m<espectros->largo;m++){
                        Espectro* e=espectros->getNodoPos(m)->getValue();
                        if(e->getColor()==Azul){
                            e->setX(ojo->GetPosX());
                            e->setY(ojo->GetPosY());
                            std::pair<float,float> point = Matrix::toPoint(e->getX(), e->getY(), nivel);
                            op->WRITE(getPos(to_string(e->getColor())+to_string(i+1)), "posx",
                                      to_string(point.first));
                            op->WRITE(getPos(to_string(e->getColor())+to_string(i+1)), "posy",
                                      to_string(point.second));
                        }
                }
            }
        }
    }

    if(op->read(getPos("Nivel"), "personaje_zona_segura")=="true"){
        persiguiendo=false;
    }else{
        for(int i=0; i<espectros->largo;i++){
            Espectro* e = espectros->getNodoPos(i)->getValue();
            if(op->read(getPos(to_string(e->getColor())+to_string(i+1)), "radiovision")=="true"
            && !persiguiendo && e->isVivo()){
            //&& e->checkearVision() ){
                persiguiendo=true;
                e->setProceso(PersiguiendoBread);
                e->setVistox(Jugador::getJugador()->getX());
                e->setVistoy(Jugador::getJugador()->getY());
                e->visited=-1;
                break;
            }
        }
    }
    for(int i=0; i<espectros->largo;i++){
        Espectro* e = espectros->getNodoPos(i)->getValue();
        e->setVivo(op->read(getPos(to_string(e->getColor())+to_string(i+1)), "vivo")=="true");
        if(e->isVivo()){
            std::pair<int, int> posicionReal= Matrix::toMatrixPosition(stof(op->read(getPos(to_string(e->getColor())+to_string(i+1)), "posx")),
                    stof(op->read(getPos(to_string(e->getColor())+to_string(i+1)), "posy")), nivel, lvl.getMap());
            e->setX(posicionReal.first);
            e->setY(posicionReal.second);

            if (persiguiendo) {
                if (e->getProceso() != PersiguiendoBread && e->getProceso() != PersiguiendoA) {
                    e->setProceso(PersiguiendoA);
                }
                op->WRITE(getPos(to_string(e->getColor())+to_string(i+1)), "velocidad",
                          to_string(e->getVelocidadPersecusion()));
            } else{
                if(e->getProceso() == PersiguiendoBread || e->getProceso() == PersiguiendoA){
                    e->setProceso(Volviendo);
                }
                op->WRITE(getPos(to_string(e->getColor())+to_string(i+1)), "velocidad",
                          to_string(e->getVelocidadRuta()));
            }

            if(!ratonCerca(e->getX(),e->getY(), e->getVision())) {
                e->nextStep();
            }

            std::pair<float,float> point = Matrix::toPoint(e->getX(), e->getY(), nivel);
            op->WRITE(getPos(to_string(e->getColor())+to_string(i+1)), "posx",
                    to_string(point.first));
            op->WRITE(getPos(to_string(e->getColor())+to_string(i+1)), "posy",
                    to_string(point.second));
            op->WRITE(getPos(to_string(e->getColor())+to_string(i+1)), "tamanoradio",
                      to_string(e->getVision()));
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
            r->movimiento(lvl.getMap());
            std::pair<float,float> point = Matrix::toPoint(r->GetPosX(),r->GetPosY(), nivel);
            op->WRITE(getPos("Rata"+to_string(i+1)),
                    "posx",to_string(point.first));
            op->WRITE(getPos("Rata"+to_string(i+1)),
                    "posy",to_string(point.second));
        }
    }

    for(int i=0; i<ojos->largo;i++){
        Ojo* ojo =ojos->getNodoPos(i)->getValue();
        if(ojo->isVivo()){
            if(ojo->checkearVision() ){
                for(int m=0; m<espectros->largo;m++){
                    Espectro* e=espectros->getNodoPos(m)->getValue();
                    if(e->getColor()==Azul){
                        op->WRITE(getPos(to_string(e->getColor())+to_string(i+1)), "velocidad", "10000000000000");
                    }
                }
            }
        }
    }

}


/**
 * Devuelve true si hay un raton cerca al espector
 * @param x X del expectro
 * @param y Y del espectro
 * @param vision Vision del espectro
 * @return True si esta cerca
 */
bool Templo::ratonCerca(int x, int y, int vision){
    for(int i=0; i<ratones->largo;i++){
        if(ratones->getNodoPos(i)->getValue()->checkearVision(x, y, vision)){
           return true;
        }
    }
    return false;
}

/**
 * @brief Cambia los personajes del nivel
 * 
 */

void Templo::setPersonajes(){
    Nivel lvl =getNivel();
    ratones=lvl.getRatones();
    ojos=lvl.getOjos();
    chuchus=lvl.getChuchus();
    espectros=lvl.getEspectros();
}

/**
 * @brief Reinicia nivel del juego
 * 
 * @return Nivel 
 */

Nivel Templo::restartNivel(){
    Nivel* lvl= nullptr;
    Jugador* j=Jugador::getJugador();
    switch (nivel) {
        case 1:
            lvl= new Nivel1;
            nivel1=lvl;
            break;
        case 2:
            lvl= new Nivel2;
            nivel2=lvl;
            break;
        case 3:
            lvl= new Nivel3;
            nivel3=lvl;
            break;
        case 4:
            lvl= new Nivel4;
            nivel4=lvl;
            break;
        case 5:
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

/**
 * @brief Obtiene los niveles del juego
 * 
 * @return Nivel 
 */

Nivel Templo::getNivel(){
    switch (nivel) {
        case 1:
            return *nivel1;
        case 2:
            return *nivel2;
        case 3:
            return *nivel3;
        case 4:
            return *nivel4;
        case 5:
            return *nivel5;
    }
}

/**
 * @brief Construct a new Templo:: Templo object
 * 
 */

Templo::Templo() {
    nivel=1;
    persiguiendo= false;
}
