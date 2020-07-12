/* 
 * File:   main.cpp
 * Author: arman
 *
 * Created on 24 de junio de 2020, 04:03 PM
 */

#include <cstdlib>
#include <iostream>
#include "GENETICO.h"
#include "bresen.h"
#include "Operaciones_Json.h"
#include "Chuchu.h"




using namespace std;

int main() {
    /**
    
    
    
    int map[10][10]={{0,0,1,0,0,0,0,0,1,0},
                     {0,0,1,0,0,0,0,0,1,0},
                     {0,0,1,0,0,0,0,0,1,0},
                     {0,0,1,0,0,1,1,1,1,0},
                     {0,0,1,0,1,1,0,0,0,0},
                     {0,0,1,0,0,1,1,0,0,0},
                     {0,0,1,0,0,0,1,0,0,0},
                     {0,0,1,0,1,0,1,0,0,0},
                     {0,0,1,0,1,0,0,0,0,0},
                     {0,5,1,1,1,1,1,0,0,0}};

    bresen br = *new bresen();
    
    br.Iniciar(0,0);
    
    cout << "fin" << endl;
     
    
    Chuchu chu = *new Chuchu(1,0,0);
    chu.movimiento();
    * */
    Genetico gen = *new Genetico();
    gen.Iniciar_Poblacion();
    gen.mostrar_grafo();
    int dato = gen.retornarGen(2,3);
    cout << "Este es el gen: " << dato << endl;
    return 0;

}

