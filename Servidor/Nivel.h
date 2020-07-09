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
        Nivel();
    public:
        TList<Raton> getRatones();
        TList<Ojo> getOjos();
        TList<Chuchu> getChuchus();
        TList<Espectro> getEspectros();
        virtual int** getMap();
};

class Nivel1: public Nivel {
    private:
        int const map[10][10]={{0,0,1,0,0,0,0,0,1,0},
                               {0,0,1,0,0,0,0,0,1,0},
                               {0,0,1,0,0,0,0,0,1,0},
                               {0,0,1,0,0,1,1,1,1,0},
                               {0,0,1,0,1,1,0,0,0,0},
                               {0,0,1,0,0,1,1,0,0,0},
                               {0,0,1,0,0,0,1,0,0,0},
                               {0,0,1,0,1,0,1,0,0,0},
                               {0,0,1,0,1,0,0,0,0,0},
                               {0,0,1,1,1,1,1,0,0,0}};
    public:
        Nivel1();
        int** getMap() override;
};

class Nivel2: public Nivel {
private:
    int const map[10][10]={{0,0,1,0,0,0,0,0,1,0},
                           {0,0,1,0,0,0,0,0,1,0},
                           {0,0,1,0,0,0,0,0,1,0},
                           {0,0,1,0,0,1,1,1,1,0},
                           {0,0,1,0,1,1,0,0,0,0},
                           {0,0,1,0,0,1,1,0,0,0},
                           {0,0,1,0,0,0,1,0,0,0},
                           {0,0,1,0,1,0,1,0,0,0},
                           {0,0,1,0,1,0,0,0,0,0},
                           {0,0,1,1,1,1,1,0,0,0}};
public:
    Nivel2();
    int** getMap() override;
};

class Nivel3: public Nivel {

private:
    int const map[10][10]={{0,0,1,0,0,0,0,0,1,0},
                           {0,0,1,0,0,0,0,0,1,0},
                           {0,0,1,0,0,0,0,0,1,0},
                           {0,0,1,0,0,1,1,1,1,0},
                           {0,0,1,0,1,1,0,0,0,0},
                           {0,0,1,0,0,1,1,0,0,0},
                           {0,0,1,0,0,0,1,0,0,0},
                           {0,0,1,0,1,0,1,0,0,0},
                           {0,0,1,0,1,0,0,0,0,0},
                           {0,0,1,1,1,1,1,0,0,0}};
public:
    Nivel3();
    int** getMap() override;
};


class Nivel4: public Nivel {

private:
    int const map[10][10]={{0,0,1,0,0,0,0,0,1,0},
                           {0,0,1,0,0,0,0,0,1,0},
                           {0,0,1,0,0,0,0,0,1,0},
                           {0,0,1,0,0,1,1,1,1,0},
                           {0,0,1,0,1,1,0,0,0,0},
                           {0,0,1,0,0,1,1,0,0,0},
                           {0,0,1,0,0,0,1,0,0,0},
                           {0,0,1,0,1,0,1,0,0,0},
                           {0,0,1,0,1,0,0,0,0,0},
                           {0,0,1,1,1,1,1,0,0,0}};
public:
    Nivel4();
    int** getMap() override;
};

class Nivel5: public Nivel {
private:
    int const map[10][10]={{0,0,1,0,0,0,0,0,1,0},
                           {0,0,1,0,0,0,0,0,1,0},
                           {0,0,1,0,0,0,0,0,1,0},
                           {0,0,1,0,0,1,1,1,1,0},
                           {0,0,1,0,1,1,0,0,0,0},
                           {0,0,1,0,0,1,1,0,0,0},
                           {0,0,1,0,0,0,1,0,0,0},
                           {0,0,1,0,1,0,1,0,0,0},
                           {0,0,1,0,1,0,0,0,0,0},
                           {0,0,1,1,1,1,1,0,0,0}};
public:
    Nivel5();
    int** getMap() override;
};

#endif //UNTITLED_NIVEL_H
