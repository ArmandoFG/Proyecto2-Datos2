//
// Created by brayan on 4/7/20.
//

#ifndef UNTITLED_NIVEL_H
#define UNTITLED_NIVEL_H

#include "TList.h"
#include "Espectro.h"

using namespace std;

class Nivel {
    protected:
        int nivel;
    //Objetos list
    //Trampas list
    //Enemigos list
        TList<Espectro> espectros;
    public:
        virtual int* getMap();
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
        Nivel1(){

        }
        int* getMap() override;
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
    Nivel2(){

    }
    int* getMap() override;
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
    Nivel3(){
        Espectro* e= EspectroFactory::Get(Gris);
    }
    int* getMap() override;
};

#endif //UNTITLED_NIVEL_H
