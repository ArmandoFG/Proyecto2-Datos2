//
// Created by brayan on 3/7/20.
//

#ifndef UNTITLED_ESPECTRO_H
#define UNTITLED_ESPECTRO_H

using namespace std;

#include <z3.h>
#include <map>
#include "string"
#include "TList.h"


enum Proceso{
    Normal, PersiguiendoA, PersiguiendoBread,Volviendo
};

class Espectro {
    protected:
public:
    Proceso getProceso() const;

protected:
    Proceso proceso;
public:
    int getVida() const;

protected:
    string tipo;
        int vida;
        int velocidadRuta;
        int velocidadPersecusion;
        int vision;
public:
    int getVision() const;

protected:
    int x;
        int y;
        int vistax;
        int vistay;
        int espectro;
        int patrullarFlag;
        TList<int> nextX;
        TList<int> nextY;
    private:
        void A(int xi, int yi, int xf, int yf, int map[10][10]);
        void breadcumbing(int xi, int yi, int map[10][10] );
        void volverBacktrAux(int xi, int yi, int xf, int yf, int step,int map[10][10], bool *done);
    public:
        virtual ~Espectro() {}
        void perseguirBread(int map[10][10]);
        void perseguirA(int* map[10][10]);
        void devolverse(int map[10][10]);
        void recibirGolpe(bool esFrente, int map[10][10]);
        void atacar();
        void morir();
        void iniciar();
        void patrullar(int map[10][10]);
        bool checkearVision();

        virtual void habilidad();

        void setY(int y);
        void setX(int x);
        int getX();
        int getY();
        void nextStep(int map[10][10]);
        void breadcumbing(int xi, int yi);
        void mover(int map [10][10]);
};

typedef Espectro* (__stdcall *CreateEspectroFn)(void);


class EspectroGris : public Espectro{
public:
    void habilidad() override;
};

class EspectroRojo : public Espectro{
public:
    void habilidad() override;
};

class EspectroAzul : public Espectro{
public:
    void habilidad() override;
};


enum ColorEspectro{
    Gris, Azul, Rojo
};

class EspectroFactory
{
public:
    static Espectro *Get(ColorEspectro color)
    {
        switch (color) {
            case Gris:
                return new EspectroGris;
            case Azul:
                return  new EspectroAzul;
            case Rojo:
                return new EspectroRojo;
        }
    }
};


#endif //UNTITLED_ESPECTRO_H
