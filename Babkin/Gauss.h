#pragma once
#include "matrix.h"
#include "vector.h"
#include <iostream>
#include <cstdlib>
using namespace std;
class Gauss
{
    private:
    matrix mtrx;
    vector result;
    int size,sizex;
    public:
    Gauss(matrix _mtrx, vector _result)
    {
        mtrx = _mtrx;
        result = _result;
    }
    Gauss (const Gauss &MOOTH)
    {
        mtrx = MOOTH.mtrx;
        result = MOOTH.result;
    }
    Gauss generate(const matrix &ms, const vector &rs)
    {
        for (int i = 0;i<ms.size;i++)
        {
            for (int j = 0;j<ms.sizex;j++)
            {
                ms(i,j) = rand()%1024;
            }
        }
        for (int p = 0; p < rs.size ; p++)
        {
            rs[p] = rand()%1024;
        }
    }
};