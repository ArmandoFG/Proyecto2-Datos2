/* 
 * File:   Operaciones_Json.cpp
 * Author: arman
 * 
 * Created on 6 de julio de 2020, 06:58 PM
 */

#include "Operaciones_Json.h"
#include <iostream>
#include <fstream>
#include "string.h" 
#include <string.h>
#include <stdio.h>
#include <jsoncpp/json/reader.h>
#include <jsoncpp/json/json.h>
#include <jsoncpp/json/writer.h>

using namespace std;

Operaciones_Json::Operaciones_Json() {
}

string Operaciones_Json::read(int fila,string dato){
    ifstream ifs("datos.json");   
    Json::Value read_obj;      
    Json::Reader reader;
    reader.parse(ifs, read_obj);    
    string Dato;
    Dato = read_obj[fila][dato].asString();  
    return Dato;
}
void Operaciones_Json::WRITE(int fila, string dato, string valor){
    ifstream ifs("datos.json");
    Json::Reader reader;
    Json::Value obj;
    reader.parse(ifs, obj); 
    ifs.close();
    obj[fila][dato]= valor;
    Json::FastWriter SW;
    ofstream OS;
    OS.open("datos.json");
    OS << SW.write(obj);
    OS.close();

    
}

