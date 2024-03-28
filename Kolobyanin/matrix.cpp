#include "matrix.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

Matrix::Matrix(int n, int m) : n(n), m(m)
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

Matrix::~Matrix()
{
	for (int i = 0; i < n; i++)
	{
		delete[] A[i];
	}
	delete[] A;
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
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			A[i][j] = a + (b - a) * (double)rand() / (double)RAND_MAX;
		}
	}
}

Matrix Matrix::operator+(const Matrix& B)
{
	Matrix s(n, m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			s.A[i][j] = A[i][j] + B.A[i][j];
		}
	}
	return s;
}

Matrix Matrix::operator-(const Matrix& B)
{
	Matrix r(n, m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			r.A[i][j] = A[i][j] - B.A[i][j];
		}
	}
	return r;
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
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++) 
		{
			A[i][j] = B.A[i][j];
		}
	}
	return *this;
}

Matrix& Matrix::operator+=(const Matrix& B)
{
	if (n == B.n && m == B.m)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				A[i][j] += B.A[i][j];
			}
		}
	}
	return *this;
}

Matrix& Matrix::operator-=(const Matrix& B)
{
	if (n == B.n && m == B.m)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				A[i][j] -= B.A[i][j];
			}
		}
	}
	return *this;
}

Matrix Matrix::operator*(const Matrix& B)
{
	Matrix k(n, B.m);
	if (m == B.n)
	{
		for (int i = 0;i < k.n;i++)
		{
			for (int j = 0;j < k.m;j++)
			{
				double q = 0.0;
				for (int k = 0;k < m;k++)
				{
					q += A[i][k] * B.A[k][j];
				}
				k.A[i][j] = q;
			}
		}
	}
	return k;
}

double& Matrix::operator()(const int i, const int j)
{
	return A[i][j];
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

istream& operator>>(istream& in, const Matrix& B)
{
	for (int i = 0; i < B.n; i++)
	{
		for (int j = 0; j < B.m; j++)
		{
			in >> B.A[i][j];
		}
	}
	return in;
}

