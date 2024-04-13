#pragma once
using namespace std;
#ifndef _SORT_H_
#define _SORT_H
#include <iostream>
#include "matrix&vector.h"

class Gauss
{
    matrix* A;
    vector* res;
    vector* b;
    int status;
public:
    Gauss(matrix* myA, vector* myb, vector* myx) : status(0), A(myA), b(myb), res(myx) {}
    void Solve();
    double Check();
    friend class vector;
    friend class matrix;
};
#endif // _SORT_H_