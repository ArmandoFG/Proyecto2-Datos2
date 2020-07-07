//
// Created by brayan on 6/7/20.
//

#ifndef PROYECTO2_DATOS2_COFRE_H
#define PROYECTO2_DATOS2_COFRE_H


class Cofre {
private:
    int x;
    int y;
public:
    Cofre(int x, int y);

private:
    bool roto;
public:
    bool isRoto() const;
    void setRoto();

public:
    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);
};


#endif //PROYECTO2_DATOS2_COFRE_H
