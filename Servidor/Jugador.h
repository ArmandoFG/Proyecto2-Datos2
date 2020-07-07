/* 
 * File:   Jugador.h
 * Author: arman
 *
 * Created on 1 de julio de 2020, 02:07 PM
 */

#ifndef JUGADOR_H
#define	JUGADOR_H

class Jugador {
public:
    Jugador();
    static Jugador getJugador();
    void setmarcador(int num);
    int getmarcador();
    void setvida();
    int getVida();
    int getX();
    int getY();
    void ubicacion(int x, int y);
    
private:
    Jugador instance;
};

#endif	/* JUGADOR_H */


