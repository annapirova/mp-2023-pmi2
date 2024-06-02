#include <iostream>
#include "matr_class.h"

// операторы

Matrix Matrix::operator+(const Matrix& matr) { // плюс
	Matrix NewMatr(matr.n, matr.m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			NewMatr.matrix[i][j] = this->matrix[i][j] + matr.matrix[i][j];
	return NewMatr;
}

Matrix& Matrix::operator+=(const Matrix& matr) { // прибавить и присвоить
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			matrix[i][j] += matr.matrix[i][j];
	return *this;
}

Matrix Matrix::operator-(const Matrix& matr) { // минус
	Matrix NewMatr(matr.n, matr.m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			NewMatr.matrix[i][j] = this->matrix[i][j] - matr.matrix[i][j];
	return NewMatr;
}

Matrix& Matrix::operator-=(const Matrix& matr) { // вычесть и присвоить
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			matrix[i][j] -= matr.matrix[i][j];
	return *this;
}

Matrix Matrix::operator*(Matrix& matr) { // умножение матрицы
	Matrix NewMatr(n, matr.m);
	for (int l = 0; l < n; l++)
		for (int i = 0; i < matr.m; i++) {
			matrix[l][i] = 0;
			for (int k = 0; k < matr.m; k++)
				NewMatr.matrix[l][i] += matrix[l][k] * matr.matrix[k][i];
		}
	return NewMatr;
}

Matrix& Matrix::operator=(const Matrix& matr) { // равно
	if (this == &matr) return *this;
	if (n != matr.n || m != matr.m) {
		n = matr.n; m = matr.m;
		matrix = new int* [n];
		for (int j = 0; j < n; j++)
			matrix[j] = new int[m];
	}

	for (int i = 0; i < n; i++) // создаём матрицу
		for (int j = 0; j < m; j++)
			matrix[i][j] = matr.matrix[i][j];
	return *this;
}

// функции 

void Matrix::matrFill() {
	//srand(time(NULL));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			matrix[i][j] = (rand() / static_cast<double>(RAND_MAX));
}
// конструктор

Matrix::Matrix(int row, int column) : n(row), m(column) {
	matrix = new int* [n];
	for (int j = 0; j < n; j++)
		matrix[j] = new int[m];
}

Matrix::Matrix(const Matrix& matr) : n(matr.n), m(matr.m) { // приравнивание матрицы
	matrix = new int* [n];
	for (int j = 0; j < n; j++)
		matrix[j] = new int[m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			matrix[i][j] = matr.matrix[i][j];
}

std::ostream& operator<<(std::ostream& os, const Matrix& matr) {
	for (int i = 0; i < matr.n; i++) {
		for (int j = 0; j < matr.m; j++) {
			os << matr.matrix[i][j] << " ";
		}
		os << std::endl;
	}
	return os;
}

std::istream& operator>>(std::istream& in, Matrix& matr) {
	int rw, clmn;
	std::cout << "Number of rows and columns: "; in >> rw >> clmn;
	matr = Matrix(rw, clmn);
	for (int i = 0; i < matr.n; i++) {
		std::cout << "Row num." << i << " values: ";
		for (int j = 0; j < matr.m; j++)
			in >> matr.matrix[i][j];
	}
	return in;
}