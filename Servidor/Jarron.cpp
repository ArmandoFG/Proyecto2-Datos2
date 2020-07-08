//
// Created by brayan on 6/7/20.
//

#include "Jarron.h"

int Jarron::getX() const {
    return x;
}

void Jarron::setX(int x) {
    Jarron::x = x;
}

int Jarron::getY() const {
    return y;
}

void Jarron::setY(int y) {
    Jarron::y = y;
}

Jarron::Jarron(int x, int y) : x(x), y(y) {}
