//
// Created by brayan on 9/7/20.
//

#ifndef PROYECTO2_DATOS2_MATRIX_H
#define PROYECTO2_DATOS2_MATRIX_H


class Matrix {
public:
    static int **generateMatrix1();
    static int **generateMatrix2();
    static int **generateMatrix3();
    static int **generateMatrix4();
    static int **generateMatrix5();
    static std::pair<int, int> toPoint(int x, int y, int matrixNumber);
    static std::pair<int, int> toMatrixPosition(int x, int y, int matrixNumber);
};


#endif //PROYECTO2_DATOS2_MATRIX_H
