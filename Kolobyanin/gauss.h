#pragma once
using namespace std;
#ifndef VECMAT_H_
#define VECMAT_H
#include <iostream>
#include "matrixvector.h"

class Gauss
{
    Matrix* A;
    Vector* res;
    Vector* B;
    int status;
public:
    Gauss(Matrix* A, Vector* B, Vector* X) : status(0), A(A), B(B), res(X) {}
    void Solve();
    double Check();
    friend class Vector;
    friend class Matrix;
};
#endif