//
// Created by brayan on 4/7/20.
//

#include "Nivel.h"

int* Nivel1::getMap() {
   return (int *) (this->map);
}
int* Nivel2::getMap() {
    return (int *) (this->map);
}
int* Nivel3::getMap() {
    return (int *) (this->map);
}

TList<Raton> Nivel::getRatones() {
    return ratones;
}

TList<Ojo> Nivel::getOjos() {
    return ojos;
}

TList<Chuchu> Nivel::getChuchus() {
    return chuchus;
}

TList<Espectro> Nivel::getEspectros() {
    return espectros;
}
