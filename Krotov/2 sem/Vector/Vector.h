#pragma once
#include <iostream>
using namespace std;
class Vector
{
private:
	int Size;
public:
	double* vec;
	Vector(int Size);
	Vector(const Vector& other);
	Vector& operator =(const Vector& other);
	~Vector();
	Vector operator +(const Vector& other);
	Vector operator -(const Vector& other);
	Vector operator +=(const Vector& other);
	Vector operator -=(const Vector& other);
	double& operator [](int index);
	Vector operator *(const Vector& other);
	Vector operator ++(int temp);
	Vector operator ++();
	void Generate(double min_, double max_);

	friend ostream& operator <<(ostream& osin, const Vector& other);
	friend istream& operator >>(istream& isin, const Vector& other);
};

