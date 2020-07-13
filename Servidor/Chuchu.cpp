/* 
 * File:   Chuchu.cpp
 * Author: arman
 * 
 * Created on 1 de julio de 2020, 07:03 PM
 */

#include "Chuchu.h"
#include "bresen.h"
#include "Operaciones_Json.h"
int posX;
int posY;

Chuchu::Chuchu(int chuchu, int** map, int x, int y) {
    this->chuchu=chuchu;
    this->map=map;
    setPos(x, y);
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
    bresen move = *new bresen(map);
    Operaciones_Json json = *new Operaciones_Json();

    move.Iniciar(GetPosX(),GetPosY(), false);
    setPos(move.getx(), move.gety());

    json.WRITE(0, "posx",to_string(GetPosX()));
    json.WRITE(0, "posy",to_string(GetPosY()));
    
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

Chuchu::Chuchu() {

}








