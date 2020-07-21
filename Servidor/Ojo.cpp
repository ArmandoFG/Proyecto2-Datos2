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

/**
 * @brief Construct a new Ojo:: Ojo object
 * 
 * @param ojo id ojo
 */

Ojo::Ojo( int ojo) {
    this->ojo=ojo;
    vivo=true;
    vision=6;
}
/**
 * @brief Cambiar posicion del ojo
 * 
 * @param x posicion x
 * @param y posicion y
 */

void Ojo::setPos(int x, int y){
    posX = x;
    posY = y;
    vision=6;
}

/**
 * @brief Obtener posicion
 * 
 * @return int 
 */
int Ojo::GetPosX(){
    return posX;
}

/**
 * @brief Vision del ojo
 * 
 * @return true 
 * @return false 
 */
bool Ojo::checkearVision(){
    Jugador* j=  Jugador::getJugador();
    return sqrt(pow(posX - j->getX(), 2) + pow(posY - j->getY(), 2)) < vision;
}
/**
 * @brief Obtener posicion y
 * 
 * @return int 
 */

int Ojo::GetPosY(){
    return posY;
}

/**
 * @brief Movimiento ojo
 * 
 */

void Ojo::movimiento(){
    
}

/**
 * @brief Estado del ojo
 * 
 * @return true 
 * @return false 
 */

bool Ojo::isVivo() const {
    return vivo;
}
/**
 * @brief Cambiar estado de vida del ojo
 * 
 * @param vivo 
 */
void Ojo::setVivo(bool vivo) {
    Ojo::vivo = vivo;
}
/**
 * @brief Obtener numero de ojo
 * 
 * @return int 
 */

int Ojo::getOjo() const {
    return ojo;
}/**
 * @brief Cambiar numero de ojo
 * 
 * @param ojo 
 */


void Ojo::setOjo(int ojo) {
    Ojo::ojo = ojo;
}
/**
 * @brief Obtener visión
 * 
 * @return int 
 */

int Ojo::getVision() const {
    return vision;
}




