#include <iostream>
#include<stdlib.h>
#include<time.h>
#include "GENETICO.h"
#include <sstream> 
#include "string.h" 
#include <string.h>
#include <stdio.h>
#include <stdio.h>



int individuos = 3;
int genes = 4;
int parejas = 2;

int Padre;
int Madre;
int Muerto;

double sumatoria = 0;




using namespace std;

struct poblacion
{
    int* individuo = new int[10];
    struct poblacion *sgte;
     struct atributos *ady;
     int* fitness = new int[10];
};
struct atributos{
    int* datos = new int[10];
    struct atributos *sgte;  
              
              };
              
typedef struct poblacion *Tnodo;
typedef struct poblacion *hijo;
typedef struct atributos *Tatributo;
typedef struct atributos *TatributoAux;

Tnodo POBLACION;
hijo Hijo;


Genetico::Genetico()
{

}

void Iniciar_Poblacion();
void insertar_atributo(int ATRIBUTO, int individuo);
void agrega_atributo(Tnodo &aux, Tatributo &nuevo, int *Atbt);
void mostrar_grafo();
void insertar_individuo(int num, int fit);
void seleccion();
void datos_hijo(int dato);
void cruce();
void Modificar_Atributo(int gen1,  int gen2, int gen3, int gen4, Tnodo &aux);
void modificar_Poblacion(int muerto, int fitness, int gen1,  int gen2, int gen3, int gen4);


void Genetico::Iniciar_Poblacion(){
    srand(time(NULL));
    int individuo;
    
    for(int i=0; i < individuos; i++){
        individuo = i;
        int gene1 = 1+rand()%4;
        int gene2 = 1+rand()%4;
        int gene3 = rand()%3;
        int gene4 = rand()%3;
        int fitness = gene1 + gene2 + gene3 + gene4;
        insertar_individuo(individuo, fitness);
        insertar_atributo(gene1, individuo);
        insertar_atributo(gene2, individuo);
        insertar_atributo(gene3, individuo);
        insertar_atributo(gene4, individuo);
    }
}






void Genetico::insertar_individuo(int num, int fit)
{
    Tnodo t,nuevo=new struct poblacion;

    *nuevo->individuo = num;    //Se le asigna el nombre del nodo al puntero
    *nuevo->fitness = fit;
    nuevo->sgte = NULL;
    nuevo->ady=NULL;

    if(POBLACION==NULL) //Si p es igual a nulo, no hay ningun nodo almacenado
     {
        POBLACION = nuevo;  // Se ingresa el nodo

      }
    else
     {
        t = POBLACION;  //Se le asigna el puntero a cabecera a t
        //Mientras el siguiente nodo de t sea diferente a null recorrera todos los nodos ecistentes
        while(t->sgte!=NULL)
         {
            t = t->sgte;
          }
        //Se ingresa el nodo
        t->sgte = nuevo;

      }

 }

void agrega_atributo(Tnodo &aux, Tatributo &nuevo, int *Atbt)
{
    Tatributo q;  //Arista auxiliar
    //Si el nodo no tiene arista la ingresa
    if(aux->ady==NULL)
    {   aux->ady=nuevo;
        *nuevo->datos= *Atbt;

    } // si no esta vac�a recorre todas las aristas hasta llegar a null
    else
    {   q=aux->ady;
        while(q->sgte!=NULL)
            q=q->sgte;
       
        q->sgte=nuevo;
        *nuevo->datos= *Atbt;


    }

}

void Genetico::insertar_atributo(int ATRIBUTO, int individuo)
{      
    int *Atbt = new int[2]; //Puntero del peso de la arista
    Tatributo nuevo=new struct atributos;    //Se crea la variable de la nueva arista
    Tnodo aux, aux2;

    //Si no hay nodos no puede ingresar la arista
    if(POBLACION==NULL)
     {

         return;
     }
    nuevo->sgte=NULL;
    
    *Atbt = ATRIBUTO;
    aux=POBLACION;
    aux2=POBLACION;
    //Se recorre los nodos para verificar que existan y para agregarle la arista
    
    while(aux!=NULL)
    {
        if(*aux->individuo==individuo)
        {
            agrega_atributo(aux, nuevo, Atbt);
           
            delete [] Atbt;
            return;
        }

        aux = aux->sgte;
    }
}


void Genetico::seleccion(){

  Tnodo Temp = POBLACION;
  int fitness = *Temp->fitness;
   int pareja = 0; 
  
       if(*Temp->fitness > *Temp->sgte->fitness){
           
           Padre = *Temp->individuo;
           
           pareja++;
           if(*Temp->sgte->fitness > *Temp->sgte->sgte->fitness){
               Madre = *Temp->sgte->individuo;
               Muerto = *Temp->sgte->sgte->individuo;
               pareja++;
           }else{
               Madre = *Temp->sgte->sgte->individuo;
               Muerto = *Temp->sgte->individuo;
               pareja++;
           }
       } 
       else{
           Padre = *Temp->sgte->individuo;
           pareja++;
           if(*Temp->fitness > *Temp->sgte->sgte->fitness){
               Muerto = *Temp->sgte->sgte->individuo;
               Madre = *Temp->individuo;
               pareja++;
           }else{
               Madre = *Temp->sgte->sgte->individuo;
               Muerto = *Temp->individuo;
               pareja++;
           }
       }

   cruce();
    
}

void cruce(){
    srand(time(NULL));
    int genPadre = rand()%5;
    int genMadre = 4 - genPadre;
    Tnodo ptr;
    Tatributo ar;
    ptr=POBLACION;
    int Genes[4];
    while(ptr!=NULL)
    {   
        if(*ptr->individuo == Padre){
            if(ptr->ady!=NULL)
            {
                Tatributo datos = ptr->ady;
                for(int i = 0; i < genPadre; i++){
                    Genes[i] = *datos->datos;
                    datos = datos->sgte;
                }

            }
           
    }
        ptr = ptr->sgte;
        
    }
   
    


    ptr=POBLACION;
    while(ptr!=NULL)
    {   
        if(*ptr->individuo == Madre){
            if(ptr->ady!=NULL)
            {
                Tatributo datos = ptr->ady;
                
                for(int i = 0; i < (genPadre + genMadre); i++){
                    
                    if(i >= genPadre){
                        Genes[i] = *datos->datos;
                    }
                    datos = datos->sgte;
                }

            }
           
    }
        ptr = ptr->sgte;
        
    }
    
    
    int fitness = Genes[0] + Genes[1] + Genes[2]+ Genes[3];
    modificar_Poblacion(Muerto, fitness, Genes[0], Genes[1], Genes[2], Genes[3]);

    
    
    


    
    
}

void modificar_Poblacion(int muerto, int fitness, int gen1,  int gen2, int gen3, int gen4){
    Tnodo ptr;
    Tatributo ar;
    ptr=POBLACION;
    
    while(*ptr->individuo!=muerto)
    {   
        ptr=ptr->sgte;  
    }
    *ptr->fitness = fitness;
    
    Modificar_Atributo(gen1, gen2, gen3, gen4, ptr);
   
    
}
void Modificar_Atributo(int gen1,  int gen2, int gen3, int gen4, Tnodo &aux){
    Tatributo q;  //Arista auxiliar
    //Si el nodo no tiene arista la ingresa
    
       q=aux->ady;
       int i = 1;
        while(q!=NULL){
            if (i == 1){
            *q->datos = gen1;
            }else if (i == 2){
            *q->datos = gen2;
            }else if (i == 3){
            *q->datos = gen3;
            }
            else if (i == 4){
            *q->datos = gen4;
            }
            i++;
            q=q->sgte;
        }
        


    
}




int Genetico::retornarGen(int individuo, int gen)
{   Tnodo ptr;
    Tatributo ar;
    ptr=POBLACION;
    int GEN;
    int contador = 0;
    while(ptr!=NULL)
    {   
        //cout<<"   "<<*ptr->individuo<<" Fitness:"<< *ptr->fitness << endl;
        if(*ptr->individuo == individuo){
            if(ptr->ady!=NULL)
            {
                ar=ptr->ady;
                while(ar!=NULL)
                {  

                    if(contador == gen){
                       GEN = *ar->datos;
                    }
                    //cout<<" "<<*ar->datos<< endl;
                    ar=ar->sgte;
                    contador++;
                }

            }
    }
    contador = 0;
        ptr=ptr->sgte;
        cout<<endl;
    }
    return GEN;
}
void Genetico::mostrar_grafo()
{   Tnodo ptr;
    Tatributo ar;
    ptr=POBLACION;
    cout<<"NODO|LISTA DE ADYACENCIA\n";

    while(ptr!=NULL)
    {   cout<<"   "<<*ptr->individuo<<" Fitness:"<< *ptr->fitness << endl;
        if(ptr->ady!=NULL)
        {
            ar=ptr->ady;
            while(ar!=NULL)
            {   cout<<" "<<*ar->datos<< endl;
                ar=ar->sgte;
             }

        }
        ptr=ptr->sgte;
        cout<<endl;
    }
}

