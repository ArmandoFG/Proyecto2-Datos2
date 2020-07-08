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
#include "dist/json/json.h"
#include "dist/json/json-forwards.h"

using namespace std;

Operaciones_Json::Operaciones_Json() {
}

string Operaciones_Json::read(string individuo, string dato){
    ifstream ifs("datos.json");   
    Json::Value read_obj;      
    Json::Reader reader;
    reader.parse(ifs, read_obj);    
    string Dato;
    dato = read_obj[individuo][dato].asString();  
    return Dato;
}
void Operaciones_Json::WRITE(string individuo, string dato, string valor){
    Json::Value obj;    
    obj[individuo][dato]= valor; 
    Json::StyledWriter SW ;
    ofstream OS;
    OS.open("datos.json"); 
    OS << SW.write(obj);  
    OS.close();
}

