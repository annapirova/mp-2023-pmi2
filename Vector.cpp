
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
class Vector
{
    int size;
    double* vec;
public:
    Vector(int size = 1);
    void Print();
    void Generate(int min, int max);
    Vector& operator=(const Vector& tor);
    Vector operator+(const Vector& tor);
    Vector operator-(const Vector& tor);
    Vector& operator+=(const Vector& tor);
    Vector& operator-=(const Vector& tor);
    Vector operator*(double scalar);
    double& operator[](int index);
    friend ostream& operator<<(ostream& os, const Vector& vec);
    friend istream& operator>>(istream& is, Vector& vec);
    double Norm();
    ~Vector();
};
Vector::Vector(int size) : size(size)
{
    vec = new double[size];
}

void Vector::Print()
{
    for (int i = 0; i < size; i++)
    {
        cout << vec[i] << endl;
    }
}

void Vector::Generate(int min, int max)
{
    for (int i = 0; i < size; i++)
    {
        vec[i] = min + (max - min) * ((double)rand() / double(RAND_MAX));
    }
}

Vector& Vector::operator=(const Vector& tor)
{
    if (this == &tor) return *this;
    if (size != tor.size)
    {
        delete[] vec;
        vec = new double[tor.size];
        size = tor.size;
    }
    for (int i = 0; i < size; i++)
    {
        vec[i] = tor.vec[i];
    }
    return *this;
}

Vector Vector::operator+(const Vector& tor)
{
    if (size != tor.size)
    {
        cout << "wrong len" << endl;
        return *this;
    }
    Vector result(size);
    for (int i = 0; i < size; i++)
    {
        result.vec[i] = vec[i] + tor.vec[i];
    }
    return result;
}

Vector Vector::operator-(const Vector& tor)
{
    if (size != tor.size)
    {
        cout << "wrong len" << endl;
        return *this;
    }
    Vector result(size);
    for (int i = 0; i < size; i++)
    {
        result.vec[i] = vec[i] - tor.vec[i];
    }
    return result;
}

Vector& Vector::operator+=(const Vector& tor)
{
    if (size != tor.size)
    {
        cout << "wrong len" << endl;
        return *this;
    }
    for (int i = 0; i < size; i++)
    {
        vec[i] += tor.vec[i];
    }
    return *this;
}

Vector& Vector::operator-=(const Vector& tor)
{
    if (size != tor.size)
    {
        cout << "wrong len" << endl;
        return *this;
    }
    for (int i = 0; i < size; i++)
    {
        vec[i] -= tor.vec[i];
    }
    return *this;
}

Vector Vector::operator*(double scalar)
{
    Vector result(size);
    for (int i = 0; i < size; i++)
    {
        result.vec[i] = vec[i] * scalar;
    }
    return result;
}

double& Vector::operator[](int index)
{
    return vec[index];
}

ostream& operator<<(ostream& os, const Vector& vec)
{
    for (int i = 0; i < vec.size; i++)
    {
        os << vec.vec[i] << " ";
    }
    return os;
}

istream& operator>>(istream& is, Vector& vec)
{
    for (int i = 0; i < vec.size; i++)
    {
        is >> vec.vec[i];
    }
    return is;
}

double Vector::Norm()
{
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += vec[i] * vec[i];
    }
    return sqrt(sum);
}

Vector::~Vector()
{
    delete[] vec;
}
int main() {
	int min, max;
	cout << "Enter min and max values: ";
	cin >> min >> max;
	Vector T(3), Y, X;
	T.Generate(min, max);
	Y = T;
	Y.Print();
	X = Y + T;  
	X.Print();
	return 0;
}
