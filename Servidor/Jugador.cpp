/* 
 * File:   Jugador.cpp
 * Author: arman
 * 
 * Created on 1 de julio de 2020, 02:07 PM
 */

#include <utility>
#include "Jugador.h"
using namespace std;

Jugador::Jugador() {
    vida = 5;
    movementNum=2;
}

Jugador* Jugador::getJugador(){
    if(instance!= nullptr){
        instance = new Jugador();
    }
    return instance;
}

void Jugador::setmarcador(int num){
    marcador += num;
}
int Jugador::getmarcador(){
    return marcador;
}

void Jugador::setvida(int vida){
    this->vida=vida;
}

int Jugador::getX(){
    return x;
}

int Jugador::getY(){
    return y;
}

int Jugador::getVida(){
    return vida;
}

void Jugador::ubicacion(std::pair<int, int> ubicacion){
    this->x = ubicacion.first;
    this->y = ubicacion.second;
    movementNum+=1;
    tracesMap[x][y]=movementNum;
}

void Jugador::setX(int x) {
    Jugador::x = x;
}

void Jugador::setY(int y) {
    Jugador::y = y;
}

int **Jugador::getTracesMap() const {
    return tracesMap;
}

void Jugador::setTracesMap(int **tracesMap) {
    Jugador::tracesMap = tracesMap;
}

int Jugador::getMovementNum() const {
    return movementNum;
}



