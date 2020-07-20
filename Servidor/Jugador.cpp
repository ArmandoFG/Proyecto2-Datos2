/* 
 * File:   Jugador.cpp
 * Author: arman
 * 
 * Created on 1 de julio de 2020, 02:07 PM
 */

#include <utility>
#include "Jugador.h"
#include "Matrix.h"

Jugador* Jugador::instance= nullptr;
using namespace std;

/**
 * @brief Construct a new Jugador:: Jugador object
 * 
 */

Jugador::Jugador() {
    vida = 5;
    movementNum=2;
    traces=new TList<std::pair<int, int>>;
}
/**
 * @brief Obtener jugador
 * 
 * @return Jugador* 
 */

Jugador* Jugador::getJugador(){
    if(instance== nullptr){
        instance = new Jugador();
    }
    return instance;
}
/**
 * @brief Cambiar marcador del juego
 * 
 * @param num Entero a aumentar
 */

void Jugador::setmarcador(int num){
    marcador += num;
}
/**
 * @brief Obtener marcador
 * 
 * @return int 
 */
int Jugador::getmarcador(){
    return marcador;
}

/**
 * @brief Cambiar vida del jugador
 * 
 * @param vida Entero
 */
void Jugador::setvida(int vida){
    this->vida=vida;
}

/**
 * @brief Obtener posicion x del jugador
 * 
 * @return int 
 */
int Jugador::getX(){
    return x;
}
/**
 * @brief Obtener posicion y del jugador
 * 
 * @return int 
 */

int Jugador::getY(){
    return y;
}

/**
 * @brief Obtener vida del jugador
 * 
 * @return int 
 */
int Jugador::getVida(){
    return vida;
}
/**
 * @brief Ubicacion del jugador dentro de la matriz
 * 
 * @param ubicacion Puntos x y del jugador
 */

void Jugador::ubicacion(std::pair<int, int> ubicacion){
    this->x = ubicacion.first;
    this->y = ubicacion.second;
    if(traces->largo>0){
        if(x!=traces->getNodoPos(traces->largo-1)->getValue().first||
                    y!=traces->getNodoPos(traces->largo-1)->getValue().second){
            traces->addLast(make_pair(x, y));
            movementNum++;
        }
    }else{
        traces->addLast(make_pair(x, y));
        movementNum++;
    }
}
/**
 * @brief Cambiar posicon x del jugador
 * 
 * @param x Entero
 */

void Jugador::setX(int x) {
    Jugador::x = x;
}
/**
 * @brief Cambiar posicion y del jugador
 * 
 * @param y Entero
 */

void Jugador::setY(int y) {
    Jugador::y = y;
}
/**
 * @brief Obtener movimiento
 * 
 * @return int 
 */

int Jugador::getMovementNum() {
    return movementNum;
}


TList<std::pair<int, int>> *Jugador::getTraces() {
    return traces;
}

void Jugador::setTraces(TList<pair<int, int>> *traces) {
    Jugador::traces = traces;
}



