//
// Created by brayan on 4/7/20.
//

#include "Nivel.h"
#include "Matrix.h"
#include "GENETICO.h"
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
    g = *new Genetico;
    g.Iniciar_Poblacion();
    map=Matrix::generateMatrix1();
    mapPatrullaje=Matrix::generateMatrix1();
    espectros.addLast(*EspectroFactory::Get(Gris,    g.retornarGen(0,0)
        ,g.retornarGen(0,1), g.retornarGen(0,2), 8,9,1, map, mapPatrullaje));
    espectros.addLast(*EspectroFactory::Get(Gris,    g.retornarGen(0,0)
            ,g.retornarGen(0,1), g.retornarGen(0,2), 8,9,2, map, mapPatrullaje));
    espectros.addLast(*EspectroFactory::Get(Gris,    g.retornarGen(0,0)
            ,g.retornarGen(0,1), g.retornarGen(0,2), 8,9,3, map, mapPatrullaje));
}


Nivel2::Nivel2():Nivel() {
    map=Matrix::generateMatrix2();
    g.seleccion();
    mapPatrullaje=Matrix::generateMatrix2();
    espectros.addLast(*EspectroFactory::Get(Rojo,    g.retornarGen(0,0)
            ,g.retornarGen(0,1), g.retornarGen(0,2), 8,9,1, map, mapPatrullaje));
    espectros.addLast(*EspectroFactory::Get(Rojo,    g.retornarGen(0,0)
            ,g.retornarGen(0,1), g.retornarGen(0,2), 8,9,2, map, mapPatrullaje));
    espectros.addLast(*EspectroFactory::Get(Rojo,    g.retornarGen(0,0)
            ,g.retornarGen(0,1), g.retornarGen(0,2), 8,9,3, map, mapPatrullaje));
}

Nivel3::Nivel3() {
    map=Matrix::generateMatrix3();
    mapPatrullaje=Matrix::generateMatrix3();
    g.seleccion();
    espectros.addLast(*EspectroFactory::Get(Azul,    g.retornarGen(0,0)
            ,g.retornarGen(0,1), g.retornarGen(0,2), 8,9,1, map, mapPatrullaje));
    espectros.addLast(*EspectroFactory::Get(Azul,    g.retornarGen(0,0)
            ,g.retornarGen(0,1), g.retornarGen(0,2), 8,9,2, map, mapPatrullaje));
    espectros.addLast(*EspectroFactory::Get(Azul,    g.retornarGen(0,0)
            ,g.retornarGen(0,1), g.retornarGen(0,2), 8,9,3, map, mapPatrullaje));
    ojos.addLast(*new Ojo(9,9,1));
}

Nivel4::Nivel4():Nivel() {
    map=Matrix::generateMatrix4();
    mapPatrullaje=Matrix::generateMatrix4();
    g.seleccion();
    espectros.addLast(*EspectroFactory::Get(Azul,    g.retornarGen(0,0)
            ,g.retornarGen(0,1), g.retornarGen(0,2), 8,9,1, map, mapPatrullaje));
    espectros.addLast(*EspectroFactory::Get(Gris,    g.retornarGen(0,0)
            ,g.retornarGen(0,1), g.retornarGen(0,2), 8,9,2, map, mapPatrullaje));
    espectros.addLast(*EspectroFactory::Get(Rojo,    g.retornarGen(0,0)
            ,g.retornarGen(0,1), g.retornarGen(0,2), 8,9,3, map, mapPatrullaje));
}

Nivel5::Nivel5(): Nivel(){
    map=Matrix::generateMatrix5();
    mapPatrullaje=Matrix::generateMatrix5();
    espectros.addLast(*EspectroFactory::Get(Azul,1000,1500, 50, 8,9,0, map, mapPatrullaje));
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



