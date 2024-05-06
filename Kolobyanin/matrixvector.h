#pragma once
using namespace std;
#ifndef VECMAT_H_
#define VECMAT_H
#include <iostream>
class Matrix
{
private:
    double** A;
    int m, n;
public:
    Matrix(int m = 1, int n = 1);
    Matrix(const Matrix& B);
    ~Matrix();
    Matrix operator+(const Matrix& B);
    Matrix operator-(const Matrix& B);
    Matrix operator=(const Matrix& B);
    Matrix& operator+=(const Matrix& B);
    Matrix& operator-=(const Matrix& B);
    Matrix operator*(const Matrix& B);
    double& operator()(const int i, const int j);
    friend istream& operator>>(istream& in, Matrix& B);
    friend ostream& operator<<(ostream& os, const Matrix& B);
    void swap(int r1, int r2);
    void generate(double a, double b);
    friend class Vector;
    friend class gauss;
    friend Vector operator*(const Matrix& B, const Vector& vec);
    int size();
    const double& operator()(const int i, const int j) const;
};

class Vector
{
private:
    int n1;
    double* vec;
public:
    Vector(int n = 1);
    Vector(const Vector& B);
    ~Vector();
    Vector operator=(const Vector& B);
    Vector operator+(const Vector& B);
    Vector operator-(const Vector& B);
    Vector& operator+=(const Vector& B);
    Vector& operator-=(const Vector& B);
    Vector& operator++();
    Vector operator++(int k);
    Vector operator*(double number);
    double& operator[](const int i);
    const double& operator[](const int i) const;
    friend istream& operator>>(istream& in, Vector& B1);
    friend ostream& operator<<(ostream& os, const Vector& B1);
    void generate(double min, double max);
    double norma();
    friend class Matrix;
    friend class gauss;
    friend Vector operator*(const Matrix& B, const Vector& vec);
};
#endif