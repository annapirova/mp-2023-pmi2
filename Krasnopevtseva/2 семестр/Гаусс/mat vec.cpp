using namespace std;
#include "matrix&vector.h"
#include <iostream>
#include <cmath>

matrix::matrix(int n_, int m_) : n(n_), m(m_)
{
    mem = new double* [n];
    for (int i = 0; i < n; i++)
        mem[i] = new double[m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            mem[i][j] = 0.0;
}
matrix::~matrix()
{
    for (int i = 0; i < n; i++)
        delete[] mem[i];
    delete[] mem;
}
matrix::matrix(const matrix& B) : n(B.n), m(B.m)
{
    mem = new double* [n];
    for (int i = 0; i < n; i++)
        mem[i] = new double[m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            mem[i][j] = B.mem[i][j];
}
matrix matrix::operator=(const matrix& B)
{
    if (this == &B)
        return *this;
    if ((n != B.n) || (m != B.m))
    {
        for (int i = 0; i < n; i++)
        {
            delete[] mem[i];
        }
        delete[] mem;
        mem = new double* [B.n];
        for (int i = 0; i < B.n; i++)
        {
            mem[i] = new double[B.m];
        }
        n = B.n;
        m = B.m;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            mem[i][j] = B.mem[i][j];
        }
    }

    return *this;
}
matrix matrix::operator+(const matrix& B)
{
    matrix mat1(n, m);
    for (int i = 0; i < B.n; i++)
    {
        for (int j = 0; j < B.m; j++)
        {
            mat1.mem[i][j] = mem[i][j] + B.mem[i][j];
        }
    }
    return mat1;

}
matrix matrix::operator-(const matrix& B)
{
    matrix mat1(n, m);
    for (int i = 0; i < B.n; i++)
    {
        for (int j = 0; j < B.m; j++)
        {
            mat1.mem[i][j] = mem[i][j] - B.mem[i][j];
        }
    }
    return mat1;

}
matrix& matrix::operator+=(const matrix& B)
{
    if ((n == B.n) && (m == B.m)) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                mem[i][j] += B.mem[i][j];
            }
    }
    return *this;
}
matrix& matrix::operator-=(const matrix& B)
{
    if ((n == B.n) && (m == B.m)) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                mem[i][j] -= B.mem[i][j];
            }
    }
    return *this;
}
matrix matrix::operator*(const matrix& B)
{
    if (m == B.n)
    {
        matrix mat1(n, B.m);

        double elem = 0.0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < B.m; j++) {
                for (int p = 0; p < m; p++) {
                    elem += mem[i][p] * B.mem[p][j];
                }
                mat1.mem[i][j] = elem;
                elem = 0.0;
            }
        }
        return mat1;
    }
    else
        cout << "Некорректные размеры для *" << endl;
}

istream& operator>>(istream& in, matrix& mat)
{
    int k, l;
    cout << "Введите размер: число строк, столбцов \n";
    in >> k >> l;
    mat = matrix(k, l);
    for (int i = 0; i < mat.n; i++) {
        cout << "Введите значения " << i + 1 << " строки \n";
        for (int j = 0; j < mat.m; j++) {
            in >> mat.mem[i][j];
        }
    }
    return in;
}
ostream& operator<<(ostream& os, const matrix& mat)
{
    for (int i = 0; i < mat.n; i++) {
        for (int j = 0; j < mat.m; j++) {
            os << mat.mem[i][j] << " ";
        }
        os << endl;
    }
    return os;
}
double& matrix::operator()(const int i, const int j) {
    return mem[i][j];
}
const double& matrix::operator()(const int i, const int j) const {
    return mem[i][j];
}
void matrix::swapRows( int row1, int row2)
{
    matrix tmp(n,m);
        for (int i = 0; i < m; i++)
        {
            tmp.mem[row1][i] = mem[row1][i];
            mem[row1][i] = mem[row2][i];
            mem[row2][i] = tmp.mem[row1][i];
        }
}
void matrix::generate(double min, double max) {
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            mem[i][j] = min + (max - min) * ((double)rand() / double(RAND_MAX));
        }
    }
}
int matrix::GetSize()
{
    return n;
}
///vector/

vector operator*(const matrix& B, const vector& vec)
{
    if (B.m == vec.n1)
    {
        double elem = 0.0;
        vector res(B.n);
        for (int i = 0; i < B.n; i++) {
            for (int j = 0; j < B.m; j++)
            {
                elem += vec.mem1[j] * B.mem[i][j];
            }
            res.mem1[i] = elem;
            elem = 0.0;
        }
        return res;
    }
    else
        cout << "Некорректные размеры для * матрицы на вектор" << endl;

}
vector::vector(int size) : n1(size)
{
    mem1 = new double[size];
}
istream& operator>>(istream& in, vector& vec)
{
    cout << "Введите размер:" << endl;
    in >> vec.n1;
    vec.mem1 = new double[vec.n1];
    cout << "Введите координаты:" << endl;
    for (int i = 0; i < vec.n1; i++)
    {
        in >> vec.mem1[i];
    }
    return in;
}
ostream& operator<<(ostream& os, const vector& vec)
{
    for (int i = 0; i < vec.n1; i++) {
        os << vec.mem1[i] << "\n";
    }
    return os;
}
vector::vector(const vector& B) : n1(B.n1)
{
    mem1 = new double[n1];
    for (int i = 0; i < n1; i++) {
        mem1[i] = B.mem1[i];
    }
}
vector vector::operator=(const vector& B)
{
    if (this == &B) {
        return*this;
    }

    if (n1 != B.n1) {
        delete[] mem1;
        mem1 = new double[B.n1];
        n1 = B.n1;
    }

    for (int i = 0; i < n1; i++) {
        mem1[i] = B.mem1[i];
    }
    return *this;
}
vector vector::operator+(const vector& B)
{
    vector vec1(n1);
    for (int i = 0; i < n1; i++)
        vec1.mem1[i] = mem1[i] + B.mem1[i];
    return vec1;
}
vector vector::operator-(const vector& B)
{
    vector vec1(n1);
    for (int i = 0; i < n1; i++)
        vec1.mem1[i] = mem1[i] - B.mem1[i];
    return vec1;
}
vector& vector::operator+=(const vector& B)
{
    if (n1 < B.n1) {
        vector vec1(B.n1);
        vec1.mem1 = new double[B.n1];
        for (int i = 0; i < B.n1; i++)
            vec1.mem1[i] = 0;
        for (int i = 0; i < n1; i++)
            vec1.mem1[i] = mem1[i];
        for (int i = 0; i < B.n1; i++)
            vec1.mem1[i] += B.mem1[i];
        vector::operator=(vec1);
    }
    else {
        for (int i = 0; i < B.n1; i++)
            mem1[i] += B.mem1[i];
        return *this;
    }
}
vector& vector::operator-=(const vector& B)
{
    if (n1 < B.n1) {
        vector vec1(B.n1);
        vec1.mem1 = new double[B.n1];
        for (int i = 0; i < B.n1; i++)
            vec1.mem1[i] = 0;
        for (int i = 0; i < n1; i++)
            vec1.mem1[i] = mem1[i];
        for (int i = 0; i < B.n1; i++)
            vec1.mem1[i] -= B.mem1[i];
        vector::operator=(vec1);
    }
    else {
        for (int i = 0; i < B.n1; i++)
            mem1[i] -= B.mem1[i];
        return *this;
    }
}
vector vector::operator*(double number)
{
    vector vec1(n1);
    for (int i = 0; i < n1; i++)
    {
        vec1.mem1[i] = mem1[i] * number;
    }
    return vec1;
}
vector vector::operator++(int k)
{
    vector tmp(*this);
    for (int i = 0; i < n1; i++) {
        tmp.mem1[i] = tmp.mem1[i] + 1.0;
    }
    return tmp;
}
vector& vector::operator++()
{
    for (int i = 0; i < n1; i++)
        mem1[i] = mem1[i] + 1.0;
    return *this;
}
double& vector::operator[](const int i) {
    return mem1[i];
}
const double& vector::operator[](const int i) const {
    return mem1[i];
}
void vector::generate(double min, double max) {
    for (int i = 0; i < n1; i++) {
        mem1[i] = min + (max - min) * ((double)rand() / double(RAND_MAX));
    }
}
double vector::norma()
{
    double sum = 0.0;
    for (int i = 0; i < n1; i++ ) {
        sum += mem1[i]*mem1[i];
    }
    return std::sqrt(sum);
}
vector::~vector()
{
    delete[] mem1;
}