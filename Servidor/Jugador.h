/* 
 * File:   Jugador.h
 * Author: arman
 *
 * Created on 1 de julio de 2020, 02:07 PM
 */

#ifndef JUGADOR_H
#define	JUGADOR_H
#include <utility>
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
    void ubicacion(std::pair<int, int> ubicacion);
    int** tracesMap;
    int movementNum;

    int getMovementNum() const;

    int **getTracesMap() const;
    void setTracesMap(int **tracesMap);

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


