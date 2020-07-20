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

enum ColorEspectro{
    Gris, Rojo, Azul
};

class Espectro {
protected:
    Espectro(ColorEspectro color, int velocidadRuta, int velocidadPersecusion, int vision, int x, int y,
             int numEspectro, int** map, int** mapPatrullaje);

    Proceso proceso;
    ColorEspectro color;
    bool vivo{true};
    int velocidadRuta;
    int velocidadPersecusion;
    int vision;
    int x;
    int y;
    int px;
    int py;
    int lx;
    int ly;
    int llx;
    int lly;
    int vistox;
    int vistoy;
    int espectro;
public:
    void setVistox(int vistox);

    void setVistoy(int vistoy);

protected:
    int** map;
    int** mapPatrullaje;
    TList<int>* nextX;
    TList<int>* nextY;
private:
    void A(int xi, int yi, int xf, int yf);
    void breadcumbing(int attempt );
    int volverBacktrAux(int xi, int yi, int xf, int yf, int step, bool *done);
    void perseguirBread();
    void perseguirA();
    void devolverse();
    void patrullar();
public:
    int getVelocidadRuta() const;

    int getVelocidadPersecusion() const;

    bool isVivo() const;
    void setVivo(bool vivo);
    int getEspectro() const;
    ColorEspectro getColor() const;

    void setProceso(Proceso proceso);

    int getVision();
    bool checkearVision();
    Proceso getProceso() ;
    void setY(int y);
    void setX(int x);
    int getX();
    int getY();
    void nextStep();
    void mover();
    virtual void habilidad(int x, int y);

    int visited{-1};
};


class EspectroGris : public Espectro{
public:
    EspectroGris( int velocidadRuta, int velocidadPersecusion, int vision, int x, int y,
                 int numEspectro,int** map, int** mapPatrullaje);
};

class EspectroRojo : public Espectro{
private:
    int const frecuenciaFuego{1000};
    int timeUntilFuego{0};
public:
    EspectroRojo( int velocidadRuta, int velocidadPersecusion, int vision, int x, int y,
                  int numEspectro,int** map,int** mapPatrullaje);

};

class EspectroAzul : public Espectro{
public:
    EspectroAzul( int velocidadRuta, int velocidadPersecusion, int vision, int x, int y,
                  int numEspectro, int** map,int** mapPatrullaje);
    void habilidad(int x, int y) override;
};


class EspectroFactory
{
public:
    static Espectro *Get(ColorEspectro color, int velocidadRuta, int velocidadPersecusion, int vision, int x, int y,
                         int numEspectro, int** map, int** mapPatrullaje)
    {
        switch (color) {
            case Gris:
                return new EspectroGris( velocidadRuta, velocidadPersecusion, vision, x, y,numEspectro, map, mapPatrullaje);
            case Azul:
                return  new EspectroAzul( velocidadRuta, velocidadPersecusion, vision, x, y,numEspectro, map, mapPatrullaje);
            case Rojo:
                return new EspectroRojo( velocidadRuta, velocidadPersecusion, vision, x, y,numEspectro, map, mapPatrullaje);
        }
        return nullptr;
    }
};


#endif //UNTITLED_ESPECTRO_H
