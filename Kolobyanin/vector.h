#pragma once
#ifndef vectors
#define vectors
#include <iostream>
using namespace std;

class Vector
{
	int n;
	double* vec;
public:
	Vector(int n);
	Vector(const Vector& B);
	~Vector();
	void Generate(double min, double max);
	Vector& operator=(const Vector& B);
	Vector operator+(const Vector& B);
	Vector operator-(const Vector& B);
	Vector& operator+=(const Vector& B);
	Vector& operator-=(const Vector& B);
	double& operator[](const int i);
	Vector operator++(int k);
	Vector& operator++();
	Vector operator*(double r);
	friend ostream& operator<<(ostream& os, const Vector& B);
	friend istream& operator>>(istream& is, const Vector& B);
};
#endif