//
// Created by brayan on 4/7/20.
//

#include "Nivel.h"

int* Nivel1::getMap() {
   return (int *) (this->map);
}

Nivel::Nivel() {
    espectros=*new TList<Espectro>;
    jarrones=*new TList<Jarron>;
    ratones=*new TList<Raton>;
    chuchus=*new TList<Chuchu>;
    ojos=*new TList<Ojo>;

}

Nivel1::Nivel1():Nivel() {
    espectros.addLast(*EspectroFactory::Get(Gris,200,400, 50, 8,9,0));
    espectros.addLast(*EspectroFactory::Get(Gris,200,400, 50, 8,9,0));
    espectros.addLast(*EspectroFactory::Get(Gris,200,400, 50, 8,9,0));
}


int** Nivel2::getMap() {
    return (int **) (this->map);
}

Nivel2::Nivel2():Nivel() {
    espectros.addLast(*EspectroFactory::Get(Rojo,200,400, 50, 8,9,0));
    espectros.addLast(*EspectroFactory::Get(Rojo,200,400, 50, 8,9,0));
    espectros.addLast(*EspectroFactory::Get(Rojo,200,400, 50, 8,9,0));

}

int** Nivel3::getMap() {
    return (int **) (this->map);
}

Nivel3::Nivel3() {
    espectros.addLast(*EspectroFactory::Get(Azul,200,400, 50, 8,9,0));
    espectros.addLast(*EspectroFactory::Get(Azul,200,400, 50, 8,9,0));
    espectros.addLast(*EspectroFactory::Get(Azul,200,400, 50, 8,9,0));
    ojos.addLast(*new Ojo(9,9,1));

}

Nivel4::Nivel4():Nivel() {
    espectros.addLast(*EspectroFactory::Get(Azul,200,400, 50, 8,9,0));
    espectros.addLast(*EspectroFactory::Get(Gris,200,400, 50, 8,9,0));
    espectros.addLast(*EspectroFactory::Get(Rojo,200,400, 50, 8,9,0));

}

Nivel5::Nivel5(): Nivel(){
    espectros.addLast(*EspectroFactory::Get(Azul,1000,1500, 50, 8,9,0));
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



