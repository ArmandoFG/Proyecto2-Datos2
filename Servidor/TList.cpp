//
// Created by usuario on 10/6/20.
//

#include "TList.h"
#include "Espectro.h"
#include "Raton.h"
#include "Chuchu.h"
#include "Ojo.h"

/**
 * Metodo constructor de la lista
 */
template <class T>
TList<T>::TList()
{
    first = nullptr;
    largo=0;
}
/**
 * Metodo que retorna el primer nodo de la lista
 * @return Primer nodo de la lista
 */
template <class T>
TNode<T>* TList<T>::getFirst()
{
    return this->first;
}
/**
 * Metodo que devuelve el nodo que contenga el valor dado
 * @param val Valor a buscar
 * @return Nodo que contiene el valor
 */
template <class T>
TNode<T>* TList<T>::getNodoVal(T val) {
    TNode<T> *present = this->first;
    while (present != nullptr) {
        if(present->getValue() == val)
            return present;
        else{
            present = present->next;
        }
    }
    return nullptr;
}
/**
 * Funcion para obtener el pos-esimo nodo de la lista
 * @param pos Posicion a buscar
 * @return Nodo de la lista
 */
template <class T>
TNode<T>* TList<T>::getNodoPos(int pos) {
    TNode<T> *present = this->first;
    int i=0;
    while (i != pos){
        present = present->next;
        i+=1;
    }
    return present;
}
/**
 * Funcion para obtener el indicie del nodo que contiene cierto valor
 * @param value Valor a buscar en la TList
 * @return Retorna un entero con la posicion del nodo buscado
 */
template <class T>
int TList<T>::getPos(T value) {
    TNode<T> *present = this->first;
    int i = 0;
    while (present != nullptr) {
        if(present->getValue() == value)
            return i;
        else{
            present = present->next;
            i+=1;
        }
    }
    return -1;
}
/**
 * Funcion para agregar un dato a la lista
 * @param data Dato a agregar
 */
template <class T>
void TList<T>::addLast(T data)
{
    if(this->first == nullptr){
        this->first = new TNode<T>(data);
        largo +=1;
    }
    else{
        TNode<T> *present =  this->first;
        while(present->next != nullptr){
            present = present->next;
        }
        present->next = new TNode<T>(data);
        largo +=1;
    }
}
/**
 * Funcion para eliminar una posicion de la lista
 * @param pos Posicion a eliminar
 */
template <class T>
void TList<T>::deletePos(int pos) {
    TNode<T> *temp1 = this->first;
    TNode<T> *temp2 = this->first->next;
    if(pos == 0){
        this->first = temp1->next;
        largo -=1;
    }
    else{
        int  i = 0;
        while (i != pos-1){
            temp1 = temp1->next;
            temp2 = temp2->next;
            i+=1;
        }
        TNode<T> *aux = temp2;
        if(pos<largo) {
            temp1->next = temp2->next;
        }else{
            temp1->next= nullptr;
        }

        delete aux;
        largo -=1;
    }
}
/**
 * Metodo para obtener string de la lista
 * @return String con toda la info de la lista
 */

template class TList<std::pair<int, int>>;
template class TList<std::pair<float, float>>;
template class TList<int>;
template class TList<float>;
template class TList<string>;
template class TList<Espectro*>;
template class TList<Chuchu*>;
template class TList<Ojo*>;
template class TList<Raton*>;

