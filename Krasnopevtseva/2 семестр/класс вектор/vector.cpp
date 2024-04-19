using namespace std;
#include "vector.h"
#include <iostream>
#include <locale.h>
#include <ctime>
vector::vector(int size): n(size)
{
    mem = new double[size];
}
istream& operator>>(istream& in, vector& vec)
{
    cout << "¬ведите размер:"<<endl;
    in >> vec.n;
    vec.mem = new double[vec.n];
    cout << "¬ведите координаты:"<<endl;
    for (int i = 0; i < vec.n; i++)
    {
        in >> vec.mem[i];
    }
    return in;
}
ostream& operator<<(ostream& os, const vector& vec) 
{
    for (int i = 0; i < vec.n; i++) {
        os << vec.mem[i] << "\n";
    }
    return os;
}
vector::vector(const vector& B) : n(B.n) 
{
    mem = new double[n];
    for (int i = 0; i < n; i++) {
        mem[i] = B.mem[i];
    }
}
vector vector::operator=(const vector& B) 
{
    if (this == &B) {
        return*this;
    }

    if (n != B.n) {
        delete[] mem;
        mem = new double[B.n];
        n = B.n;
    }

    for (int i = 0; i < n; i++) {
        mem[i] = B.mem[i];
    }
    return *this;
}
vector vector::operator+(const vector& B)
{
    vector vec1(n);
    for (int i = 0; i < n; i++)
        vec1.mem[i] = mem[i] + B.mem[i];
        return vec1;
}
vector vector::operator-(const vector& B)
{
    vector vec1(n);
    for (int i = 0; i < n; i++)
        vec1.mem[i] = mem[i] - B.mem[i];
    return vec1;
}
vector& vector::operator+=(const vector& B)
{
    if (n < B.n) {
        vector vec1(B.n);
        vec1.mem = new double[B.n];
        for (int i = 0; i < B.n; i++) 
            vec1.mem[i] = 0;
        for (int i = 0; i < n; i++)
            vec1.mem[i] = mem[i];
        for (int i = 0; i < B.n; i++) 
            vec1.mem[i] += B.mem[i];
        vector::operator=(vec1);
    }
    else {
        for (int i = 0; i < B.n; i++) 
            mem[i] += B.mem[i];
        return *this;
    }
}
vector& vector::operator-=(const vector& B)
{
    if (n < B.n) {
        vector vec1(B.n);
        vec1.mem = new double[B.n];
        for (int i = 0; i < B.n; i++)
            vec1.mem[i] = 0;
        for (int i = 0; i < n; i++)
            vec1.mem[i] = mem[i];
        for (int i = 0; i < B.n; i++)
            vec1.mem[i] -= B.mem[i];
        vector::operator=(vec1);
    }
    else {
        for (int i = 0; i < B.n; i++)
            mem[i] -= B.mem[i];
        return *this;
    }
}
vector vector::operator*(double number)
{
    vector vec1(n);
    for (int i = 0; i < n; i++)
    {
        vec1.mem[i] = mem[i] * number;
    }
    return vec1;
}
vector vector::operator++(int k)
{
    vector tmp(*this);
    for (int i = 0; i < n; i++) {
        tmp.mem[i] = tmp.mem[i] + 1.0;
    }
    return tmp;
}
vector& vector::operator++()
{
    for (int i = 0; i < n; i++)
        mem[i] = mem[i] + 1.0;
    return *this;
}
double& vector::operator[](const int i) {
    return mem[i];
}
const double& vector::operator[](const int i) const {
    return mem[i];
}
void vector::generate(double min, double max) {
    for (int i = 0; i < n; i++) {
        mem[i] = min + (max - min) * ((double)rand() / double(RAND_MAX));
    }
}
vector::~vector()
{
    delete[] mem;
}
