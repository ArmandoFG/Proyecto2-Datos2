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

void setPos(int x, int y);
int GetPosX();
int GetPosY();

Chuchu::Chuchu(int x, int y) {
    setPos(x,y);
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
    bresen move = *new bresen();
    Operaciones_Json json = *new Operaciones_Json();

    move.Iniciar(GetPosX(),GetPosY(), false);
    setPos(move.getx(), move.gety());

    json.WRITE("chuchu","posx", to_string(GetPosX()));
    json.WRITE("chuchu","posy", to_string(GetPosY()));
    
}


