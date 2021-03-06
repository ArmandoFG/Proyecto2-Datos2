/* 
 * File:   bresen.cpp
 * Author: arman
 * 
 * Created on 1 de julio de 2020, 09:09 AM
 */

#include "bresen.h"

#include <iostream>
#include<stdlib.h>
#include <stdio.h>
#include<time.h>
#include <math.h>
#include "Matrix.h"
using namespace std;



void Iniciar(int Bx1, int By1);

int x;
int y;
/**
 * @brief Construct a new bresen::bresen object
 * 
 * @param map Nivel del juego
 */

bresen::bresen(int **map) {
    this->map=map;
}
/**
 * @brief Inicia el algoritmo
 * 
 * @param Bx1 Posicion x del chuchu
 * @param By1 Posicion y del chuchu
 * @param listo booleano 
 */

void bresen::Iniciar(int Bx1, int By1, bool listo){
    //srand(time(NULL))

    int direccion = rand()%8;
     Matrix::SIZEX;
     Matrix::SIZEY;

   x=Bx1;

   y=By1;

 

 
   int x2;
   int y2;
   
   //Verifica que si ya encontró una posicion
    
   if(listo != true){
       int contador = 4;
       int contadorAux = 0;
       x2 = x;
       y2 = y;

       int lineasEnMap = Matrix::SIZEX;
       int columnasEnMap = Matrix::SIZEY;

       //Direccion a la que irá

       if(direccion == 0){
       if(map[y2][x2 + 1] == 0 && lineasEnMap >= y2 >= 0 && columnasEnMap >= x2 >= 0){
           
           while(map[x2 + 1][y2] != 1 && contador != contadorAux && lineasEnMap >= y2 >= 0 && columnasEnMap >= x2 >= 0){
               x2++;
               contadorAux++;
           }

            return Iniciar(x2, y2, true);
           
       }else{
       return Iniciar(x2, y2, false);
       }
       }
       if(direccion == 1){
       if(map[y2 + 1][x2 + 1] == 0 && lineasEnMap >= y2 >= 0 && columnasEnMap >= x2 >= 0){

           while(map[y2 + 1][x2 + 1] != 1 && contador != contadorAux && lineasEnMap >= y2 >= 0 && columnasEnMap >= x2 >= 0){
               x2++;
               y2++;
                contadorAux++;

           }
            cout << "Encontre un muro aqui o limite" << endl;

            return Iniciar(x2, y2, true);
           
       }else{
       return Iniciar(x2, y2, false);
       }
       }
       if(direccion == 2){
       if(map[y2 + 1][x2] == 0 && lineasEnMap >= y2 >= 0 && columnasEnMap >= x2 >= 0){
           
           
           while(map[y2 + 1][x2] != 1 && contador != contadorAux && lineasEnMap >= y2 >= 0 && columnasEnMap >= x2 >= 0){
               y2++;
               contadorAux++;
           }
            cout << "Encontre un muro aqui o limite" << endl;

            return Iniciar(x2, y2, true);
           
       }else{
       return Iniciar(x2, y2, false);
       }
       }
       if(direccion == 3){
       if(map[y2 + 1][x2 - 1] == 0 && lineasEnMap >= y2 >= 0 && columnasEnMap >= x2 >= 0){
          
           while(map[y2 + 1][x2 - 1] != 1 && contador != contadorAux && lineasEnMap >= y2 >= 0 && columnasEnMap >= x2 >= 0){
               y2++;
               x2--;  
               contadorAux++;             
           }
            cout << "Encontre un muro aqui o limite" << endl;

            return Iniciar(x2, y2, true);
           
       }else{
       return Iniciar(x2, y2, false);
       }
       }
       if(direccion == 4){
       if(map[y2][x2 - 1] == 0 && lineasEnMap >= y2 >= 0 && columnasEnMap >= x2 >= 0){
          
           while(map[y2][x2 - 1] != 1 && contador != contadorAux && lineasEnMap >= y2 >= 0 && columnasEnMap >= x2 >= 0){
                x2--;
                contadorAux++;
           }
            cout << "Encontre un muro aqui o limite" << endl;
            return Iniciar(x2, y2, true);
           
       }else{
       return Iniciar(x2, y2, false);
       }
       }
       if(direccion == 5){
       if(map[y2 - 1][x2 - 1] == 0 && lineasEnMap >= y2 >= 0 && columnasEnMap >= x2 >= 0){
           
           while(map[y2 - 1][x2 - 1] != 1 && contador != contadorAux && lineasEnMap >= y2 >= 0 && columnasEnMap >= x2 >= 0){
               y2--;
               x2--;
               contadorAux++;
           }
            cout << "Encontre un muro aqui o limite" << endl;           
            return Iniciar(x2, y2, true);
           
       }else{
       return Iniciar(x2, y2, false);
       }
       }
       if(direccion == 6){
       if(map[y2 - 1][x2] == 0 && lineasEnMap >= y2 >= 0 && columnasEnMap >= x2 >= 0){
           
           while(map[y2 - 1][x2] != 1 && contador != contadorAux && lineasEnMap >= y2 >= 0 && columnasEnMap >= x2 >= 0){
                y2--;
                contadorAux++;
           }
             cout << "Encontre un muro aqui o limite" << endl;          
            return Iniciar(x2, y2, true);
           
       }else{
       return Iniciar(x2, y2, false);
       }
       }
       if(direccion == 7){
       if(map[y2 - 1][x2 + 1] == 0 && lineasEnMap >= y2 >= 0 && columnasEnMap >= x2 >= 0){
           
           while(map[y2 - 1][x2 + 1] != 1 && contador != contadorAux && lineasEnMap >= y2 >= 0 && columnasEnMap >= x2 >= 0){
               y2--;
               x2++;
               contadorAux++;
           }
            cout << "Encontre un muro aqui o limite" << endl;           
            return Iniciar(x2, y2, true);
           
       }else{
       return Iniciar(x2, y2, false);
       }
       }
   }
 
}

int bresen::getx(){
    return x;

}
int bresen::gety(){
    return y;
}

