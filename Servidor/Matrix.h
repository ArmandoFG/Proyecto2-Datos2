//
// Created by brayan on 9/7/20.
//

#ifndef PROYECTO2_DATOS2_MATRIX_H
#define PROYECTO2_DATOS2_MATRIX_H


class Matrix {
private:
    static float xMin[4];
    static float yMin[4];
    static float xMax[4];
    static float yMax[4];
public:
    static const int SIZEY = 100;
    static const int SIZEX = 100;
    static int **generateMatrix1();
    static int **generateMatrix2();
    static int **generateMatrix3();
    static int **generateMatrix4();
    static int **generateMatrix5();
    static std::pair<float, float> toPoint(int x, int y, int matrixNumber);
    static std::pair<int, int> toMatrixPosition(float x, float y, int matrixNumber);
};


#endif //PROYECTO2_DATOS2_MATRIX_H
