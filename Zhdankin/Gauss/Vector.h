#pragma once
#ifndef VECTOR__
#define VECTOR__
#include <iostream>

using namespace std;

class Vector
{
	int n;
	double* vec;
public:
	Vector(int n);
	Vector(const Vector& C);
	~Vector();

	void Generate(double a, double b);
	double GetSize() const;
	double GetElement(int index) const;
	double Norma();

	friend ostream& operator<<(ostream& osin, const Vector& C);
	friend istream& operator>>(istream& isin, const Vector& C);

	Vector& operator=(const Vector& C);
	Vector operator+(const Vector& C);
	Vector operator-(const Vector& C);
	Vector& operator+=(const Vector& C);
	Vector& operator-=(const Vector& C);
	double& operator[](const int i);
	Vector operator++(int);
	Vector& operator++();
	Vector operator*(const Vector& C);
};
#endif