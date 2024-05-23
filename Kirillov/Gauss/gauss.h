#pragma once

#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <cmath>
using namespace std;
class Vector {
    double* values;
    int size;
public:
    Vector(int s = 1);
    Vector(const Vector& other);
    ~Vector();
    Vector& operator=(const Vector& other);
    Vector& operator+=(const Vector& other);
    Vector& operator-=(const Vector& other);
    Vector operator+(const Vector& other) const;
    Vector operator-(const Vector& other) const;
    double& operator[](int i);
    int GiveSize() const;
    void Generate(double lg, double ug);
    void NullVector();
    friend std::ostream& operator<<(std::ostream& os, const Vector& vec);
    friend std::istream& operator>>(std::istream& is, Vector& vec);
};

class Matrix {
    double** A;
    int row, col;

public:
    Matrix(int row = 1, int col = 1);
    Matrix(const Matrix& B);
    ~Matrix();
    int getRow() const;
    int getCol() const;
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

class Gauss {
    Matrix* matrix;
    Matrix m_copy;
    Vector X;
    Vector* answer;

public:
    Gauss(Matrix& mat, Vector& ans);
    void transformToUpperTriangular();
    void solve();
    Vector getAnswer();
    Vector getAnswer2();
    Matrix getMCopy();
    int Check(Vector B,double cr);
};
