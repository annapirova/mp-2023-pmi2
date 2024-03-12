#include <iostream>
#include <cstdio>
#include "matrix.h"
using namespace std;

Matrix::Matrix(int n, int m) :n(n), m(m)
{
	A = new double* [n];
	for (int i = 0; i < n; i++) {
		A[i] = new double[m];
	}
}
Matrix::Matrix(const Matrix& B) :n(B.n), m(B.m) {
	A = new double* [n];
	for (int i = 0; i < n; i++) {
		A[i] = new double[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) {
			A[i][j] = B.A[i][j];
		}
	}
}

void Matrix::Print() {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
}

void Matrix::Generate(int a, int b) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) {
			//A[i][j]=a+(b-a)*((double)rand()/double(RAND_MAX));
			A[i][j] = rand() % 10;
		}
	}

}
void Matrix::Null() {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) {
			A[i][j] = 0;
		}
	}

}

Matrix& Matrix::operator= (const Matrix& B) {
	if (this == &B) return *this;
	if ((n != B.n) || (m != B.m)) {
		for (int i = 0; i < n; i++) {
			delete A[i];
		}
		delete[] A;
		A = new double* [B.n];
		for (int i = 0; i < B.n; i++) {
			A[i] = new double[B.m];
		}
		n = B.n;
		m = B.m;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++) {
				A[i][j] = B.A[i][j];
			}
		}
	}
	return *this;
}

Matrix& Matrix::operator+= (const Matrix& B) {
	if ((n == B.n) && (m == B.m)) {
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++) {
				A[i][j] += B.A[i][j];
			}
		}
	}
	return *this;
}

Matrix Matrix::operator+ (const Matrix& B) {
	if ((n == B.n) && (m == B.m)) {
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++) {
				A[i][j] += B.A[i][j];
			}
		}
	}
	return *this;
}
Matrix Matrix::operator- (const Matrix& B) {
	if ((n == B.n) && (m == B.m)) {
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++) {
				A[i][j] -= B.A[i][j];
			}
		}
	}
	return *this;
}
Matrix& Matrix::operator-= (const Matrix& B) {
	if ((n == B.n) && (m == B.m)) {
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++) {
				A[i][j] -= B.A[i][j];
			}
		}
	}
	return *this;
}
Matrix Matrix::operator* (const Matrix& B) {
	if (m == B.n) {
		Matrix C(n, B.m);
		C.Null();
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < B.m; j++) {
				for (int k = 0; k < m; k++) {
					C.A[i][j] += (A[k][j] * B.A[i][k]);

				}
			}
		}
		for (int i = 0; i < n; i++)
			delete A[i];
		delete[] A;
		A = new double* [n];
		for (int i = 0; i < n; i++) {
			A[i] = new double[B.m];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < B.m; j++) {
				A[i][j] = C.A[i][j];
			}
		}
		
	}
	else cout << "wrong number of lines" << endl;
	return *this;
}
Matrix::~Matrix() {
	for (int i = 0; i < n; i++)
		delete A[i];
	delete[] A;
}

Vector::Vector(int op) :size(op)
{
	vec = new double[op];
}

void Vector::Print() {
	for (int i = 0; i < size; i++)
	{
		cout<<vec[i]<<endl;
	}
}

Vector::~Vector() {
	delete[] vec;
}

void Vector::Genetate(int min, int max) {
	for (int i = 0; i < size; i++) {
		vec[i] = min + (max - min) * ((double)rand() / double(RAND_MAX));
	}
}

Vector& Vector::operator=(const Vector& tor) {
	if (this == &tor) return *this;
	if (size != tor.size) {
		delete[] vec;
		vec = new double[tor.size];
		size = tor.size;
	}
	for (int i = 0; i < size; i++) {
		vec[i] = tor.vec[i];
	}
	return *this;
}

Vector Vector::operator+(const Vector& tor) {
	if (size != tor.size) {
		cout << "wrong len" << endl;
		return *this;
	}
	for (int i = 0; i < size; i++) {
		vec[i]=vec[i]+ tor.vec[i];
	}
	return *this;
}