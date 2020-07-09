//
// Created by brayan on 4/7/20.
//

#ifndef UNTITLED_TEMPLO_H
#define UNTITLED_TEMPLO_H


#include "Nivel.h"
#include "Jugador.h"

class Templo {
    private:
        Nivel nivel1;
        Nivel nivel2;
        Nivel nivel3;
        Nivel nivel4;
        Nivel nivel5;

        int nivel;
        bool persiguiendo;
        Jugador jugador;
        TList<Raton> ratones;
        TList<Ojo> ojos;
        TList<Chuchu> chuchus;
        TList<Espectro> espectros;
        TList<Fuego*> fuegos;

        Nivel getNivel();
        bool ratonCerca(int x, int y, int vision);

    void nextNivel();

    Nivel restartNivel();

    void startCiclo();
};


#endif //UNTITLED_TEMPLO_H
