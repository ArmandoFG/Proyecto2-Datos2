/* 
 * File:   Operaciones_Json.h
 * Author: arman
 *
 * Created on 6 de julio de 2020, 06:58 PM
 */

#include <iostream>
#include "string.h" 
#include <string.h>

#ifndef OPERACIONES_JSON_H
#define	OPERACIONES_JSON_H

using namespace std;

class Operaciones_Json {
public:
    Operaciones_Json();
    string read(int fila,string dato);
    void WRITE( int fila, string dato, string valor);

private:

};

#endif	/* OPERACIONES_JSON_H */

