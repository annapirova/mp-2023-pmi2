#pragma once
#include <iostream>
#include <cstdlib>
#include <stdexcept>
using namespace std;

class Vector {
    double* values;
    int size;       

public:
    Vector(int s = 1);
    Vector(const Vector& other);
    ~Vector();
    Vector& operator=(const Vector& other);
    Vector& operator+=(const Vector& other);
    Vector& operator-=(const Vector& other);
    Vector operator+(const Vector& other) const;
    Vector operator-(const Vector& other) const;
    double& operator[](int i);
    int GiveSize() const;
    void Generate(double lg, double ug);
    void NullVector();
    friend std::ostream& operator<<(std::ostream& os, const Vector& vec);
    friend std::istream& operator>>(std::istream& is, Vector& vec);
};