#pragma once
using namespace std;
#ifndef _SORT_H_
#define _SORT_H
#include <iostream>
class matrix
{
private:
    double** mem;
    int m, n;
public:
    matrix(int m = 1, int n = 1);
    matrix(const matrix& B);
    ~matrix();
    matrix operator=(const matrix& B);
    matrix operator+(const matrix& B);
    matrix operator-(const matrix& B);
    matrix& operator+=(const matrix& B);
    matrix& operator-=(const matrix& B);
    matrix operator*(const matrix& B);
    int GetSize();
    double& operator()(const int i, const int j);
    const double& operator()(const int i, const int j) const;
    void swapRows(int row1, int row2);
    void generate(double min, double max);
    friend istream& operator>>(istream& in, matrix& mat);
    friend ostream& operator<<(ostream& os, const matrix& mat);
    friend class vector;
    friend class gauss;
    friend vector operator*(const matrix& B, const vector& vec);
};
class vector
{
private:
    int n1;
    double* mem1;
public:
    vector(int n = 1);
    vector(const vector& B);
    ~vector();
    vector operator=(const vector& B);
    vector operator+(const vector& B);
    vector operator-(const vector& B);
    vector& operator+=(const vector& B);
    vector& operator-=(const vector& B);
    vector& operator++();
    vector operator++(int k);
    vector operator*(double number);
    double& operator[](const int i);
    const double& operator[](const int i) const;
    friend istream& operator>>(istream& in, vector& vec);
    friend ostream& operator<<(ostream& os, const vector& vec);
    void generate(double min, double max);
    double norma();
    friend class matrix;
    friend class gauss;
    friend vector operator*(const matrix& B, const vector& vec);
};
#endif // _SORT_H_
