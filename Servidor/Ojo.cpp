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

Ojo::Ojo( int ojo) {
    this->ojo=ojo;
    vivo=true;
    vision=3;
}

void Ojo::setPos(int x, int y){
    posX = x;
    posY = y;
}

int Ojo::GetPosX(){
    return posX;
}

bool Ojo::checkearVision(){
    Jugador j= * Jugador::getJugador();
    return sqrt(pow(posY - j.getX(), 2) + pow(posY - j.getY(), 2)) < vision;
}


int Ojo::GetPosY(){
    return posY;
}

void Ojo::movimiento(){
    
}

bool Ojo::isVivo() const {
    return vivo;
}

void Ojo::setVivo(bool vivo) {
    Ojo::vivo = vivo;
}

int Ojo::getOjo() const {
    return ojo;
}

void Ojo::setOjo(int ojo) {
    Ojo::ojo = ojo;
}

int Ojo::getVision() const {
    return vision;
}




