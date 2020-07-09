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
#include "Fuego.h"


enum Proceso{
    Normal, PersiguiendoA, PersiguiendoBread,Volviendo
};

enum ColorEspectro{
    Gris, Azul, Rojo
};

class Espectro {
protected:
    Espectro(ColorEspectro color, int velocidadRuta, int velocidadPersecusion, int vision, int x, int y,
             int numEspectro);

    Proceso proceso;
    ColorEspectro color;
    bool vivo{true};
public:
    bool isVivo() const;

    void setVivo(bool vivo);

protected:
    int velocidadRuta;
    int velocidadPersecusion;
    int vision;
    int x;
    int y;
    int vistax;
    int vistay;
    int espectro;
    TList<int> nextX;
    TList<int> nextY;
public:
    int getEspectro() const;

private:
    void A(int xi, int yi, int xf, int yf, int** map);
    void breadcumbing(int xi, int yi, int** map );
    void volverBacktrAux(int xi, int yi, int xf, int yf, int step, int** map, bool *done);
public:
    Espectro(){};
    ColorEspectro getColor() const;
    int getVision();
    void perseguirBread( int** map);
    void perseguirA( int** map);
    void devolverse( int** map);
    void morir();
    void patrullar(int** map);
    bool checkearVision();
    virtual void habilidad(int x, int y);
    Proceso getProceso() ;

    void setY(int y);
    void setX(int x);
    int getX();
    int getY();
    void nextStep( int** map);
    void mover( int** map);
};


class EspectroGris : public Espectro{
public:
    EspectroGris( int velocidadRuta, int velocidadPersecusion, int vision, int x, int y,
                 int numEspectro);
};

class EspectroRojo : public Espectro{
private:
    int const frecuenciaFuego{1000};
    int timeUntilFuego{0};
public:
    EspectroRojo( int velocidadRuta, int velocidadPersecusion, int vision, int x, int y,
                  int numEspectro);

};

class EspectroAzul : public Espectro{
public:
    EspectroAzul( int velocidadRuta, int velocidadPersecusion, int vision, int x, int y,
                  int numEspectro);
    void habilidad(int x, int y) override;
};


class EspectroFactory
{
public:
    static Espectro *Get(ColorEspectro color, int velocidadRuta, int velocidadPersecusion, int vision, int x, int y,
                         int numEspectro)
    {
        switch (color) {
            case Gris:
                return new EspectroGris( velocidadRuta, velocidadPersecusion, vision, x, y,numEspectro);
            case Azul:
                return  new EspectroAzul( velocidadRuta, velocidadPersecusion, vision, x, y,numEspectro);
            case Rojo:
                return new EspectroRojo( velocidadRuta, velocidadPersecusion, vision, x, y,numEspectro);
        }
    }
};


#endif //UNTITLED_ESPECTRO_H
