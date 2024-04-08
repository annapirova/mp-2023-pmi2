#pragma once
#ifndef GAUSS_H
#define GAUSS_H
using namespace std;
#include "vecmat.h"

class Gauss {
private:
    Matrix* A;
    Vector* x;
    Vector* b;
    int status;

public:
    Gauss(Matrix* A, Vector* x, Vector* b);
    void solve();
    double Check();
};
#endif

