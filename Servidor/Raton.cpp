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

/**
 * @brief Construct a new Raton:: Raton object
 * 
 * @param raton int
 */

Raton::Raton(int raton) {
    this->raton=raton;
}
/**
 * @brief Cambiar posicion del raton
 * 
 * @param x entero Posicion x
 * @param y entero Posicion y
 */

void Raton::setPos(int x, int y){
    posX = x;
    posY = y;
}
/**
 * @brief Obtener posicion x
 * 
 * @return int 
 */

int Raton::GetPosX(){
    return posX;
}
/**
 * @brief Obtener posicion y
 * 
 * @return int 
 */
int Raton::GetPosY(){
    return posY;
}
/**
 * @brief Movimiento del raton
 * 
 * @param map Nivel del juego
 */
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
/**
 * @brief Vision del ratón
 * 
 * @param x Entero posicion x
 * @param y Entero posicion y
 * @param vision Estero visión
 * @return true 
 * @return false 
 */
bool Raton::checkearVision(int x, int y, int vision){
    return sqrt(pow(posY - x, 2) + pow(posY - y, 2)) < vision;
}
/**
 * @brief Estado de la vida
 * 
 * @return true 
 * @return false 
 */
bool Raton::isVivo() const {
    return vivo;
}
/**
 * @brief Cambiar estado de la vida
 * 
 * @param vivo 
 */

void Raton::setVivo(bool vivo) {
    Raton::vivo = vivo;
}
/**
 * @brief Obtener ratón
 * 
 * @return int 
 */
int Raton::getRaton() const {
    return raton;
}
/**
 * @brief Cambiar ratón
 * 
 * @param raton 
 */

void Raton::setRaton(int raton) {
    Raton::raton = raton;
}

