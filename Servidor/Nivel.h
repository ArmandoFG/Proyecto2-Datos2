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
#include "Jarron.h"
#include "Cofre.h"

using namespace std;

class Nivel {
    protected:
        TList<Jarron> jarrones;
        TList<Cofre> cofres;
        TList<Raton> ratones;
        TList<Ojo> ojos;
        TList<Chuchu> chuchus;
        TList<Espectro> espectros;
        Nivel();
    public:
        TList<Jarron> getJarrones();
        TList<Cofre> getCofres();
        TList<Raton> getRatones();
        TList<Ojo> getOjos();
        TList<Chuchu> getChuchus();
        TList<Espectro> getEspectros();
        virtual int** getMap();
};

class Nivel1: Nivel {
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

class Nivel2: Nivel {
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

class Nivel3: Nivel {

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


class Nivel4: Nivel {

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

class Nivel5: Nivel {
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
