//
// Created by brayan on 6/7/20.
//

#ifndef PROYECTO2_DATOS2_FUEGO_H
#define PROYECTO2_DATOS2_FUEGO_H


class Fuego {
private:
    int x;
    int y;
    int dirx;
    int diry;
public:

    Fuego(int x, int y, int dirx, int diry);
    int getDirx() const;
    void setDirx(int dirx);
    int getDiry() const;
    void setDiry(int diry);
    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);

};


#endif //PROYECTO2_DATOS2_FUEGO_H
