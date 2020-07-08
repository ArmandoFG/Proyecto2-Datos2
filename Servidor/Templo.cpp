//
// Created by brayan on 4/7/20.
//

#include "Templo.h"

void Templo::startCiclo(){
    Nivel lvl=getNivel();
    Espectro e;
    persiguiendo=false;
    //Falta recibir cuales espectros ya llegaron, para continuar

    for(int i=0; i<ojos.largo;i++){
        Ojo ojo =ojos.getNodoPos(i)->getValue();
        if(ojo.checkearVision()){
            persiguiendo= true;
            for(int i=0; i<espectros.largo;i++){
                e=espectros.getNodoPos(i)->getValue();
                if(e.getColor()==Azul){
                    e.setX(ojo.GetPosX());
                    e.setY(ojo.GetPosY());
                }
            }
            //Hacer sonido
        }
    }

    for(int i=0; i<espectros.largo;i++){
        //Si jugador en zona segura, volver
        e=espectros.getNodoPos(i)->getValue();
        if(e.getProceso()==PersiguiendoBread){
            persiguiendo=true;
        }

        if(persiguiendo){
            if(e.getProceso()!=PersiguiendoBread && e.getProceso()!=PersiguiendoA){
                e.perseguirA(lvl.getMap());
            }
            if(e.getProceso()!=PersiguiendoBread && e.getColor()==Rojo){
                Fuego* f=e.habilidad();
                if(f== nullptr){
                    fuegos.addLast(f);
                }
            }
        }
        if(e.getVida()>0 && !ratonCerca(e.getX(),e.getY(),e.getVision())){
            e.nextStep(lvl.getMap());
        }
    }
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
