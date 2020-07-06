/* 
 * File:   Raton.cpp
 * Author: arman
 * 
 * Created on 1 de julio de 2020, 07:38 PM
 */

#include "Raton.h"
#include "bresen.h"

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
    
}


