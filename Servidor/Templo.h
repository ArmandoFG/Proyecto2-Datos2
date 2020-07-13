//
// Created by brayan on 4/7/20.
//

#ifndef UNTITLED_TEMPLO_H
#define UNTITLED_TEMPLO_H


#include "Nivel.h"
#include "Jugador.h"
#include "TList.cpp"
class Templo {
public:
    Templo();

    private:
        Nivel* nivel1{new Nivel1};
        Nivel* nivel2{new Nivel2};
        Nivel* nivel3{new Nivel3};
        Nivel* nivel4{new Nivel4};
        Nivel* nivel5{new Nivel5};

        int nivel;
        bool persiguiendo{false};
        TList<Raton*>* ratones;
        TList<Ojo*>* ojos;
        TList<Chuchu*>* chuchus;
        TList<Espectro*>* espectros;

        Nivel getNivel();
        bool ratonCerca(int x, int y, int vision);

    void nextNivel();

    Nivel restartNivel();

public:
    void startCiclo();

    void setPersonajes();
};


#endif //UNTITLED_TEMPLO_H
