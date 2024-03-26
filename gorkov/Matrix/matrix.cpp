#include <iostream>
#include "matrix.h"


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
			A[i][j] = 0.0;
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
	}
		n = B.n;
		m = B.m;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++) {
				A[i][j] = B.A[i][j];
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
	Matrix C(n, m);
	if ((n == B.n) && (m == B.m)) {
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++) {
				C.A[i][j]=A[i][j] + B.A[i][j];
			}
		}
	}
	return C;
}
Matrix Matrix::operator- (const Matrix& B) {
	Matrix C(n, m);
	if ((n == B.n) && (m == B.m)) {
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++) {
				C.A[i][j]=A[i][j]- B.A[i][j];
			}
		}
	}
	return C;
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
		Matrix C(n, B.m);
		C.Null();	
		if (m == B.n) {

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < B.m; j++) {
				for (int k = 0; k < m; k++) {
					C.A[i][j] += (B.A[k][j] * A[i][k]);

				}
			}
		}
	}
		return C;

}

double& Matrix::operator()(const int i, const int j) 
{
	return A[i][j];
}

const double& Matrix::operator()(const int i, const int j) const
{
	return A[i][j];
}


Matrix::~Matrix() {
	for (int i = 0; i < n; i++)
		delete A[i];
	delete[] A;
}

///////////////////////////////////////////////////////////////////////////////
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
		//vec[i] = rand() % 10;
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
	Vector c(size);
	if	(size == tor.size){
	for (int i = 0; i < size; i++) {
		c.vec[i] = vec[i] + tor.vec[i];
	} 
	}
	return c;
}
Vector Vector::operator+=(const Vector& tor) {
	if (size == tor.size) {
		for (int i = 0; i < size; i++)
			vec[i] += tor.vec[i];
	}
	return *this;
}

Vector Vector::operator-(const Vector& tor) {
	Vector c(size);
	if (size == tor.size) {
		for (int i = 0; i < size; i++) {
			c.vec[i] = vec[i] - tor.vec[i];
		}
	}
	return c;
}

Vector Vector::operator-=(const Vector& tor) {
	if (size == tor.size) {
		for (int i = 0; i < size; i++)
			vec[i] -= tor.vec[i];
	}
	return *this;
}


ostream& operator << (ostream& os, const Vector& tor) {
	for (int i = 0; i < tor.size; i++) {
		os << tor.vec[i] << endl;
	}
	return os;
}

istream& operator >> (istream& input, Vector& tor) {
	for (int i = 0; i < tor.size; i++) {
		input >> tor.vec[i];
	}
	return input;
}

double& Vector::operator[](const int i) const
{
	return vec[i];
}

Vector Vector::operator++(int k) {
	Vector tmp(*this);
	for (int i = 0; i < size; i++)
		tmp.vec[i] = tmp.vec[i] + 1.0;
	return tmp;
}

Vector& Vector::operator++(){
	for (int i = 0; i < size; i++)
		vec[i] = vec[i] + 1.0;
	return *this;
}
