using namespace std;
#include "matrixvector.h"
#include <iostream>
#include <cmath>

Matrix::Matrix(int n, int m) : n(n), m(m)
{
    A = new double* [n];
    for (int i = 0; i < n; i++)
    {
        A[i] = new double[m];
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            A[i][j] = 0.0;
        }
}

Matrix::~Matrix()
{
    for (int i = 0; i < n; i++)
    {
        delete[] A[i];
    }
    delete[] A;
}

Matrix::Matrix(const Matrix& B) : n(B.n), m(B.m)
{
    A = new double* [n];
    for (int i = 0; i < n; i++)
    {
        A[i] = new double[m];
        for (int j = 0; j < m; j++)
        {
            A[i][j] = B.A[i][j];
        }
    }
}

Matrix Matrix::operator=(const Matrix& B)
{
    if (this == &B)
    {
        return *this;
    }

    if ((n != B.n) || (m != B.m))
    {
        for (int i = 0; i < n; i++)
        {
            delete[] A[i];
        }
        delete[] A;

        A = new double* [B.n];
        for (int i = 0; i < B.n; i++)
        {
            A[i] = new double[B.m];
        }

        n = B.n;
        m = B.m;
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

Matrix Matrix::operator+(const Matrix& B)
{
    Matrix s(n, m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            s.A[i][j] = A[i][j] + B.A[i][j];
        }
    }
    return s;
}

Matrix Matrix::operator-(const Matrix& B)
{
    Matrix r(n, m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            r.A[i][j] = A[i][j] - B.A[i][j];
        }
    }
    return r;
}

Matrix& Matrix::operator+=(const Matrix& B)
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
    return *this;
}

Matrix& Matrix::operator-=(const Matrix& B)
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
    return *this;
}

Matrix Matrix::operator*(const Matrix& B)
{
    if (m == B.n)
    {
        Matrix z(n, B.m);

        double x = 0.0;
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < B.m; j++) 
            {
                for (int p = 0; p < m; p++) 
                {
                    x += A[i][p] * B.A[p][j];
                }
                z.A[i][j] = x;
                x = 0.0;
            }
        }
        return z;
    }
    else
        cout << "Error" << endl;
}

istream& operator>>(istream& in, Matrix& mat)
{
    int k, l;
    cout << "Vvedite razmer matrix: \n";
    in >> k >> l;
    mat = Matrix(k, l);
    for (int i = 0; i < mat.n; i++) 
    {
        cout << "Vvedite znachenie " << i + 1 << " stroki: \n";
        for (int j = 0; j < mat.m; j++) 
        {
            in >> mat.A[i][j];
        }
    }
    return in;
}

ostream& operator<<(ostream& os, const Matrix& mat)
{
    for (int i = 0; i < mat.n; i++) 
    {
        for (int j = 0; j < mat.m; j++) 
        {
            os << mat.A[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

double& Matrix::operator()(const int i, const int j) 
{
    return A[i][j];
}

const double& Matrix::operator()(const int i, const int j) const 
{
    return A[i][j];
}

void Matrix::swap(int row1, int row2)
{
    Matrix tmp(n, m);
    for (int i = 0; i < m; i++)
    {
        tmp.A[row1][i] = A[row1][i];
        A[row1][i] = A[row2][i];
        A[row2][i] = tmp.A[row1][i];
    }
}

void Matrix::generate(double min, double max) {
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            A[i][j] = min + (max - min) * ((double)rand() / double(RAND_MAX));
        }
    }
}

int Matrix::size()
{
    return n;
}

Vector operator*(const Matrix& B, const Vector& vec)
{
    if (B.m == vec.n1)
    {
        double elem = 0.0;
        Vector res(B.n);
        for (int i = 0; i < B.n; i++) {
            for (int j = 0; j < B.m; j++)
            {
                elem += vec.vec[j] * B.A[i][j];
            }
            res.vec[i] = elem;
            elem = 0.0;
        }
        return res;
    }
    else
        cout << "Error" << endl;

}

Vector::Vector(int size) : n1(size)
{
    vec = new double[size];
}

istream& operator>>(istream& in, Vector& vec)
{
    cout << "Vvedite razmer vectora: " << endl;
    in >> vec.n1;
    vec.vec = new double[vec.n1];
    cout << "Vvedite coordinati vectora: " << endl;
    for (int i = 0; i < vec.n1; i++)
    {
        in >> vec.vec[i];
    }
    return in;
}

ostream& operator<<(ostream& os, const Vector& vec)
{
    for (int i = 0; i < vec.n1; i++) 
    {
        os << vec.vec[i] << "\n";
    }
    return os;
}

Vector::Vector(const Vector& B)
{
    n1 = B.n1;
    vec = new double[n1];
    for (int i = 0; i < n1; i++)
    {
        vec[i] = B.vec[i];
    }
}

Vector Vector::operator=(const Vector& B)
{
    if (this == &B)
    {
        return *this;
    }
    if ((n1 != B.n1))
    {
        delete[] vec;
        vec = new double[B.n1];
        n1 = B.n1;
    }
    for (int i = 0; i < n1; i++)
    {
        vec[i] = B.vec[i];
    }
    return *this;
}

Vector Vector::operator+(const Vector& B)
{
    Vector vec_(n1);
    for (int i = 0; i < n1; i++)
    {
        vec_.vec[i] = vec[i] + B.vec[i];
    }
    return vec_;
}

Vector Vector::operator-(const Vector& B)
{
    Vector vec_(n1);
    for (int i = 0; i < n1; i++)
    {
        vec_.vec[i] = vec[i] - B.vec[i];
    }
    return vec_;
}


Vector& Vector::operator+=(const Vector& B)
{
    if (n1 != B.n1)
    {
        return *this;
    }
    for (int i = 0; i < n1; i++)
    {
        vec[i] += B.vec[i];
    }
    return *this;
}

Vector& Vector::operator-=(const Vector& B)
{
    if (n1 != B.n1)
    {
        return *this;
    }
    for (int i = 0; i < n1; i++)
    {
        vec[i] -= B.vec[i];
    }
    return *this;
}

Vector Vector::operator*(double r)
{
    Vector result(n1);
    for (int i = 0; i < n1; i++)
    {
        result.vec[i] = vec[i] * r;
    }
    return result;
}

Vector Vector::operator++(int k)
{
    Vector vec_(*this);
    for (int i = 0; i < n1; i++)
    {
        vec_.vec[i] += 1.0;
    }
    return vec_;
}

Vector& Vector::operator++()
{
    for (int i = 0; i < n1; i++)
    {
        vec[i] += 1.0;
    }
    return *this;
}

double& Vector::operator[](const int i) 
{
    return vec[i];
}

const double& Vector::operator[](const int i) const 
{
    return vec[i];
}

void Vector::generate(double min, double max) 
{
    for (int i = 0; i < n1; i++) 
    {
        vec[i] = min + (max - min) * ((double)rand() / double(RAND_MAX));
    }
}

double Vector::norma()
{
    double sum = 0.0;
    for (int i = 0; i < n1; i++) 
    {
        sum += vec[i] * vec[i];
    }
    return std::sqrt(sum);
}

Vector::~Vector()
{
    delete[] vec;
}