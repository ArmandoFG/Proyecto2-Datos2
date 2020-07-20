/* 
 * File:   GENETICO.h
 * Author: arman
 *
 * Created on 25 de junio de 2020, 04:07 PM
 */

#ifndef GENETICO_H
#define	GENETICO_H

class Genetico
{
public:
    Genetico();
    void Iniciar_Poblacion();
    void insertar_individuo(int num, int fit);
    void insertar_atributo(int ATRIBUTO, int individuo);
    int retornarGen(int individuo, int gen);
    void seleccion();
    void mostrar_poblacion();
};

#endif // GENETICO_H





