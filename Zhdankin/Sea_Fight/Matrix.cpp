#include "Matrix.h"
#include "Vector.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

Matrix::Matrix(int n) : n(n), m(n)
{
	A = new double* [n];
	for (int i = 0; i < n; i++)
	{
		A[i] = new double[m];
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			A[i][j] = 0.0;
		}
}

Matrix::Matrix(int n, int m): n(n), m(m)
{
	A = new double* [n];
	for (int i = 0; i < n; i++)
	{
		A[i] = new double[m];
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			A[i][j] = 0.0;
		}
}

Matrix::Matrix(const Matrix& B) : n(B.n), m(B.m)
{
	A = new double* [n];
	for (int i = 0; i < n; i++)
	{
		A[i] = new double[m];
		for (int j = 0; j < m; j++)
		{
			A[i][j] = B.A[i][j];
		}
	}
}

void Matrix::Generate(double a, double b)
{
	const long max_rand = 100000L;

	double lower_bound = a;
	double upper_bound = b;

	srand(time(NULL));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			double random_double = (double)rand() / (double)RAND_MAX * (upper_bound - lower_bound) + lower_bound;
			A[i][j] = random_double;
		}
	}
}

Matrix::~Matrix()
{
	for (int i = 0; i < n; i++)
	{
		delete[] A[i];
	}
	delete[] A;
}

void Matrix::Print()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
}

Matrix Matrix::operator+(const Matrix& B)
{
	Matrix C(n, m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			C.A[i][j] = A[i][j] + B.A[i][j];

	return C;
}

Matrix Matrix::operator-(const Matrix& B)
{
	Matrix C(n, m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			C.A[i][j] = A[i][j] - B.A[i][j];

	return C;
}

Matrix& Matrix::operator=(const Matrix& B)
{
	if (this == &B)
	{
		return *this;
	}

	if ((n != B.n) || (m != B.m))
	{
		for (int i = 0; i < n; i++)
		{
			delete[] A[i];
		}
		delete[] A;

		A = new double* [B.n];
		for (int i = 0; i < B.n; i++)
		{
			A[i] = new double[B.m];
		}

		n = B.n;
		m = B.m;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			A[i][j] = B.A[i][j];
		}
	}
	
	return *this;
}

Matrix& Matrix::operator+=(const Matrix& B)
{
	if ((n == B.n) && (m == B.m))
	{
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				A[i][j] += B.A[i][j];
			}
		}
	}
	else
	{
		cout << "error" << endl;
	}

	return *this;
}

Matrix& Matrix::operator-=(const Matrix& B)
{
	if ((n == B.n) && (m == B.m))
	{
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				A[i][j] -= B.A[i][j];
			}
		}
	}
	else
	{
		cout << "error" << endl;
	}

	return *this;
}

ostream& operator<<(ostream& os, const Matrix& B)
{
	for (int i = 0; i < B.n; i++)
	{
		for (int j = 0; j < B.m; j++)
		{
			os << B.A[i][j] << " ";
		}
		os << endl;
	}
	return os;
}

istream& operator>>(istream& is, const Matrix& B)
{
	for (int i = 0; i < B.n; i++)
	{
		for (int j = 0; j < B.m; j++)
		{
			is >> B.A[i][j];
		}
	}
	return is;
}

double& Matrix::operator()(const int i, const int j)
{
	return A[i][j];
}

Matrix Matrix::operator*(const Matrix& B)
{
	if ((m != B.n))
	{
		return Matrix(0,0);
	}

	Matrix tmp(n, B.m);

	for(int i = 0; i<n; i++)
		for (int j = 0; j < B.m; j++)
		{
			double sum = 0;
			for (int k = 0; k < m; k++)
			{
				sum += A[i][k] * B.A[k][j];
			}
			tmp.A[i][j] = sum;
		}
	return tmp;
}

/*Vector Matrix::operator*(const Vector& C)
{
	if (n != C.GetSize())
	{
		return Vector(0);
	}

	Vector result(m);

	for (int i = 0; i < m; i++)
	{
		double sum = 0;
		for (int j = 0; j < n; j++)
		{
			sum += A[i][j] * C.GetElement(j);
		}
		result[i] = sum;
	}

	return result;
}*/

int Matrix::GetValue(int x, int y) const {
	if (x >= 0 && x < 10 && y >= 0 && y < 10) {
		return A[y][x];
	}
	return -1; // invalid value to indicate out of bounds
}
int Matrix::GetRowCount() const
{
	return n;
}