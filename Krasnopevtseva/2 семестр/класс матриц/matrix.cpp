#include "matrix.h"
#include <iostream>
using std::cout;
using std::endl;
matrix::matrix(int n_, int m_) : n(n_), m(m_)
{
	A = new double* [n];
	for (int i = 0; i < n; i++)
		A[i] = new double[m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			A[i][j] = 0.0;
}
matrix::~matrix()
{
	for (int i = 0; i < n; i++)
		delete[] A[i];
	delete[] A;
}
matrix::matrix(const matrix& B) : n(B.n), m(B.n)
{
	A = new double * [n];
	for (int i = 0; i < n; i++)
		A[i] = new double[m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			A[i][j] = B.A[i][j];
}
