#pragma once
#ifndef MATRIX
#define MATRIX
#include <iostream>

using namespace std;

class Matrix
{
	double** A;
	int m, n;
public:
	Matrix(int n, int m);
	Matrix(const Matrix& B);
	void Generate(double a, double b);
	~Matrix();
	Matrix operator+(const Matrix& B);
	Matrix operator-(const Matrix& B);
	Matrix& operator=(const Matrix& B);
	Matrix& operator+=(const Matrix& B);
	Matrix& operator-=(const Matrix& B);
	Matrix operator*(const Matrix& B);
	double& operator()(const int i, const int j);
	friend ostream& operator<<(ostream& os, const Matrix& B);
	friend istream& operator>>(istream& in, const Matrix& B);
};
#endif
