/* 
 * File:   Raton.cpp
 * Author: arman
 * 
 * Created on 1 de julio de 2020, 07:38 PM
 */

#include <cstdlib>
#include "Raton.h"
#include "bresen.h"
#include "math.h"

int posX;
int posY;

Raton::Raton() {
}



void Raton::setPos(int x, int y){
    posX = x;
    posY = y;
}

int Raton::GetPosX(){
    return posX;
}

int Raton::GetPosY(){
    return posY;
}

void Raton::movimiento(){
    posX=posX-1+ rand() % 3;
    posY=posY-1+ rand() % 3;
}

bool Raton::checkearVision(int x, int y, int vision){
    return sqrt(pow(posY - x, 2) + pow(posY - y, 2)) < vision;
}

bool Raton::isVivo() const {
    return vivo;
}

void Raton::setVivo(bool vivo) {
    Raton::vivo = vivo;
}

