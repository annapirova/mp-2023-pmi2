#include "vector.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

void Vector::Generate(double min, double max)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		vec[i] = (rand() / (double)RAND_MAX) * (max - min) + min;
	}
}

Vector::Vector(int n_) : n(n_)
{
	vec = new double[n];

	for (int i = 0; i < n; i++)
	{
		vec[i] = 0.0;
	}
}

Vector::Vector(const Vector& B)
{
	n = B.n;
	vec = new double[n];
	for (int i = 0; i < n; i++)
	{
		vec[i] = B.vec[i];
	}
}

Vector::~Vector()
{
	delete[] vec;
}

Vector& Vector::operator=(const Vector& B)
{
	if (this == &B)
	{
		return *this;
	}
	if ((n != B.n))
	{
		delete[] vec;
		vec = new double[B.n];
		n = B.n;
	}
	for (int i = 0; i < n; i++)
	{
		vec[i] = B.vec[i];
	}
	return *this;
}

Vector Vector::operator+(const Vector& B)
{
	Vector vec_(n);
	for (int i = 0; i < n; i++)
	{
		vec_.vec[i] = vec[i] + B.vec[i];
	}
	return vec_;
}

Vector Vector::operator-(const Vector& B)
{
	Vector vec_(n);
	for (int i = 0; i < n; i++)
	{
		vec_.vec[i] = vec[i] - B.vec[i];
	}
	return vec_;
}

Vector& Vector::operator+=(const Vector& B)
{
	if (n != B.n)
	{
		return *this;
	}
	for (int i = 0; i < n; i++)
	{
		vec[i] += B.vec[i];
	}
	return *this;
}

Vector& Vector::operator-=(const Vector& B)
{
	if (n != B.n)
	{
		return *this;
	}
	for (int i = 0; i < n; i++)
	{
		vec[i] -= B.vec[i];
	}
	return *this;
}

double& Vector::operator[](const int i)
{
	return vec[i];
}

Vector Vector::operator*(double r)
{
	Vector result(n);
	for (int i = 0; i < n; i++)
	{
		result.vec[i] = vec[i] * r;
	}
	return result;
}

Vector Vector::operator++(int k)
{
	Vector vec_(*this);
	for (int i = 0; i < n; i++)
	{
		vec_.vec[i] += 1.0;
	}
	return vec_;
}

Vector& Vector::operator++()
{
	for (int i = 0; i < n; i++)
	{
		vec[i] += 1.0;
	}
	return *this;
}

ostream& operator<<(ostream& os, const Vector& B)
{
	for (int i = 0; i < B.n; i++)
	{
		os << B.vec[i];
		cout << endl;
	}
	return os;
}

istream& operator>>(istream& is, const Vector& B)
{
	for (int i = 0; i < B.n; i++)
	{
		is >> B.vec[i];
	}
	return is;
}