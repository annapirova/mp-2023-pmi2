#pragma once
#include <iostream>
using namespace std;

class  Matrix
{
	int n, m;
	double** A;

public:
	Matrix(int n = 1, int m = 1);
	//double& operator()(const int i, const int j) const;
	~Matrix();
	Matrix(const Matrix& B);
	void Print();
	void Generate(int a, int b);
	void Null();
	Matrix& operator= (const Matrix& B);
	Matrix& operator+= (const Matrix& B);
	Matrix operator+ (const Matrix& B);
	Matrix operator- (const Matrix& B);
	Matrix& operator-= (const Matrix& B);
	Matrix operator* (const Matrix& B);
	double& operator()(const int i, const int j);
	const double& operator()(const int i, const int j) const;
	friend class Vector;
};

class Vector
{
	
	int size;
	double* vec;
public:
	Vector(int size = 1);
	void Print();
	void Genetate(int min, int max);
	Vector& operator= (const Vector& tor);
	Vector operator+ (const Vector& tor);
	Vector operator- (const Vector& tor);
	Vector operator+= (const Vector& tor);
	Vector operator-=(const Vector& tor);
	Vector operator++(int k);
	Vector& operator++();
	double& operator[](const int i) const;

	friend istream& operator>> (istream& input, Vector& tor);
	friend ostream& operator<< (ostream& os, const Vector& tor);
	~Vector();
	friend class Matrix;
};

