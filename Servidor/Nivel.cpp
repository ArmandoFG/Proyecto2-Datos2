//
// Created by brayan on 4/7/20.
//

#include "Nivel.h"
#include "Matrix.h"
#include "GENETICO.h"

Genetico* Nivel::g=new Genetico;

int** Nivel::getMap() {
   return (int **) (this->map);
}

Nivel::Nivel() {
    espectros=new TList<Espectro*>;
    ratones=new TList<Raton*>;
    chuchus=new TList<Chuchu*>;
    ojos=new TList<Ojo*>;
}

Nivel1::Nivel1():Nivel() {
    g->Iniciar_Poblacion();
    map=Matrix::generateMatrix1();
    mapPatrullaje=Matrix::rutasMatrix1();
    espectros->addLast(EspectroFactory::Get(Gris,    g->retornarGen(0,0)
        ,g->retornarGen(0,1), 9, 9,23 ,1, map, mapPatrullaje));
    espectros->addLast(EspectroFactory::Get(Gris,    g->retornarGen(0,0)
            ,g->retornarGen(0,1), 9, 33,5,2, map, mapPatrullaje));
    espectros->addLast(EspectroFactory::Get(Gris,    g->retornarGen(0,0)
            ,g->retornarGen(0,1), 9, 33,41,3, map, mapPatrullaje));
    ratones->addLast(new Raton(1));
    ratones->addLast(new Raton(2));
    chuchus->addLast(new Chuchu(1,map, 14,12));
}


Nivel2::Nivel2():Nivel() {
    map=Matrix::generateMatrix2();
    g->seleccion();
    mapPatrullaje=Matrix::generateMatrix2();
    espectros->addLast(EspectroFactory::Get(Rojo,    g->retornarGen(0,0)
            ,g->retornarGen(0,1), g->retornarGen(0,2), 10,25,1, map, mapPatrullaje));
    espectros->addLast(EspectroFactory::Get(Rojo,    g->retornarGen(0,0)
            ,g->retornarGen(0,1), g->retornarGen(0,2), 33,4,2, map, mapPatrullaje));
    espectros->addLast(EspectroFactory::Get(Rojo,    g->retornarGen(0,0)
            ,g->retornarGen(0,1), g->retornarGen(0,2), 30,40,3, map, mapPatrullaje));
}

Nivel3::Nivel3() {
    map=Matrix::generateMatrix3();
    mapPatrullaje=Matrix::generateMatrix3();
    g->seleccion();
    espectros->addLast(EspectroFactory::Get(Azul,    g->retornarGen(0,0)
            ,g->retornarGen(0,1), g->retornarGen(0,2), 10,15,1, map, mapPatrullaje));
    espectros->addLast(EspectroFactory::Get(Azul,    g->retornarGen(0,0)
            ,g->retornarGen(0,1), g->retornarGen(0,2), 23,34,2, map, mapPatrullaje));
    espectros->addLast(EspectroFactory::Get(Azul,    g->retornarGen(0,0)
            ,g->retornarGen(0,1), g->retornarGen(0,2), 40,26,3, map, mapPatrullaje));
    ojos->addLast(new Ojo(9,9,1));
}

Nivel4::Nivel4():Nivel() {
    map=Matrix::generateMatrix4();
    mapPatrullaje=Matrix::generateMatrix4();
    g->seleccion();
    espectros->addLast(EspectroFactory::Get(Azul,    g->retornarGen(0,0)
            ,g->retornarGen(0,1), g->retornarGen(0,2), 4,23,1, map, mapPatrullaje));
    espectros->addLast(EspectroFactory::Get(Gris,    g->retornarGen(0,0)
            ,g->retornarGen(0,1), g->retornarGen(0,2), 23,39,2, map, mapPatrullaje));
    espectros->addLast(EspectroFactory::Get(Rojo,    g->retornarGen(0,0)
            ,g->retornarGen(0,1), g->retornarGen(0,2), 40,26,3, map, mapPatrullaje));
}

Nivel5::Nivel5(): Nivel(){
    map=Matrix::generateMatrix5();
    mapPatrullaje=Matrix::generateMatrix5();
    espectros->addLast(EspectroFactory::Get(Azul,1000,1500, 50, 8,9,0, map, mapPatrullaje));
}

TList<Raton*>* Nivel::getRatones() {
    return ratones;
}

TList<Ojo*>* Nivel::getOjos() {
    return ojos;
}

TList<Chuchu*>* Nivel::getChuchus() {
    return chuchus;
}

TList<Espectro*>* Nivel::getEspectros() {
    return espectros;
}



