//
// Created by brayan on 4/7/20.
//

#include "Nivel.h"
#include "Matrix.h"

int** Nivel::getMap() {
   return (int **) (this->map);
}

Nivel::Nivel() {
    espectros=*new TList<Espectro>;
    ratones=*new TList<Raton>;
    chuchus=*new TList<Chuchu>;
    ojos=*new TList<Ojo>;
}

Nivel1::Nivel1():Nivel() {
    espectros.addLast(*EspectroFactory::Get(Gris,200,400, 50, 8,9,0));
    espectros.addLast(*EspectroFactory::Get(Gris,200,400, 50, 8,9,0));
    espectros.addLast(*EspectroFactory::Get(Gris,200,400, 50, 8,9,0));
    map=Matrix::generateMatrix1();
}


Nivel2::Nivel2():Nivel() {
    espectros.addLast(*EspectroFactory::Get(Rojo,200,400, 50, 8,9,0));
    espectros.addLast(*EspectroFactory::Get(Rojo,200,400, 50, 8,9,0));
    espectros.addLast(*EspectroFactory::Get(Rojo,200,400, 50, 8,9,0));
    map=Matrix::generateMatrix2();
}

Nivel3::Nivel3() {
    espectros.addLast(*EspectroFactory::Get(Azul,200,400, 50, 8,9,0));
    espectros.addLast(*EspectroFactory::Get(Azul,200,400, 50, 8,9,0));
    espectros.addLast(*EspectroFactory::Get(Azul,200,400, 50, 8,9,0));
    ojos.addLast(*new Ojo(9,9,1));
    map=Matrix::generateMatrix3();

}

Nivel4::Nivel4():Nivel() {
    espectros.addLast(*EspectroFactory::Get(Azul,200,400, 50, 8,9,0));
    espectros.addLast(*EspectroFactory::Get(Gris,200,400, 50, 8,9,0));
    espectros.addLast(*EspectroFactory::Get(Rojo,200,400, 50, 8,9,0));
    map=Matrix::generateMatrix4();

}

Nivel5::Nivel5(): Nivel(){
    espectros.addLast(*EspectroFactory::Get(Azul,1000,1500, 50, 8,9,0));
    map=Matrix::generateMatrix5();
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



