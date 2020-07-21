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

void setPosB(int x, int y);
int getPosxB();
int getPosyB();

/**
 * @brief Construct a new Chuchu:: Chuchu object
 * 
 * @param chuchu identificador del chuchu
 * @param map Nivel del juego
 * @param x posicion x del jugador
 * @param y posicion y del jugador
 */
Chuchu::Chuchu(int chuchu, int** map, int x, int y) {
    this->chuchu=chuchu;
    this->map=map;
    this->posXB = x;
    this->posYB = y
    

}

/**
 * @brief Cambiar posicion del chuchu
 * 
 * @param x posicion x del chuchu
 * @param y posicion y del chuchu
 */
void Chuchu::setPos(int x, int y){
    posX = x;
    posY = y;
   
}

/**
 * @brief Obtener posicion x
 * 
 * @return int 
 */

int Chuchu::GetPosX(){
    return posX;
}
/**
 * @brief Obtener posicion y del jugador
 * 
 * @return int 
 */

int Chuchu::GetPosY(){
    return posY;
}

/**
 * @brief Inicia movimiento del chuchu
 * 
 */
void Chuchu::movimiento(){
    bresen move = *new bresen(map);
    Operaciones_Json json = *new Operaciones_Json();
    move.Iniciar(getPosxB(),getPosyB(), false);
    setPos(move.getx(), move.gety()); 
    
}
/**
 * @brief Verifica si el chuchu está vivo
 * 
 * @return true 
 * @return false 
 */

bool Chuchu::isVivo() const {
    return vivo;
}
/**
 * @brief Cambia el estado de vida del chuchu
 * 
 * @param vivo 
 */
void Chuchu::setVivo(bool vivo) {
    Chuchu::vivo = vivo;
}

/**
 * @brief Obtiene el chuchu
 * 
 * @return int 
 */

int Chuchu::getChuchu() const {
    return chuchu;
}



void Chuchu::setChuchu(int chuchu) {
    Chuchu::chuchu = chuchu;
}
int getPosxB(){
    return Chuchu::posXB;
}
int getPosyB(){
    return Chuchu::posYB;

}




Chuchu::Chuchu() {

}








