/* 
 * File:   Ojo.h
 * Author: arman
 *
 * Created on 1 de julio de 2020, 07:36 PM
 */

#ifndef OJO_H
#define	OJO_H

class Ojo {
public:
    Ojo(int ojo);
    void setPos(int x, int y);
    int GetPosX();
    int GetPosY();
    void movimiento();
    bool checkearVision();
private:
    int vision;
    bool vivo;
    int ojo;
    int posX{0};
    int posY{0};
public:
    int getOjo() const;

    void setOjo(int ojo);

public:
    bool isVivo() const;
    void setVivo(bool vivo);
};

#endif	/* OJO_H */

