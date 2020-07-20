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

//Lista de la poblacion

struct poblacion
{
    int* individuo = new int[10];
    struct poblacion *sgte;
     struct atributos *ady;
     int* fitness = new int[10];
};

//Lista de los genes
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

/**
 * @brief Espectros iniciales
 * 
 */

void Genetico::Iniciar_Poblacion(){
    srand(time(NULL));
    int individuo;

    //Genes aleatorios de los espectros
    
    for(int i=0; i < individuos; i++){
        individuo = i;
        int gene1 = 1+rand()%3;
        int gene2 = 1+rand()%3;
        int gene3 = 2+rand()%2;
        int gene4 = rand()%3;
        int fitness = gene1 + gene2 + gene3 + gene4;
        insertar_individuo(individuo, fitness);
        insertar_atributo(gene1, individuo);
        insertar_atributo(gene2, individuo);
        insertar_atributo(gene3, individuo);
        insertar_atributo(gene4, individuo);
    }
}




/**
 * @brief Inserta el espectro
 * 
 * @param num Id del espectro
 * @param fit fitness del espectro
 */


void Genetico::insertar_individuo(int num, int fit)
{
    Tnodo t,nuevo=new struct poblacion;

    *nuevo->individuo = num;    
    *nuevo->fitness = fit;
    nuevo->sgte = NULL;
    nuevo->ady=NULL;

    if(POBLACION==NULL) 
     {
        POBLACION = nuevo;  

      }
    else
     {
        t = POBLACION;  
        while(t->sgte!=NULL)
         {
            t = t->sgte;
          }
        //Se ingresa el nodo
        t->sgte = nuevo;

      }

 }

 /**
  * @brief Agrega los genes al espectro
  * 
  * @param aux Espectro
  * @param nuevo Genes 
  * @param Atbt Int
  */

void agrega_atributo(Tnodo &aux, Tatributo &nuevo, int *Atbt)
{
    Tatributo q;  
    if(aux->ady==NULL)
    {   aux->ady=nuevo;
        *nuevo->datos= *Atbt;

    } 
    else
    {   q=aux->ady;
        while(q->sgte!=NULL)
            q=q->sgte;
       
        q->sgte=nuevo;
        *nuevo->datos= *Atbt;


    }

}

/**
 * @brief Atributos de los espectros
 * 
 * @param ATRIBUTO  Genes
 * @param individuo Espectro
 */

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
    //Se recorre los nodos para verificar que existan y para agregarle los genes
    
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

/**
 * @brief Escoge a los dos mejores espectros
 * 
 */

void Genetico::seleccion(){

  Tnodo Temp = POBLACION;
  int fitness = *Temp->fitness;
   int pareja = 0; 
    
    //Compara el fitness de cada espectro

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

/**
 * @brief Crea al nuevo espectro
 * 
 */
void cruce(){
    srand(time(NULL));
    //Escoge al azar el numero de genes del padre y la madre
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
    
    //Calcula el fitness
    
    int fitness = Genes[0] + Genes[1] + Genes[2]+ Genes[3];

    //Agrega el nuevo individuo y elimina al mas debil
    modificar_Poblacion(Muerto, fitness, Genes[0], Genes[1], Genes[2], Genes[3]);

    
    
    


    
    
}

/**
 * @brief Agrega al nuevo espectro
 * 
 * @param muerto Espectro mas debil
 * @param fitness Fitnes del nuevo espectro
 * @param gen1 int gen
 * @param gen2 int gen
 * @param gen3 int gen
 * @param gen4int gen
 */

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
/**
 * @brief Agrega los nuevos genes del espectro
 * @param gen1 int gen
 * @param gen2 int gen
 * @param gen3 int gen
 * @param gen4 int gen
 * @param aux nodo espectro
 */
void Modificar_Atributo(int gen1,  int gen2, int gen3, int gen4, Tnodo &aux){
    Tatributo q;  
    
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


/**
 * @brief Obtener genes de los espectros
 * 
 * @param individuo id individuo
 * @param gen int gen
 * @return int 
 */

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
/**
 * @brief Muestra la población
 * 
 */
void Genetico::mostrar_poblacion()
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

