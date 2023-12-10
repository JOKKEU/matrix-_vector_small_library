#pragma once

#ifndef MATRIX_H
#define MATRIX_H

#include "matrix.h"
#include <iostream>
#include <vector>

#define MAX_SIZE 4

class Matrix {
private:
    std::vector<std::vector<int>> matrix;
    unsigned int size_x;
    unsigned int size_y;
public:
    Matrix() = default;
    Matrix(const std::vector<std::vector<int>>& matrix);
    Matrix(unsigned int, unsigned int);
    ~Matrix();
    Matrix(const Matrix& other);
    //Matrix operator=(const Matrix& other);
    Matrix operator+(const Matrix& other);
    Matrix operator-(const Matrix& other);
    Matrix operator*(const Matrix& other);
    int getElement(int x, int y);
    unsigned int getSize_x() const;
    unsigned int getSize_y() const;
    int determinator();
    Matrix transpose();
    void printMatrix();
    Matrix ConjugateTransposeReal();
    Matrix ConjugateTransposeImag();
    
};

std::ostream& operator<<(std::ostream& os, Matrix& matrix);

#endif