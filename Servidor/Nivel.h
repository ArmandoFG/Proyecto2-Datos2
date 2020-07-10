//
// Created by brayan on 4/7/20.
//

#ifndef UNTITLED_NIVEL_H
#define UNTITLED_NIVEL_H

#include "TList.h"
#include "Espectro.h"
#include "Chuchu.h"
#include "Ojo.h"
#include "Raton.h"

using namespace std;

class Nivel {
    protected:
        TList<Raton> ratones;
        TList<Ojo> ojos;
        TList<Chuchu> chuchus;
        TList<Espectro> espectros;
        int** map;
        int** mapPatrullaje;
        Nivel();
    public:
        TList<Raton> getRatones();
        TList<Ojo> getOjos();
        TList<Chuchu> getChuchus();
        TList<Espectro> getEspectros();
        int** getMap();
};

class Nivel1: public Nivel {
public:
    Nivel1();
};

class Nivel2: public Nivel {
public:
    Nivel2();
};

class Nivel3: public Nivel {
public:
    Nivel3();
};


class Nivel4: public Nivel {
public:
    Nivel4();
};

class Nivel5: public Nivel {
public:
    Nivel5();
};

#endif //UNTITLED_NIVEL_H
