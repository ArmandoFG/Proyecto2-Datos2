//
// Created by brayan on 6/7/20.
//

#include "Fuego.h"

int Fuego::getX() const {
    return x;
}

void Fuego::setX(int x) {
    Fuego::x = x;
}

int Fuego::getY() const {
    return y;
}

void Fuego::setY(int y) {
    Fuego::y = y;
}

int Fuego::getDirx() const {
    return dirx;
}

void Fuego::setDirx(int dirx) {
    Fuego::dirx = dirx;
}

int Fuego::getDiry() const {
    return diry;
}

void Fuego::setDiry(int diry) {
    Fuego::diry = diry;
}

Fuego::Fuego(int x, int y, int dirx, int diry) {
    this->x=x;
    this->y=y;
    this->dirx=dirx;
    this->diry=diry;
}
