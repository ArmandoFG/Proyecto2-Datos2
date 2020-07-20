//
// Created by brayan on 4/7/20.
//

#include "Nivel.h"
#include "Matrix.h"
#include "GENETICO.h"

Genetico* Nivel::g=new Genetico;

/**
 * @brief Retorna el mapa del nivel
 * 
 * @return int** 
 */

int** Nivel::getMap() {
   return (int **) (this->map);
}

/**
 * @brief Construct a new Nivel:: Nivel object
 * 
 */

Nivel::Nivel() {
    espectros=new TList<Espectro*>;
    ratones=new TList<Raton*>;
    chuchus=new TList<Chuchu*>;
    ojos=new TList<Ojo*>;
}

/**
 * @brief Construct a new Nivel 1:: Nivel 1 object
 * 
 */

Nivel1::Nivel1():Nivel() {
    g->Iniciar_Poblacion();
    map=Matrix::generateMatrix1();
    mapPatrullaje=Matrix::rutasMatrix1();
    espectros->addLast(EspectroFactory::Get(Gris,    g->retornarGen(0,0)
        ,g->retornarGen(0,1), 4, 9,23 ,1, map, mapPatrullaje));
    espectros->addLast(EspectroFactory::Get(Gris,    g->retornarGen(0,0)
            ,g->retornarGen(0,1), 4, 33,5,2, map, mapPatrullaje));
    espectros->addLast(EspectroFactory::Get(Gris,    g->retornarGen(0,0)
            ,g->retornarGen(0,1), 4, 33,41,3, map, mapPatrullaje));
    ratones->addLast(new Raton(1));
    ratones->addLast(new Raton(2));
    chuchus->addLast(new Chuchu(1,map, 14,12));
}

/**
 * @brief Construct a new Nivel 2:: Nivel 2 object
 * 
 */

Nivel2::Nivel2():Nivel() {
    map=Matrix::generateMatrix2();
    g->seleccion();
    mapPatrullaje=Matrix::rutasMatrix2();
    espectros->addLast(EspectroFactory::Get(Rojo,    g->retornarGen(0,0)
            ,g->retornarGen(0,1), g->retornarGen(0,2), 10,25,1, map, mapPatrullaje));
    espectros->addLast(EspectroFactory::Get(Rojo,    g->retornarGen(0,0)
            ,g->retornarGen(0,1), g->retornarGen(0,2), 33,4,2, map, mapPatrullaje));
    espectros->addLast(EspectroFactory::Get(Rojo,    g->retornarGen(0,0)
            ,g->retornarGen(0,1), g->retornarGen(0,2), 25,41,3, map, mapPatrullaje));
    ratones->addLast(new Raton(1));
    ratones->addLast(new Raton(2));
    chuchus->addLast(new Chuchu(1,map, 33,23));
    ojos->addLast(new Ojo(1));
}
/**
 * @brief Construct a new Nivel 3:: Nivel 3 object
 * 
 */
Nivel3::Nivel3() {
    map=Matrix::generateMatrix3();
    mapPatrullaje=Matrix::rutasMatrix3();
    g->seleccion();
    espectros->addLast(EspectroFactory::Get(Azul,    g->retornarGen(0,0)
            ,g->retornarGen(0,1), g->retornarGen(0,2), 10,15,1, map, mapPatrullaje));
    espectros->addLast(EspectroFactory::Get(Azul,    g->retornarGen(0,0)
            ,g->retornarGen(0,1), g->retornarGen(0,2), 23,34,2, map, mapPatrullaje));
    espectros->addLast(EspectroFactory::Get(Azul,    g->retornarGen(0,0)
            ,g->retornarGen(0,1), g->retornarGen(0,2), 40,26,3, map, mapPatrullaje));
    ojos->addLast(new Ojo(1));
    ojos->addLast(new Ojo(2));
    ojos->addLast(new Ojo(3));
    ratones->addLast(new Raton(1));
    chuchus->addLast(new Chuchu(1,map, 35,15));

}
/**
 * @brief Construct a new Nivel 4:: Nivel 4 object
 * 
 */

Nivel4::Nivel4():Nivel() {
    map=Matrix::generateMatrix4();
    mapPatrullaje=Matrix::rutasMatrix4();
    g->seleccion();
    espectros->addLast(EspectroFactory::Get(Gris,    g->retornarGen(0,0)
            ,g->retornarGen(0,1), g->retornarGen(0,2), 4,23,1, map, mapPatrullaje));
    espectros->addLast(EspectroFactory::Get(Azul,    g->retornarGen(0,0)
            ,g->retornarGen(0,1), g->retornarGen(0,2), 23,39,2, map, mapPatrullaje));
    espectros->addLast(EspectroFactory::Get(Rojo,    g->retornarGen(0,0)
            ,g->retornarGen(0,1), g->retornarGen(0,2), 40,26,3, map, mapPatrullaje));
    ojos->addLast(new Ojo(1));
    ojos->addLast(new Ojo(2));
    ratones->addLast(new Raton(1));
    chuchus->addLast(new Chuchu(1,map, 31,40));

}
/**
 * @brief Construct a new Nivel 5:: Nivel 5 object
 * 
 */

Nivel5::Nivel5(): Nivel(){
    map=Matrix::generateMatrix5();
    mapPatrullaje=Matrix::generateMatrix5();
    espectros->addLast(EspectroFactory::Get(Gris,6,6, 10, 25,25,
            1, map, mapPatrullaje));
    espectros->getFirst()->getValue()->setColor(Final);
}

/**
 * @brief Ratones del nivel
 * 
 * @return TList<Raton*>* 
 */

TList<Raton*>* Nivel::getRatones() {
    return ratones;
}
/**
 * @brief Obtener ojos del juego
 * 
 * @return TList<Ojo*>* 
 */

TList<Ojo*>* Nivel::getOjos() {
    return ojos;
}
/**
 * @brief Obtener chuchu del juego
 * 
 * @return TList<Chuchu*>* 
 */
TList<Chuchu*>* Nivel::getChuchus() {
    return chuchus;
}
/**
 * @brief Obtener espectros del juego
 * 
 * @return TList<Espectro*>* 
 */

TList<Espectro*>* Nivel::getEspectros() {
    return espectros;
}



