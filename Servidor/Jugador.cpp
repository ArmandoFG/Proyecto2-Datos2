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

Jugador::Jugador() {
    vida = 5;
    movementNum=2;
    traces=new TList<std::pair<int, int>>;
}

Jugador* Jugador::getJugador(){
    if(instance== nullptr){
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

void Jugador::setX(int x) {
    Jugador::x = x;
}

void Jugador::setY(int y) {
    Jugador::y = y;
}


int Jugador::getMovementNum() {
    return movementNum;
}

TList<std::pair<int, int>> *Jugador::getTraces() {
    return traces;
}

void Jugador::setTraces(TList<pair<int, int>> *traces) {
    Jugador::traces = traces;
}



