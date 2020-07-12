//
// Created by usuario on 10/6/20.
//

#include "TNode.h"
#include "iostream"
#include "Chuchu.h"
#include "Raton.h"
#include "Ojo.h"
#include "Espectro.h"

using namespace std;
/**
 * Constructor del nodo
 */
template <class T>
TNode<T>::TNode()
{
    next = nullptr;
}

/**
 * Constructor de clase
 * @param data Dato para inicializar la clase
 */
template <class T>
TNode<T>::TNode(T data)
{
    next = nullptr;
    value = data;
}

/**
 * Metodo para obtener el valor guardado
 * @return string del valor guardado
 */
template <class T>
T TNode<T>::getValue()
{
    return  value;
}
/**
 * Metodo para cambiar el valor guardadp
 * @param data Nuevo valor a guardar
 */

template <class T>
void TNode<T>::setValue(T data) {
    this->value = data;
}


template class TNode<std::pair<int, int>>;
template class TNode<std::pair<float, float>>;
template class TNode<int>;
template class TNode<float>;
template class TNode<string>;
template class TNode<Espectro*>;
template class TNode<Raton*>;
template class TNode<Chuchu*>;
template class TNode<Ojo*>;
