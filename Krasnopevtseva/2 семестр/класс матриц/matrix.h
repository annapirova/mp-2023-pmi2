#pragma once
#ifndef _SORT_H_
#define _SORT_H

class matrix
{
private:
    double** A;
    int m,n;
public:
    matrix(int m_ = 1, int n = 1);
    matrix(const matrix &B);
    ~matrix();
};

#endif // _SORT_H_
