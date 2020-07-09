/* 
 * File:   Chuchu.cpp
 * Author: arman
 * 
 * Created on 1 de julio de 2020, 07:03 PM
 */

#include "Chuchu.h"
#include "bresen.h"

int posX;
int posY;

Chuchu::Chuchu(int chuchu) {
    this->chuchu=chuchu;
}

void Chuchu::setPos(int x, int y){
    posX = x;
    posY = y;
}

int Chuchu::GetPosX(){
    return posX;
}

int Chuchu::GetPosY(){
    return posY;
}

void Chuchu::movimiento(){
    
}

bool Chuchu::isVivo() const {
    return vivo;
}

void Chuchu::setVivo(bool vivo) {
    Chuchu::vivo = vivo;
}

int Chuchu::getChuchu() const {
    return chuchu;
}

void Chuchu::setChuchu(int chuchu) {
    Chuchu::chuchu = chuchu;
}


