//
// Created by brayan on 6/7/20.
//

#include "Cofre.h"

int Cofre::getX() const {
    return x;
}

void Cofre::setX(int x) {
    Cofre::x = x;
}

int Cofre::getY() const {
    return y;
}

void Cofre::setY(int y) {
    Cofre::y = y;
}

bool Cofre::isRoto() const {
    return roto;
}

void Cofre::setRoto() {
    Cofre::roto = true;
}

Cofre::Cofre(int x, int y) : x(x), y(y) {
    roto= false;
}
