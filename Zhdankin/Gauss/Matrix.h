#pragma once
#ifndef MATRIX__
#define MATRIX__
#include "Vector.h"
#include <iostream>

using namespace std;

class Matrix
{
	int n;
	int m;
	double** A;
public:
	Matrix(int n, int m);
	Matrix(const Matrix& B);
	void Generate(double a, double b);
	int GetRowCount() const;
	
	~Matrix();

	friend ostream& operator<<(ostream& os, const Matrix& B);
	friend istream& operator>>(istream& is, const Matrix& B);

	Matrix& operator=(const Matrix& B);
	Matrix operator+(const Matrix& B);
	Matrix operator-(const Matrix& B);
	Matrix& operator+=(const Matrix& B);
	Matrix& operator-=(const Matrix& B);
	double& operator()(const int i, const int j);
	Matrix operator*(const Matrix& B);
	Vector operator*(const Vector& C);

	friend class Vector;
	friend class Gauss;
	
};
#endif