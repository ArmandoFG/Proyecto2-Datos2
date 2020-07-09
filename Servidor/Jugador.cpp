/* 
 * File:   Jugador.cpp
 * Author: arman
 * 
 * Created on 1 de julio de 2020, 02:07 PM
 */

#include "Jugador.h"


Jugador::Jugador() {
    vida = 5;
}

Jugador* Jugador::getJugador(){
    if(instance!= nullptr){
        instance = new Jugador();
    }
    return instance;
}

void Jugador::setmarcador(int num){
    marcador += num;
}
int Jugador::getmarcador(){
    return marcador;
}

void Jugador::setvida(int vida){
    this->vida=vida;
}

int Jugador::getX(){
    return x;
}

int Jugador::getY(){
    return y;
}

int Jugador::getVida(){
    return vida;
          
}

void Jugador::ubicacion(int x, int y){
    posicionX = x;
    posicionY = y;
}

void Jugador::setX(int x) {
    Jugador::x = x;
}

void Jugador::setY(int y) {
    Jugador::y = y;
}



