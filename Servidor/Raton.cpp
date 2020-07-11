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
#include "Matrix.h"
int posX;
int posY;

Raton::Raton(int raton) {
    this->raton=raton;
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

void Raton::movimiento(int** map){
    int newposX=posX-1+ rand() % 3;
    int newposY=posY-1+ rand() % 3;
    if(posY>=0 && posY<=Matrix::SIZEY && posX>=0 && posX<=Matrix::SIZEX){
        if(map[newposX][newposY]!=0){
            posX=newposX;
            posY=newposY;
        } else{
            this->movimiento(map);
        }
    }else{
        this->movimiento(map);
    }
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

int Raton::getRaton() const {
    return raton;
}

void Raton::setRaton(int raton) {
    Raton::raton = raton;
}

