/* 
 * File:   Jugador.cpp
 * Author: arman
 * 
 * Created on 1 de julio de 2020, 02:07 PM
 */

#include "Jugador.h"

int marcador;
int vida = 5;
int posicionX;
int posicionY;

Jugador::Jugador() {
}

void Jugador::setmarcador(int num){
    marcador += num;
}
int Jugador::getmarcador(){
    return marcador;
}

void Jugador::setvida(){
    vida--;
}

int Jugador::getVida(){
    return vida;
          
}

void Jugador::ubicacion(int x, int y){
    posicionX = x;
    posicionY = y;
}



