#pragma once
#include "Vector.h"

#include <iostream>
#include <cstdlib>
#include <stdexcept>

class Vector;

class Matrix {
    double** A;
    int row, col;

public:
    Matrix(int row = 1, int col = 1);
    Matrix(const Matrix& B);
    ~Matrix();
    Matrix Plus(const Matrix& B);
    Matrix operator+(const Matrix& B);
    Matrix operator-(const Matrix& B);
    Matrix& operator=(const Matrix& B);
    Matrix& operator+=(const Matrix& B);
    Matrix& operator-=(const Matrix& B);
    Matrix operator*(const Matrix& B);
    double& operator()(int i, int j);
    friend std::ostream& operator<<(std::ostream& os, const Matrix& B);
    friend std::istream& operator>>(std::istream& is, const Matrix& B);
    void Generate(double lg, double ug);
    void NullMatrix();
    Vector multiplyVector(Vector& v);
};

