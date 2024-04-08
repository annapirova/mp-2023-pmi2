#pragma once
#ifndef VECMAT_H
#define VECMAT_H
using namespace std;
class Vector;

class Matrix {
private:
    int n, m;
    double** matrix;

public:
    Matrix(int row = 1, int col = 1); // конструктор
    Matrix(const Matrix& matr); // конструктор копирования
    ~Matrix(); // деструктор

    // Операторы
    Matrix operator+(const Matrix& matr);
    Matrix& operator+=(const Matrix& matr);
    Matrix operator-(const Matrix& matr);
    Matrix& operator-=(const Matrix& matr);
    Matrix operator*(Matrix& matr);
    Matrix& operator=(const Matrix& matr);
    double& operator()(int i, int j);
    const double& operator()(int i, int j) const;

    // Функции
    int GetN() const { return n; };
    int GetM() const { return m; };

    friend class Gauss;
    friend ostream& operator<<(ostream& os, const Matrix& matr);
    friend istream& operator>>(istream& os, Matrix& matr);
    friend Vector operator*(Matrix& matr, Vector& vect);
};

class Vector {
private:
    double* vect;
    int len;

public:
    Vector(int N = 1); // конструктор
    Vector(const Vector& v); // конструктор копирования
    ~Vector(); // деструктор

    // Операторы
    Vector operator+(const Vector& v);
    Vector operator-(const Vector& v);
    Vector& operator+=(const Vector& v);
    Vector& operator-=(const Vector& v);
    Vector operator*(double a);
    Vector& operator=(const Vector& v);
    double& operator()(int i);
    const double& operator()(int i) const;
    double Norm() const; // Вычисление нормы вектора

    // Функции
    friend Vector operator*(Matrix& matr, Vector& vect);
    friend ostream& operator<<(ostream& os, const Vector& vect);
    friend istream& operator>>(istream& in, Vector& V);
};
#endif
