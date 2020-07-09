//
// Created by brayan on 4/7/20.
//

#include "Templo.h"
#include "Operaciones_Json.h"

void Templo::startCiclo(){
    Nivel lvl=getNivel();
    Espectro e;
    auto* op=new Operaciones_Json;
    persiguiendo=false;

    Jugador j=*Jugador::getJugador();
    j.setvida(stoi(op->read("jugador", "vida")));
    j.setmarcador(stoi(op->read("jugador", "marcador")));
    j.setX(stoi(op->read("jugador", "posX")));
    j.setY(stoi(op->read("jugador", "posY")));

    if(j.getVida()==0){
        lvl=restartNivel();
        j.setvida(5);
        j.setmarcador(0);
    }

    op->WRITE("espectro1", "teletransporte", "false");
    op->WRITE("espectro2", "teletransporte", "false");
    op->WRITE("espectro3", "teletransporte", "false");
    op->WRITE("espectro4", "teletransporte", "false");

    for(int i=0; i<ojos.largo;i++){

        Ojo ojo =ojos.getNodoPos(i)->getValue();
        string name="ojo"+to_string(ojo.getOjo());
        ojo.setVivo(op->read(name, "vivo")=="true");

        if(ojo.isVivo()){
            ojo.setPos(stoi(op->read(name,"posX")), stoi(op->read("ojo","posX")));

            if(ojo.checkearVision()){
                persiguiendo= true;

                for(int i=0; i<espectros.largo;i++){
                    e=espectros.getNodoPos(i)->getValue();
                    if(e.getColor()==Azul){
                        e.setX(ojo.GetPosX());
                        e.setY(ojo.GetPosY());
                        op->WRITE(name, "teletransporte", "true");
                    }
                }
            }
        }
    }
    for(int i=0; i<espectros.largo;i++){
        e.setVivo(op->read("espectro"+to_string(e.getEspectro()), "vivo")=="true");
        if(e.isVivo()){

            string completoUltimoPaso=op->read("espectro"+to_string(e.getEspectro()), "completoUltimoPaso");

            if(op->read("jugador", "zonasegura")=="true"){
                persiguiendo=false;
                if(e.getProceso() == PersiguiendoBread || e.getProceso() == PersiguiendoA){
                    e.devolverse(lvl.getMap());
                }
            }

            e = espectros.getNodoPos(i)->getValue();
            if (e.getProceso() == PersiguiendoBread) {
                persiguiendo = true;
            }

            if (persiguiendo) {
                if (e.getProceso() != PersiguiendoBread && e.getProceso() != PersiguiendoA) {
                    e.perseguirA(lvl.getMap());
                }
            }

            if(ratonCerca(e.getX(),e.getY(), e.getVision())){
                op->WRITE("espectro" + to_string(e.getEspectro()), "estado", "paralizado");
            }else if(completoUltimoPaso=="true"){
                op->WRITE("espectro" + to_string(e.getEspectro()), "estado", to_string(e.getProceso()));
                e.nextStep(lvl.getMap());
            }
            op->WRITE("espectro" + to_string(e.getEspectro()), "posX", to_string(e.getX()));
            op->WRITE("espectro" + to_string(e.getEspectro()), "posY", to_string(e.getY()));
        }
    }
    for(int i=0; i<ratones.largo;i++){
        Raton r =ratones.getNodoPos(i)->getValue();
        string name= "raton"+to_string(r.getRaton());
        r.setVivo(op->read(name,"vivo")=="true");

        if(r.isVivo()){
            r.movimiento();
            op->WRITE(name,"posX",to_string(r.GetPosX()));
            op->WRITE(name,"posY",to_string(r.GetPosY()));
        }
    }
    for(int i=0; i<chuchus.largo;i++){
        Chuchu c =chuchus.getNodoPos(i)->getValue();
        string name= "chuchu"+to_string(c.getChuchu());
        c.setVivo(op->read(name, "vivo")=="true");
        if(c.isVivo()){
            c.movimiento();
            op->WRITE(name,"posX", to_string(c.GetPosX()));
            op->WRITE(name,"posY", to_string(c.GetPosY()));
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

Nivel Templo::restartNivel(){
    Nivel* lvl= nullptr;
    switch (nivel) {
        case 1:
            lvl= new Nivel1;
        case 2:
            lvl= new Nivel2;
        case 3:
            lvl= new Nivel3;
        case 4:
            lvl= new Nivel4;
        case 5:
            lvl= new Nivel5;
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
            return nivel1;
        case 2:
            return nivel2;
        case 3:
            return nivel3;
        case 4:
            return nivel4;
        case 5:
            return nivel5;
    }
}
