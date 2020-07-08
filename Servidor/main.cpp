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
#include "Operaciones_Json.cpp"



using namespace std;

int main() {
    /**
    Genetico gen = *new Genetico();
    gen.Iniciar_Poblacion();
    gen.mostrar_grafo();
    gen.seleccion();
    gen.mostrar_grafo();
    
    
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
     * */
    
    Operaciones_Json json = *new Operaciones_Json();
    json.WRITE("jugador", "vidas", "4");
     
    cout << "Hola" << endl;
    return 0;

}

