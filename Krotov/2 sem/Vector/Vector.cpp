#include "Vector.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
Vector::Vector(int Size): Size(Size)
{
	vec = new double[Size];
	for (int i = 0; i < Size; i++)
	{
		vec[i] = i;
	}
}
Vector::Vector(const Vector& other): Size(other.Size)
{
	
	vec = new double[Size];
	for (int i = 0; i < other.Size; i++)
	{
		vec[i] = other.vec[i];
	}
}
Vector& Vector:: operator =(const Vector& other)
{
	Size = other.Size;
	if (this == &other)
	{
		return *this;
	}

	if (vec != nullptr)
	{
		delete[] vec;

	}
	vec = new double[other.Size];

	for (int i = 0; i < other.Size; i++)
	{
		vec[i] = other.vec[i];
	}

	return *this;
}
Vector::~Vector()
{
	delete[] vec;
}
Vector Vector:: operator +(const Vector& other)
{
	Vector tmp(Size);
	if (tmp.Size == other.Size)
	{
		for (int i=0; i < Size; i++)
		{
			tmp.vec[i] = vec[i] + other.vec[i];
		}
	}
	
	return tmp;
}
Vector Vector:: operator -(const Vector& other)
{
	Vector tmp(Size);
	if (tmp.Size == other.Size)
	{
		for (int i=0; i < Size; i++)
		{
			tmp.vec[i] = vec[i] - other.vec[i];
		}
	}
	
	return tmp;
}
Vector Vector:: operator +=(const Vector& other)
{

	if (Size == other.Size)
	{
		for (int i=0; i < Size; i++)
		{
			vec[i] = vec[i] + other.vec[i];
		}
	}
	
	return *this;
}
Vector Vector:: operator -=(const Vector& other)
{

	if (Size == other.Size)
	{
		for (int i =0; i < Size; i++)
		{
			vec[i] = vec[i] - other.vec[i];
		}
	}
	else
	{
		cout << "Error: size1 != size2" << endl << "return NULL vector" << endl;
	}
	return *this;
}
double& Vector:: operator [](int index)
{
	return vec[index];
}
Vector Vector:: operator *(const Vector& other)
{
	if (Size != other.Size)
	{
		delete[] vec;
		vec = new double[other.Size];
		Size = other.Size;
	}
	Vector result(other);
	for (int i = 0; i < other.Size; i++)
	{
		result[i] = vec[i] * other.vec[i];
	}
	return result;
}
Vector Vector:: operator ++(int)
{
	Vector tmp(*this);
	{
		for (int i = 0; i < Size; i++)
		{
			vec[i] += 1.0;
		}
		return tmp;
	}
}
Vector Vector:: operator ++()
{
	for (int i = 0; i < Size; i++)
	{
		vec[i] += 1.0;
	}
	return *this;
}
void Vector::Generate(double min_, double max_)
{
	double min = min_;
	double max = max_;
	srand(time(NULL));
	for (int i = 0; i < Size; i++)
	{
		vec[i] = 1.*(max-min)*rand()/RAND_MAX + min;
	}
}
ostream& operator<<(ostream& osin, const Vector& other)
{
	for (int i = 0; i < other.Size; i++)
	{
		osin << other.vec[i] << endl;
	}
	return osin;
}
istream& operator>>(istream& isin, const Vector& other)
{
	for (int i = 0; i < other.Size; i++)
	{
		isin >> other.vec[i];
	}
	return isin;
}