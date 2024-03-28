#include <iostream>
#include "Matrix.h"
#include <iomanip>
#include <ctime>
using namespace std;
matrix::matrix(int n_, int m_) : n(n_), m(m_)
{
    A = new double* [n];
    for (int i = 0; i < n; i++)
    {
        A[i] = new double[m];
        for (int j = 0; j < m; j++)
            A[i][j] = 0.0;
    }
}

matrix::matrix(const matrix& B) : n(B.n), m(B.m)
{
    A = new double* [n];
    for (int i = 0; i < n; i++)
    {
        A[i] = new double[m];
        for (int j = 0; j < m; j++)
            A[i][j] = B.A[i][j];
    }
}

matrix::~matrix()
{
    for (int i = 0; i < n; i++)
        delete[] A[i];
    delete[] A;
}

void matrix::set_random(double a, double b)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            A[i][j] = a + (b - a) * (double)rand() / (double)RAND_MAX;
        }
    }
}

void matrix::Print()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << setw(4) << A[i][j] << " ";
        }
        cout << endl;
    }
}

matrix matrix::plus(const matrix& B)
{
    matrix c(n, m);
    if (n == B.n && m == B.m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                c.A[i][j] = A[i][j] + B.A[i][j];
            }
        }
    }
    else
    {
        cout << "ERROR" << endl << "return NULL matrix" << endl;
    }
    return c;
}

matrix matrix::operator +(const matrix& B)
{
    matrix c(n, m);
    if (n == B.n && m == B.m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                c.A[i][j] = A[i][j] + B.A[i][j];
            }
        }
    }
    else
    {
        cout << "ERROR" << endl << "return NULL matrix" << endl;
    }
    return c;
}

matrix matrix::operator -(const matrix& B)
{
    matrix c(n, m);
    if (n == B.n && m == B.m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                c.A[i][j] = A[i][j] - B.A[i][j];
            }
        }
    }
    else
    {
        cout << "ERROR" << endl << "return NULL matrix" << endl;
    }
    return c;
}

matrix& matrix::operator = (const matrix& B)
{
    if (this == &B) return *this;
    if (n != B.n || m != B.m)
    {
        for (int i = 0; i < n; i++)
            delete[] A[i];
        delete[] A;
        A = new double* [B.n];
        for (int i = 0; i < n; i++)
            A[i] = new double[B.m];
        m = B.m;
        n = B.n;
    }
    for (int i = 0; i < n; i++)
    {
            for (int j = 0; j < m; j++)
            {
                A[i][j] = B.A[i][j];
            }
    }
    return *this;
}

matrix matrix::operator * (const matrix& B)
{
    matrix c(n, B.m);
    if (m == B.n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < B.m; j++)
            {
                double q = 0.0;
                for (int k = i; k < n - i; k++)
                {
                    q += A[i][j + k] * B.A[i + k][j];
                }
                c.A[i][j] = q;
            }
        }
    }
    else
    {
        cout << "ERROR" << endl << "return NULL matrix" << endl;
    }
    return c;
}

matrix& matrix::operator += (const matrix& B)
{
    if (n == B.n && m == B.m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                A[i][j] += B.A[i][j];
            }
        }
    }
    else
    {
        cout << "ERROR" << endl;
    }
    return *this;
}

matrix& matrix::operator -= (const matrix& B)
{
    if (n == B.n && m == B.m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                A[i][j] -= B.A[i][j];
            }
        }
    }
    else
    {
        cout << "ERROR" << endl;
    }
    return *this;
}


