#pragma once
#include <iostream>
using namespace std;
class Matrix
{

	double** matrix;
	int rows, cols;

public:

	Matrix(int rows, int cols);
	Matrix(const Matrix& other);
	~Matrix();
	Matrix& operator =(const Matrix& other);
	Matrix operator +(const Matrix& other);
	Matrix operator -(const Matrix& other);
	Matrix operator +=(const Matrix& other);
	Matrix operator -=(const Matrix& other);
	double& operator ()(int index);
	Matrix operator *(const Matrix& other);
	void Generate(double min_, double max_);
	friend ostream& operator <<(ostream& osin, const Matrix& other);
	friend istream& operator >>(istream& isin, const Matrix& other);
};
