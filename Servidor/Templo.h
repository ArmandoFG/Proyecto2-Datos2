//
// Created by brayan on 4/7/20.
//

#ifndef UNTITLED_TEMPLO_H
#define UNTITLED_TEMPLO_H


#include "Nivel.h"
#include "Jugador.h"

class Templo {
    private:
        Nivel Nivel1;
        Nivel Nivel2;
        Nivel Nivel3;
        int nivel;
        Jugador jugador;
        TList<Raton> ratones;
        TList<Ojo> ojos;
        TList<Chuchu> chuchus;
        TList<Espectro> espectros;
        Nivel getNivel();

    void nextNivel();
};


#endif //UNTITLED_TEMPLO_H
