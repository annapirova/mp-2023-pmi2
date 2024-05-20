#pragma once
#ifndef MATRIX_H
#define MATRIX_H
using namespace std;

class matrix
{
private:
    double** A;
    int n, m;

public:
    matrix(int n = 1, int m = 1);
    matrix(const matrix& B);
    ~matrix();
    void set_random(double a, double b);
    void Print();
    matrix plus(const matrix& B);
    matrix operator + (const matrix& B);
    matrix operator - (const matrix& B);
    matrix operator * (const matrix& B);
    matrix& operator = (const matrix& B);
    matrix& operator += (const matrix& B);
    matrix& operator -= (const matrix& B);
};
#endif
