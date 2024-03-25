#include "Vector.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::endl;

Vector::Vector(int n): n(n)
{
	vec = new double [n];

	for (int i = 0; i < n; i++)
	{
		vec[i] = 0.0;
	}
}

Vector::Vector(const Vector& C): n(C.n)
{
	vec = new double[n];
	for (int i = 0; i < n; i++)
	{
		vec[i] = C.vec[i];
	}
}

Vector::~Vector()
{
	delete[] vec;
}

Vector& Vector::operator=(const Vector& C)
{
	if (this == &C)
	{
		return *this;
	}

	if ((n != C.n))
	{
		delete[] vec;

		vec = new double[C.n];
		n = C.n;
	}
	for (int i = 0; i < n; i++)
	{
		vec[i] = C.vec[i];
	}

	return *this;
}

Vector Vector::operator+(const Vector& C)
{
	Vector tmp(n);
	for (int i = 0; i < n; i++)
	{
		tmp.vec[i] = vec[i] + C.vec[i];
	}
	return tmp;
}

Vector Vector::operator-(const Vector& C)
{
	Vector tmp(n);
	for (int i = 0; i < n; i++)
	{
		tmp.vec[i] = vec[i] - C.vec[i];
	}
	return tmp;
}

Vector& Vector::operator+=(const Vector& C)
{
	if (this == &C)
	{
		return *this;
	}

	if ((n != C.n))
	{
		delete[] vec;

		vec = new double[C.n];
		n = C.n;
	}
	for (int i = 0; i < n; i++)
	{
		vec[i] += C.vec[i];
	}

	return *this;
}

Vector& Vector::operator-=(const Vector& C)
{
	if (this == &C)
	{
		return *this;
	}

	if ((n != C.n))
	{
		delete[] vec;

		vec = new double[C.n];
		n = C.n;
	}
	for (int i = 0; i < n; i++)
	{
		vec[i] -= C.vec[i];
	}

	return *this;
}

double& Vector::operator[](const int i)
{
	return vec[i];
}

Vector Vector::operator*(const Vector& C)
{
	if ((n != C.n))
	{
		delete[] vec;

		vec = new double[C.n];
		n = C.n;
	}
	Vector result(n);

	for (int i = 0; i < n; i++)
	{
		result[i] = vec[i] * C.vec[i];
	}
	return result;
}

Vector Vector::operator++(int)
{
Vector tmp(*this);
	for (int i = 0; i < n; i++)
	{
		tmp.vec[i] += 1.0;
	}
	return tmp;
}

Vector& Vector::operator++()
{
	for (int i = 0; i < n; i++)
	{
		vec[i] += 1.0;
	}
	return *this;
}

void Vector::Generate(double a, double b)
{
	double min = a;
	double max = b;

	srand(time(NULL));

	for (int i = 0; i < n; i++)
	{
		vec[i] = (rand() / (double)RAND_MAX) * (max - min) + min;
	}
}

ostream& operator<<(ostream& osin, const Vector& C)
{
	for (int i = 0; i < C.n; i++)
	{
		osin << C.vec[i] << endl;
	}
	return osin;
}

istream& operator>>(istream& isin, const Vector& C)
{
	for (int i = 0; i < C.n; i++)
	{
		isin >> C.vec[i];
	}
	return isin;
}