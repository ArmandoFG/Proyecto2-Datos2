/* 
 * File:   Ojo.cpp
 * Author: arman
 * 
 * Created on 1 de julio de 2020, 07:36 PM
 */

#include "Ojo.h"
#include "bresen.h"
#include "Jugador.h"
#include "math.h"

int posX;
int posY;
Ojo::Ojo(int x, int y) {
    posX=x;
    posY=y;
}

void Ojo::setPos(int x, int y){
    posX = x;
    posY = y;
}

int Ojo::GetPosX(){
    return posX;
}

bool Ojo::checkearVision(){
    Jugador j=Jugador::getJugador();
    return sqrt(pow(posY - j.getX(), 2) + pow(posY - j.getY(), 2)) < vision;
}


int Ojo::GetPosY(){
    return posY;
}

void Ojo::movimiento(){
    
}




