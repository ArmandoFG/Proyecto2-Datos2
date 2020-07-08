//
// Created by usuario on 10/6/20.
//

#ifndef VSCODEMEMORYLIB_TLIST_H
#define VSCODEMEMORYLIB_TLIST_H


#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "TNode.h"
#include <string>
using namespace std;
/**
 * Clase lista para valores string
 */
template <class T>
class TList
{
private:
    TNode<T> *first;
public:
    int largo;
    TList();
    TNode<T>* getFirst();
    TNode<T>* getNodoPos(int pos);
    TNode<T>* getNodoVal(T val);
    int getPos(T value);
    void addLast(T data);
    void deletePos(int pos);
    string printList();
};


#endif //VSCODEMEMORYLIB_TLIST_H