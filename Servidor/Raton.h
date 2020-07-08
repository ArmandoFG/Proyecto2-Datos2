/* 
 * File:   Raton.h
 * Author: arman
 *
 * Created on 1 de julio de 2020, 07:38 PM
 */

#ifndef RATON_H
#define	RATON_H

class Raton {
public:
    Raton();
    void setPos(int x, int y);
    int GetPosX();
    int GetPosY();
    void movimiento();
    bool checkearVision(int x, int y, int vision);
};

#endif	/* RATON_H */

