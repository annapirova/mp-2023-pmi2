#pragma once
#ifndef VECMAT_H
#define VECMAT_H

#include <iostream>
#include <random>
#include <ctime>

class Vector;

class Matrix {
private:
    int n, m;
    double** matrix;

public:
    Matrix(int row = 1, int col = 1); 
    Matrix(const Matrix& matr); 
    ~Matrix(); 

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
    int Rows() const { return n; };
    int Cols() const { return m; };
    void RandomMatrix(double min, double max);
    friend class Gauss;
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matr);
    friend std::istream& operator>>(std::istream& os, Matrix& matr);
    friend Vector operator*(Matrix& matr, Vector& vect);
};

class Vector {
private:
    double* vect;
    int len;

public:
    Vector(int N = 1); // Конструктор
    Vector(const Vector& v); // Конструктор копирования
    ~Vector(); 

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

 
    friend Vector operator*(Matrix& matr, Vector& vect);
    friend std::ostream& operator<<(std::ostream& os, const Vector& vect);
    friend std::istream& operator>>(std::istream& in, Vector& V);
    void Generate(double min, double max);
    friend Vector operator*(Matrix& matr, Vector& vect);
};

#endif
