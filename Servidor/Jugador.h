/* 
 * File:   Jugador.h
 * Author: arman
 *
 * Created on 1 de julio de 2020, 02:07 PM
 */

#ifndef JUGADOR_H
#define	JUGADOR_H
#include <utility>
#include "TList.h"
using namespace std;

class Jugador {
public:
    static Jugador* getJugador();
    void setmarcador(int num);
    int getmarcador();
    void setvida(int vida);
    int getVida();
    int getX();
    int getY();

    TList<std::pair<int, int>> *getTraces() ;

    void setTraces(TList<pair<int, int>> *traces);

    void ubicacion(std::pair<int, int> ubicacion);
    TList<std::pair<int, int>>* traces;
    int movementNum;
    int getMovementNum();

private:
    Jugador();
    int x;
    int y;
public:
    void setX(int x);

    void setY(int y);

private:
    int vida;
    int marcador;
    static Jugador* instance;
};

#endif	/* JUGADOR_H */


