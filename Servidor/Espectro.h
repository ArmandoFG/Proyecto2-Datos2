//
// Created by brayan on 3/7/20.
//

#ifndef UNTITLED_ESPECTRO_H
#define UNTITLED_ESPECTRO_H

using namespace std;

#include <z3.h>
#include <map>
#include "string"



class Espectro {
    protected:
        string tipo;
        int velocidadRuta;
        int velocidadPersecusion;
        int vision;
        int x;
        int y;
        int vistax;
        int vistay;
        int espectro;
        int patrullarFlag;
    public:
        virtual ~Espectro() {}
        void perseguirBread(int map[10][10]);
        void perseguirA(int map[10][10]);
        void devolverse(int map[10][10]);
        void recibirGolpe(bool esFrente, int map[10][10]);
        void atacar();
        void morir();
        void iniciar();
        void patrullar(int map[10][10]);
        void checkearVision(int map[10][10]);

        virtual void habilidad();

        void setY(int y);
        void setX(int x);
        int getX();
        int getY();

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
