#include "Matrix.h"
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <ctime>

using namespace std; 

Matrix::Matrix(int rows, int cols): rows(rows),cols(cols)
{
	matrix = new double* [rows];
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new double[cols];
		for (int j = 0; j < cols; j++)
			matrix[i][j] = 0.0;
	}
}
Matrix::Matrix(const Matrix& other): rows(other.rows),cols(other.cols)
{
	matrix = new double* [rows];
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new double[cols];
		for (int j = 0; j < cols; j++)
		{
			matrix[i][j] = other.matrix[i][j];
		}
	}
}
Matrix::~Matrix()
{
	for (int i = 0; i < rows; i++)
	{
		delete[] matrix[i];
		delete[] matrix;
	}

}
Matrix& Matrix:: operator=(const Matrix& other)
{
	if (this == &other)
	{
		return *this;
	}
	if ((rows != other.rows) || (cols != other.cols))
	{
		for (int i = 0; i < rows; i++)
		{
			delete[] matrix[i];
		}
		delete[] matrix;

		matrix = new double* [other.rows];
		for (int i = 0; i < other.rows; i++)
		{
			matrix[i] = new double[other.cols];
		}

		rows = other.rows;
		cols = other.cols;
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			matrix[i][j] = other.matrix[i][j];
		}
	}

	return *this;
}
Matrix Matrix:: operator+(const Matrix& other)
{
	Matrix tmp(rows, cols);
	if ((tmp.rows == other.rows) || (tmp.cols == other.cols))
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				tmp.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
			}
		}
	}
	return tmp;
}
Matrix Matrix:: operator-(const Matrix& other)
{
	Matrix tm(rows, cols);
	if ((tm.rows == other.rows) || (tm.cols == other.cols))
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				tm.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
			}
		}
	}
	return tm;
}
Matrix Matrix:: operator+=(const Matrix& other)
{
	if ((rows == other.rows) || (cols == other.cols))
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				matrix[i][j] = matrix[i][j] + other.matrix[i][j];
			}
		}
	}
	return *this;
}
Matrix Matrix:: operator-=(const Matrix& other)
{
	if ((rows == other.rows) || (cols == other.cols))
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				matrix[i][j] = matrix[i][j] - other.matrix[i][j];
			}
		}
	}
	return *this;
}
double& Matrix:: operator ()(int i, int j)
{
	return matrix[i][j];
}
Matrix Matrix:: operator*(const Matrix& other)
{
	if (cols = other.rows)
	{
		Matrix be(rows, other.cols);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < other.cols; j++)
			{
				double s = 0.0;
				for (int k = 0; k < cols; k++)
				{
					s = s + matrix[i][k] * other.matrix[k][j];
				}
				be.matrix[i][j] = s;
			}
		}
		return be;
	}
}
ostream& operator <<(ostream& osin, const Matrix& other)
{
	for (int i = 0; i < other.rows; i++)
	{
		for (int j = 0; j < other.cols; j++)
		{
			osin << other.matrix[i][j] << " ";
		}
		osin << endl;
	}
	return osin;
}
istream& operator >>(istream& isin, const Matrix& other)
{
	for (int i = 0; i < other.rows; i++)
	{
		for (int j = 0; j < other.cols; j++)
		{
			isin >> other.matrix[i][j];
		}
	}
	return isin;
}
void Matrix:: Generate(double min_, double max_)
{
	double min = min_;
	double max = max_;
	srand(time(NULL));
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			matrix[i][j] = 1. * (max - min) * rand() / RAND_MAX + min;
		}
	}
}





