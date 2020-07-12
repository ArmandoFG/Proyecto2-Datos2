//
// Created by usuario on 10/6/20.
//

#ifndef VSCODEMEMORYLIB_TNODE_H
#define VSCODEMEMORYLIB_TNODE_H

#include <string>
using namespace std;
/**
 * Clase para guardar valores de una lista
 */

template <class T>
class TNode {
private:
    T value;
public:
    TNode *next;
    TNode();
    TNode(T value);
    T getValue();
    void setValue(T value);
};


#endif //VSCODEMEMORYLIB_TNODE_H
