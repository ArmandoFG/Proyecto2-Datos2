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

using namespace std;

void Iniciar(int Bx1, int By1);

bresen::bresen() {
}

void bresen::Iniciar(int Bx1, int By1){
    //srand(time(NULL));
    int x;
    int y;
    int direccion = rand()%8;
   int map[10][10]={{0,0,0,0,1,0,0,0,1,0},
                     {0,0,0,0,1,0,0,0,1,0},
                     {0,0,0,0,0,0,0,0,1,0},
                     {0,0,0,0,0,0,1,1,1,0},
                     {0,0,1,0,0,0,0,0,0,0},
                     {0,0,1,0,0,1,1,0,0,0},
                     {0,0,1,0,0,0,1,0,0,0},
                     {0,0,1,0,1,0,1,0,0,0},
                     {0,0,1,0,1,0,0,0,0,0},
                     {0,0,1,1,1,1,1,0,0,5}};


   x=Bx1;

   y=By1;
 
   int x2;
   int y2;
   
   
   if(map[y][x] != 5){
       x2 = x;
       y2 = y;
       cout << direccion << endl;
       if(direccion == 0){
       if(map[y2][x2 + 1] == 0 || map[y2][x2 + 1] == 5){
           if(map[y2][x2 + 1] == 5){
               x2++;
               y2;
               cout << "Lo encontré" << endl;

               return Iniciar(x2, y2);
           }
           x2++;
           y2 = y;
           while(map[x2 + 1][y2] != 1){
               x2++;
               if(map[y2][x2] == 5){
               cout << "Lo encontré" << endl;
               return Iniciar(x2, y2);
           }
               cout << "Encontre un muro aqui" << endl;
           }
           
            return Iniciar(x2, y2);
           
       }else{
       return Iniciar(x2, y2);
       }
       }
       if(direccion == 1){
       if(map[y2 + 1][x2 + 1] == 0 || map[y2 + 1][x2 + 1] == 5){
           if(map[y2 + 1][x2 + 1] == 5){
               x2++;
               y2++;
               cout << "Lo encontré" << endl;
               return Iniciar(x2, y2);

           }
           x2++;
           y2++;
           while(map[y2 + 1][x2 + 1] != 1){
               x2++;
               y2++;
               if(map[y2][x2] == 5){
               cout << "Lo encontré" << endl;
               return Iniciar(x2, y2);

           }
               cout << "Encontre un muro" << endl;
           }
           
            return Iniciar(x2, y2);
           
       }else{
       return Iniciar(x2, y2);
       }
       }
       if(direccion == 2){
       if(map[y2 + 1][x2] == 0 || map[y2 + 1][x2] == 5){
           if(map[y2 + 1][x2] == 5){
               y2++;
               return Iniciar(x2, y2);
               cout << "Lo encontré" << endl;
           }
           y2++;
           while(map[y2 + 1][x2] != 1){
               y2++;
               if(map[y2][x2] == 5){
               return Iniciar(x2, y2);
               cout << "Lo encontré" << endl;
           }
               cout << "Encontre un muro" << endl;
           }
           
            return Iniciar(x2, y2);
           
       }else{
       return Iniciar(x2, y2);
       }
       }
       if(direccion == 3){
       if(map[y2 + 1][x2 - 1] == 0 || map[y2 + 1][x2 - 1] == 5){
           if(map[y2 + 1][x2 - 1] == 5){
               y2++;
               x2--;
               cout << "Lo encontré" << endl;
               return Iniciar(x2, y2);

           }
           y2++;
           x2--;
           while(map[y2 + 1][x2 - 1] != 1){
               y2++;
               x2--;
               if(map[y2][x2] == 5){
               cout << "Lo encontré" << endl;
               return Iniciar(x2, y2);

           }
               cout << "Encontre un muro" << endl;
           }
           
            return Iniciar(x2, y2);
           
       }else{
       return Iniciar(x2, y2);
       }
       }
       if(direccion == 4){
       if(map[y2][x2 - 1] == 0){
           if(map[y2][x2 - 1] == 5){
               x2--;
               cout << "Lo encontré" << endl;
               return Iniciar(x2, y2);

           }
           x2--;
           while(map[y2][x2 - 1] != 1){
                x2--;

               if(map[y2][x2] == 5){
               cout << "Lo encontré" << endl;
               return Iniciar(x2, y2);

           }
               cout << "Encontre un muro" << endl;
           }
           
            return Iniciar(x2, y2);
           
       }else{
       return Iniciar(x2, y2);
       }
       }
       if(direccion == 5){
       if(map[y2 - 1][x2 - 1] == 0){
           if(map[y2 - 1][x2 - 1] == 5){
               x2--;
               y2--;
               cout << "Lo encontré" << endl;
               return Iniciar(x2, y2);

           }
           y2--;
           x2--;
           while(map[y2 - 1][x2 - 1] != 1){
               y2--;
               x2--;
               if(map[y2][x2] == 5){
               cout << "Lo encontré" << endl;
               return Iniciar(x2, y2);

           }
               
               cout << "Encontre un muro" << endl;
           }
           
            return Iniciar(x2, y2);
           
       }else{
       return Iniciar(x2, y2);
       }
       }
       if(direccion == 6){
       if(map[y2 - 1][x2] == 0){
           if(map[y2 - 1][x2] == 5){
               y2--;
               cout << "Lo encontré" << endl;
               return Iniciar(x2, y2);

           }
           y2--;
           while(map[y2 - 1][x2] != 1){
                y2--;

               if(map[y2][x2] == 5){
               cout << "Lo encontré" << endl;
               return Iniciar(x2, y2);

           }
               cout << "Encontre un muro" << endl;
           }
           
            return Iniciar(x2, y2);
           
       }else{
       return Iniciar(x2, y2);
       }
       }
       if(direccion == 7){
       if(map[y2 - 1][x2 + 1] = 0){
           if(map[y2 - 1][x2 + 2] == 5){
               y2--;
               x2++;
               cout << "Lo encontré" << endl;
               return Iniciar(x2, y2);

           }
           y2--;
           x2++;
           while(map[y2 - 1][x2 + 1] != 1){
               y2--;
               x2++;
               if(map[y2][x2] == 5){
               cout << "Lo encontré" << endl;
               return Iniciar(x2, y2);

           }
               
               cout << "Encontre un muro" << endl;
           }
           
            return Iniciar(x2, y2);
           
       }else{
       return Iniciar(x2, y2);
       }
       }
   }
   cout << "Fue encontrado salga" << endl;
 
}

