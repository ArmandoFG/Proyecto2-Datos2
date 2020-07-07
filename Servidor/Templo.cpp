//
// Created by brayan on 4/7/20.
//

#include "Templo.h"

void Templo::startCiclo(){
    Nivel lvl=getNivel();
    Espectro e;
    persiguiendo=false;

    for(int i=0; i<ojos.largo;i++){
        if(ojos.getNodoPos(i)->getValue().checkearVision()){
            persiguiendo= true;
            //Hacer sonido
        }
    }



    for(int i=0; i<espectros.largo;i++){
        e=espectros.getNodoPos(i)->getValue();
        if(e.getProceso()==PersiguiendoBread){
            persiguiendo=true;
        }
    }
    for(int i=0; i<espectros.largo;i++){
        e=espectros.getNodoPos(i)->getValue();
        if(persiguiendo){
            if(e.getProceso()!=PersiguiendoBread){
                e.perseguirA(lvl.getMap());
            }
        }
        if(e.getVida()>0 && !ratonCerca(e.getX(),e.getY(),e.getVision())){
            e.nextStep();
        }
    }
    //Si jugador en zona segura, volver
}

bool Templo::ratonCerca(int x, int y, int vision){
    for(int i=0; i<ratones.largo;i++){
        if(ratones.getNodoPos(i)->getValue().checkearVision(x, y, vision)){
            return true;
        }
    }
    return false;
}

void Templo::nextNivel(){
    nivel+=1;
    Nivel lvl =getNivel();
    ratones=lvl.getRatones();
    ojos=lvl.getOjos();
    chuchus=lvl.getChuchus();
    espectros=lvl.getEspectros();
}

Nivel Templo::getNivel(){
    switch (nivel) {
        case 1:
            return Nivel1;
        case 2:
            return Nivel2;
        case 3:
            return Nivel3;
        case 4:
            return Nivel4;
        case 5:
            return Nivel5;
    }
}
