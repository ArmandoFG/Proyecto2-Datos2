/* 
 * File:   bresen.h
 * Author: arman
 *
 * Created on 1 de julio de 2020, 09:09 AM
 */

#ifndef BRESEN_H
#define	BRESEN_H

class bresen {
public:
    bresen(int** map);
    void Iniciar(int Bx1, int By1, bool listo);
    int getx();
    int gety();

private:
    int** map;
};

#endif	/* BRESEN_H */

