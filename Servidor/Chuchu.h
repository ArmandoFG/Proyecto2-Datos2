/* 
 * File:   Chuchu.h
 * Author: arman
 *
 * Created on 1 de julio de 2020, 07:03 PM
 */

#ifndef CHUCHU_H
#define	CHUCHU_H

class Chuchu {
public:
    Chuchu();
    explicit Chuchu(int chuchu, int**map, int x, int y);
    void setPos(int x, int y);
    bool isVivo() const;
    void setVivo(bool vivo);
    int GetPosX();
    int GetPosY();
    void movimiento();
    bool vivo{true};
private:
    int chuchu;
    int** map;
    int posX;
    int posY;
    int posXB;
    int posYB;
public:
    int getChuchu() const;

    void setChuchu(int chuchu);
};

#endif	/* CHUCHU_H */

