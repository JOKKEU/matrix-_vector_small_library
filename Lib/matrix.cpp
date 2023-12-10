#pragma once
#include "matrix.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <complex>

#define MAX_SIZE 4

using std::cout;
using std::endl;

Matrix::Matrix(const std::vector<std::vector<int>>& matrix) : matrix(matrix) {
    try {
        size_x = matrix.size();
        size_y = matrix[0].size();
    }
    catch (const std::runtime_error& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

unsigned int Matrix::getSize_x() const { return size_x; }
unsigned int Matrix::getSize_y() const { return size_y; }

int Matrix::getElement(int x, int y) {
    try {
        return matrix[x][y];
    }
    catch (const std::runtime_error& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

}

Matrix::Matrix(unsigned int size_x, unsigned int size_y) : size_x(size_x), size_y(size_y) {
    try {
        if (size_x > MAX_SIZE || size_x == 0 || size_y > MAX_SIZE || size_y == 0) {
            throw std::runtime_error("Invalid matrix size.");
        }
        matrix = std::vector<std::vector<int>>(size_x, std::vector<int>(size_y));
    }
    catch (const std::runtime_error& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

Matrix::Matrix(const Matrix& other) : size_x(other.size_x), size_y(other.size_y), matrix(other.matrix) {}
Matrix::~Matrix() = default;
Matrix Matrix::operator+(const Matrix& other) {
    try {

        if (size_x != other.size_x || size_y != other.size_y) {
            throw std::runtime_error("Matrix size mismatch in addition.");
        }
        Matrix result(size_x, size_y);
        for (unsigned int i = 0; i < size_x; ++i) {
            for (unsigned int j = 0; j < size_y; ++j) {
                result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
            }
        }
        return result;
    }
    catch (const std::runtime_error& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

Matrix Matrix::operator-(const Matrix& other) {
    try {

        if (size_x != other.size_x || size_y != other.size_y) {
            throw std::runtime_error("Matrix size mismatch in subtraction.");
        }
        Matrix result(size_x, size_y);
        for (unsigned int i = 0; i < size_x; ++i) {
            for (unsigned int j = 0; j < size_y; ++j) {
                result.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
            }
        }
        return result;
    }
    catch (const std::runtime_error& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, Matrix& matrix) {
    try {
        for (unsigned int i = 0; i < matrix.getSize_x(); ++i) {
            for (unsigned int j = 0; j < matrix.getSize_y(); ++j) {
                os << matrix.getElement(i, j) << "\t";
            }
            os << "\n";
        }
        return os;
    }
    catch (const std::runtime_error& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

Matrix Matrix::operator*(const Matrix& other) {
    try {

        if (size_y != other.size_x) {
            throw std::runtime_error("Number of columns in first matrix must be equal to the number of rows in the second matrix for multiplication.");
        }
        Matrix result(size_x, other.size_y);
        for (unsigned int i = 0; i < size_x; ++i) {
            for (unsigned int j = 0; j < other.size_y; ++j) {
                result.matrix[i][j] = 0;
                for (unsigned int k = 0; k < size_y; ++k) {
                    result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
                }
            }
        }
        return result;
    }
    catch (const std::runtime_error& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}
//нахожнение определителя матрицы
int Matrix::determinator() {
    try {

        int result;
        if (size_x != size_y) {
            throw std::runtime_error("matrix must be square!");
            return -999999999;
        }
        else {
            if (size_x == 2) {
                return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
            }
            else if (size_x == 3) {
                result =
                    matrix[0][0] * matrix[1][1] * matrix[2][2] +
                    matrix[0][1] * matrix[1][2] * matrix[2][0] +
                    matrix[0][2] * matrix[1][0] * matrix[2][1] -
                    matrix[0][2] * matrix[1][1] * matrix[2][0] -
                    matrix[0][0] * matrix[1][2] * matrix[2][1] -
                    matrix[0][1] * matrix[1][0] * matrix[2][2];
                return result;
            }
            else if (size_x == 4) {
                int A1, A2, A3, A4;

                A1 = matrix[0][0] * matrix[1][1] * matrix[2][2] +
                    matrix[0][1] * matrix[1][2] * matrix[2][3] +
                    matrix[0][2] * matrix[1][3] * matrix[2][1] -
                    matrix[0][2] * matrix[1][1] * matrix[2][3] -
                    matrix[0][1] * matrix[1][3] * matrix[2][2] -
                    matrix[0][0] * matrix[1][2] * matrix[2][1];

                A2 = matrix[0][0] * matrix[1][1] * matrix[2][2] +
                    matrix[0][1] * matrix[1][2] * matrix[2][3] +
                    matrix[0][2] * matrix[1][3] * matrix[2][0] -
                    matrix[0][2] * matrix[1][1] * matrix[2][3] -
                    matrix[0][1] * matrix[1][3] * matrix[2][2] -
                    matrix[0][0] * matrix[1][2] * matrix[2][1];

                A3 = matrix[0][0] * matrix[1][1] * matrix[2][2] +
                    matrix[0][1] * matrix[1][2] * matrix[2][3] +
                    matrix[0][2] * matrix[1][3] * matrix[2][0] -
                    matrix[0][2] * matrix[1][1] * matrix[2][3] -
                    matrix[0][1] * matrix[1][3] * matrix[2][2] -
                    matrix[0][0] * matrix[1][2] * matrix[2][1];

                A4 = matrix[0][0] * matrix[1][1] * matrix[2][2] +
                    matrix[0][1] * matrix[1][2] * matrix[2][3] +
                    matrix[0][2] * matrix[1][3] * matrix[2][3] -
                    matrix[0][2] * matrix[1][1] * matrix[2][3] -
                    matrix[0][1] * matrix[1][3] * matrix[2][2] -
                    matrix[0][0] * matrix[1][2] * matrix[2][3];

                return A1 + A2 + A3 + A4;
            }
        }
    }
    catch (const std::runtime_error& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}
// транспонировать матрицу
Matrix Matrix::transpose() {
    try {

        std::vector<std::vector<int>> temp(size_y, std::vector<int>(size_x));
        for (unsigned int i = 0; i < size_x; ++i) {
            for (unsigned int j = 0; j < size_y; ++j) {
                temp[j][i] = matrix[i][j];
            }
        }
        matrix = temp;
        std::swap(size_x, size_y);
        return matrix;
    }
    catch (const std::runtime_error& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void Matrix::printMatrix() {
    try {
        for (int i = 0; i < size_x; ++i) {
            for (int j = 0; j < size_y; ++j) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    catch (const std::runtime_error& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

}
//комплексное сопрежение (реальная часть)
Matrix Matrix::ConjugateTransposeReal() {
    Matrix result(size_y, size_x); 

    for (unsigned int i = 0; i < size_x; i++) {
        for (unsigned int j = 0; j < size_y; j++) {
            result.matrix[j][i] = static_cast<int>(std::real(matrix[i][j])); 
        }
    }

    return result;
}
//комплексное сопрежение (мнимая часть)
Matrix Matrix::ConjugateTransposeImag() {
    Matrix result(size_y, size_x);

    for (unsigned int i = 0; i < size_x; i++) {
        for (unsigned int j = 0; j < size_y; j++) {
            result.matrix[j][i] = static_cast<int>(std::imag(matrix[i][j])); 
        }
    }

    return result;
}


 