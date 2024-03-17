using namespace std;
#include <iostream>
#include "matrix.h"
#include <locale.h>
#include <random>
#include <ctime>


Matrix::Matrix(int n_, int m_) : n(n_), m(m_) {
	Memory = new double* [n];
	for (int i = 0; i < n; i++) {
		Memory[i] = new double [m];
	}
}


Matrix::~Matrix() {
	for (int i = 0; i < n; i++) {
		delete[] Memory[i];
	}
	delete[] Memory;
}


Matrix::Matrix(const Matrix& B) : n(B.n), m(B.m) {
	Memory = new double* [n];
	for (int i = 0; i < n; i++) {
		Memory[i] = new double[m];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			Memory[i][j] = B.Memory[i][j];
		}
	}
}


Matrix Matrix::operator+(const Matrix& B) {
	if ((n < B.n) || (m < B.m)) {
		Matrix New_Matrix(B.n, B.m);
		//Выделяем память под новую матрицу
		New_Matrix.Memory = new double* [B.n];
		for (int i = 0; i < B.n; i++) {
			New_Matrix.Memory[i] = new double[B.m];
		}
		//Заполняем нулями
		for (int i = 0; i < B.n; i++) {
			for (int j = 0; j < B.m; j++) {
				New_Matrix.Memory[i][j] = 0;
			}
		}
		//Переносим данные из меньшей матрицы
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				New_Matrix.Memory[i][j] = Memory[i][j];
			}
		}
		//Складываем и возвращаем итоговую матрицу
		for (int i = 0; i < B.n; i++) {
			for (int j = 0; j < B.m; j++) {
				New_Matrix.Memory[i][j] += B.Memory[i][j];
			}
		}
		n = B.n;
		m = B.m;
		return New_Matrix;
	}
	else {
		for (int i = 0; i < B.n; i++) {
			for (int j = 0; j < B.m; j++) {
				Memory[i][j] += B.Memory[i][j];
			}
		}
		return *this;
	}
}


Matrix &Matrix::operator=(const Matrix& B) {
	if (this == &B) {
		return* this;
	}

	if ((n != B.n) || (m != B.m)) {
		for (int i = 0; i < n; i++) {
			delete[] Memory[i];
		}
		delete[] Memory;
		Memory = new double* [B.n];
		for (int i = 0; i < B.n; i++) {
			Memory[i] = new double[B.m];
		}
		n = B.n;
		m = B.m;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			Memory[i][j] = B.Memory[i][j];
		}
	}
	return *this;
}


Matrix Matrix::operator-(const Matrix& B) {
	if ((n < B.n) || (m < B.m)) {
		Matrix New_Matrix(B.n, B.m);
		//Выделяем память под новую матрицу
		New_Matrix.Memory = new double* [B.n];
		for (int i = 0; i < B.n; i++) {
			New_Matrix.Memory[i] = new double[B.m];
		}
		//Заполняем нулями
		for (int i = 0; i < B.n; i++) {
			for (int j = 0; j < B.m; j++) {
				New_Matrix.Memory[i][j] = 0;
			}
		}
		//Переносим данные из меньшей матрицы
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				New_Matrix.Memory[i][j] = Memory[i][j];
			}
		}
		//Складываем и возвращаем итоговую матрицу
		for (int i = 0; i < B.n; i++) {
			for (int j = 0; j < B.m; j++) {
				New_Matrix.Memory[i][j] -= B.Memory[i][j];
			}
		}
		return New_Matrix;
	}
	else {
		for (int i = 0; i < B.n; i++) {
			for (int j = 0; j < B.m; j++) {
				Memory[i][j] -= B.Memory[i][j];
			}
		}
		return *this;
	}
}


Matrix &Matrix::operator+=(const Matrix& B){
	if ((n < B.n) || (m < B.m)){
		Matrix New_Matrix(B.n, B.m);
		//Выделяем память под новую матрицу
		New_Matrix.Memory = new double* [B.n];
		for (int i = 0; i < B.n; i++) {
			New_Matrix.Memory[i] = new double[B.m];
		}
		//Заполняем нулями
		for (int i = 0; i < B.n; i++) {
			for (int j = 0; j < B.m; j++) {
				New_Matrix.Memory[i][j] = 0;
			}
		}
		//Переносим данные из меньшей матрицы
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				New_Matrix.Memory[i][j] = Memory[i][j];
			}
		}
		//Складываем и возвращаем итоговую матрицу
		for (int i = 0; i < B.n; i++) {
			for (int j = 0; j < B.m; j++) {
				New_Matrix.Memory[i][j] += B.Memory[i][j];
			}
		}
		Matrix::operator=(New_Matrix);
	}
	else {
		for (int i = 0; i < B.n; i++) {
			for (int j = 0; j < B.m; j++) {
				Memory[i][j] += B.Memory[i][j];
			}
		}
		return *this;
	}
	
}

 
Matrix& Matrix::operator-=(const Matrix& B) {
	if ((n < B.n) || (m < B.m)) {
		Matrix New_Matrix(B.n, B.m);
		//Выделяем память под новую матрицу
		New_Matrix.Memory = new double* [B.n];
		for (int i = 0; i < B.n; i++) {
			New_Matrix.Memory[i] = new double[B.m];
		}
		//Заполняем нулями
		for (int i = 0; i < B.n; i++) {
			for (int j = 0; j < B.m; j++) {
				New_Matrix.Memory[i][j] = 0;
			}
		}
		//Переносим данные из меньшей матрицы
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				New_Matrix.Memory[i][j] = Memory[i][j];
			}
		}
		//Складываем и возвращаем итоговую матрицу
		for (int i = 0; i < B.n; i++) {
			for (int j = 0; j < B.m; j++) {
				New_Matrix.Memory[i][j] -= B.Memory[i][j];
			}
		}
		Matrix::operator=(New_Matrix);
	}
	else {
		for (int i = 0; i < B.n; i++) {
			for (int j = 0; j < B.m; j++) {
				Memory[i][j] -= B.Memory[i][j];
			}
		}
		return *this;
	}

}


Matrix& Matrix::RandomMatrix() {
	double random_int;
	double random_double;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			random_int = rand();
			random_double = rand() + (random_int / RAND_MAX);
			Memory[i][j] = random_double;
		}
	}
	return *this;
}


Matrix Matrix::operator*(const Matrix& B) {
	Matrix New_Matrix(n, B.m);
	double summa = 0;
	//Идем по строчкам 1 матрицы
	for (int i = 0; i < n; i++) {
		//Идем по столбцам
		for (int j = 0; j < B.m; j++) {
			for (int ind = 0; ind < m; ind++) {
				summa += Memory[i][ind] * B.Memory[ind][j];
			}
			New_Matrix.Memory[i][j] = summa;
			summa = 0;
		}
	}
	return New_Matrix;
}


istream& operator>>(istream& in, Matrix& mat) {
	cout << "Введите размер матрицы (n, m):  ";
	in >> mat.n >> mat.m;
	mat.Memory = new double* [mat.n];
	for (int i = 0; i < mat.n; i++) {
		mat.Memory[i] = new double[mat.m];
		cout << "Введите " << i + 1 << " строку:   ";
		for (int j = 0; j < mat.m; j++) {
			in >> mat.Memory[i][j];
		}
	}
	return in;
}


ostream& operator<<(ostream& os, const Matrix& mat) {
	os << "Ваша матрица" << endl;
	for (int i = 0; i < mat.n; i++) {
		for (int j = 0; j < mat.m; j++) {
			os << mat.Memory[i][j] << " ";
		}
		os << endl;
	}
	return os;
}


double& Matrix::operator()(const int i, const int j) {
	return Memory[i][j];
}
const double& Matrix::operator()(const int i, const int j) const {
	return Memory[i][j];
}
