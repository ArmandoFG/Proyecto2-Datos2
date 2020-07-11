//
// Created by brayan on 4/7/20.
//

#include "Templo.h"
#include "Operaciones_Json.h"
#include "Matrix.h"

void Templo::startCiclo(){
    Nivel lvl=getNivel();
    Espectro e;
    auto* op=new Operaciones_Json;
    persiguiendo=false;


    if(nivel!=stoi(op->read("juego",0, "nivel"))){
        this->nextNivel();
        nivel++;
        lvl= this->getNivel();
    }

    Jugador j=*Jugador::getJugador();
    j.setvida(stoi(op->read("juego",0, "vida")));
    j.setmarcador(stoi(op->read("juego",0, "puntos")));
    float x=stof(op->read("jugador",chuchus.largo+espectros.largo-1, "posx"));
    float y=stof(op->read("jugador", chuchus.largo+espectros.largo-1,"posy"));

    j.ubicacion(Matrix::toMatrixPosition(x,y,this->nivel));

    if(j.getVida()==0){
        lvl=restartNivel();
        j.setvida(5);
        j.setmarcador(0);}
    for(int i=0; i<chuchus.largo;i++){
        Chuchu c =chuchus.getNodoPos(i)->getValue();
        c.setVivo(op->read("Personajes",c.getChuchu()-1, "vivo")=="true");
        if(c.isVivo()){
            std::pair<int, int> ubicacion = Matrix::toMatrixPosition(
                    stof(op->read("Personajes",c.getChuchu()-1,
                                  "posx")),
                    stof(op->read("Personajes",c.getChuchu()-1,
                                  "posy")),
                    nivel);
            c.setPos(ubicacion.first,ubicacion.second);
            c.movimiento();
            std::pair<float,float> point = Matrix::toPoint(c.GetPosX(), c.GetPosY(), nivel);
            op->WRITE("Personajes",c.getChuchu(),"posx", to_string(point.first));
            op->WRITE("Personajes",c.getChuchu(),"posy", to_string(point.second));
        }
    }
    /**
     * NOta: podria no ser necesario
    for(int i=0; i<espectros.largo;i++) {
        op->WRITE("espectro"+to_string(espectros.getNodoPos(i)->getValue().getEspectro())
                , "teletransporte", "false");
    }
     */
    for(int i=0; i<ojos.largo;i++){

        Ojo ojo =ojos.getNodoPos(i)->getValue();
        string name="ojo"+to_string(ojo.getOjo());
        ojo.setVivo(op->read("Personajes",chuchus.largo+espectros.largo+ojo.getOjo(), "vivo")=="true");

        if(ojo.isVivo()){
            std::pair<int, int> ubicacion=Matrix::toMatrixPosition(stof(op->read("Personajes",chuchus.largo+espectros.largo+ojo.getOjo(),"posx"))
                    , stof(op->read("Personajes",chuchus.largo+espectros.largo+ojo.getOjo(),"posy"))
                    ,this->nivel);
            ojo.setPos(ubicacion.first, ubicacion.second);
            if(ojo.checkearVision()){
                persiguiendo= true;

               /**  Nota: Esto podria no ser necesario porque ta esta resuelto del lado del client
                    for(int m=0; m<espectros.largo;m++){
                    e=espectros.getNodoPos(m)->getValue();
                    if(e.getColor()==Azul){
                        e.setX(ojo.GetPosX());
                        e.setY(ojo.GetPosY());
                        op->WRITE("espectro"+to_string(e.getEspectro()), "teletransporte", "true");
                    }
                }*/
            }
        }
    }
    for(int i=0; i<espectros.largo;i++){
        e.setVivo(op->read("Personajes",chuchus.largo+e.getEspectro()-1, "vivo")=="true");
        if(e.isVivo()){

            std::pair<int, int> posicionReal= Matrix::toMatrixPosition(stof(op->read("Personajes",chuchus.largo+e.getEspectro()-1, "posx")),
                    stof(op->read("Personajes",chuchus.largo+e.getEspectro()-1, "posy")), nivel);
            e.setX(posicionReal.first);
            e.setY(posicionReal.second);

            if(op->read("Personajes",chuchus.largo+espectros.largo, "zonasegura")=="true"){
                persiguiendo=false;
                if(e.getProceso() == PersiguiendoBread || e.getProceso() == PersiguiendoA){
                    e.devolverse();
                }
            }

            e = espectros.getNodoPos(i)->getValue();
            if (e.getProceso() == PersiguiendoBread) {
                persiguiendo = true;
            }

            if (persiguiendo) {
                if (e.getProceso() != PersiguiendoBread && e.getProceso() != PersiguiendoA) {
                    e.perseguirA();
                }
            }

            if(!ratonCerca(e.getX(),e.getY(), e.getVision())){
                e.nextStep();
            }

            std::pair<float,float> point = Matrix::toPoint(e.getX(), e.getY(), nivel);
            op->WRITE("Personajes",chuchus.largo+e.getEspectro()-1, "posx",
                    to_string(point.first));
            op->WRITE("Personajes",chuchus.largo+e.getEspectro()-1, "posy",
                    to_string(point.second));
        }
    }
    for(int i=0; i<ratones.largo;i++){
        Raton r =ratones.getNodoPos(i)->getValue();
        string name= "raton"+to_string(r.getRaton());
        r.setVivo(op->read("Personajes",chuchus.largo+espectros.largo+ojos.largo,
                "vivo")=="true");

        if(r.isVivo()){
            std::pair<int, int> ubicacion = Matrix::toMatrixPosition(
                    stof(op->read("Personajes",chuchus.largo+espectros.largo+ojos.largo,
                             "posx")),
                    stof(op->read("Personajes",chuchus.largo+espectros.largo+ojos.largo,
                             "posy")),
                    nivel);
            r.setPos(ubicacion.first,ubicacion.second);

            //r.movimiento();
            //std::pair<float,float> point = Matrix::toPoint(r.GetPosX(),r.GetPosY(), nivel);
            //op->WRITE("Personajes",chuchus.largo+espectros.largo+ojos.largo,
            //        "posx",to_string(point.first));
            //op->WRITE("Personajes",chuchus.largo+espectros.largo+ojos.largo,
            //        "posy",to_string(point.second));
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
