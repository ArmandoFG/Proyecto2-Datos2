//
// Created by brayan on 9/7/20.
//

#ifndef PROYECTO2_DATOS2_MATRIX_H
#define PROYECTO2_DATOS2_MATRIX_H

#include <utility>
using namespace std;

class Matrix {
private:
    static float xMin[5];
    static float yMin[5];
    static float xMax[5];
    static float yMax[5];
public:
    static const int SIZEY = 50;
    static const int SIZEX = 50;
    static int **generateMatrix1();
    static int **generateMatrix2();
    static int **generateMatrix3();
    static int **generateMatrix4();
    static int **generateMatrix5();
    static int **rutasMatrix1();
    static int **rutasMatrix2();
    static int **rutasMatrix3();
    static int **rutasMatrix4();
    static void print(int** matrix);
    static std::pair<float, float> toPoint(int x, int y, int matrixNumber);
    static std::pair<int, int> toMatrixPosition(float x, float y, int matrixNumber, int** matrix);

};


#endif //PROYECTO2_DATOS2_MATRIX_H
