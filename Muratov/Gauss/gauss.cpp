using namespace std;
#include <iostream>
#include "gauss.h"
#include <locale.h>
#include <random>
#include <ctime>
#include <math.h>



Vector::Vector(int size_) : size(size_) {
	if (size < 0) {
		throw bad_alloc();
	}
	else {
		Memory = new double[size_];
	}
}


Vector::~Vector() {
	delete[] Memory;
}


Vector::Vector(const Vector& B) : size(B.size) {
	if (size > 0) {
		Memory = new double[size];
		for (int i = 0; i < size; i++) {
			Memory[i] = B.Memory[i];

		}
	}
	else throw bad_alloc();
}

int Vector::Size() {
	return size;
}


Vector operator*(const Vector& A, const Matrix& B) {
	Vector New_Vector(A.size);
	double summa = 0.0;
	New_Vector.Memory = new double[A.size];
	for (int i = 0; i < B.n; i++) {
		for (int j = 0; j < B.m; j++) {
			summa += A.Memory[j] * B.Memory[i][j];
		}
		New_Vector.Memory[i] = summa;
		summa = 0.0;
	}
	return New_Vector;
}


double Vector::Norma() {
	double res, summa = 0;
	for (int i = 0; i < size; i++) {
		summa += Memory[i] * Memory[i];
	}
	res = pow(summa, 0.5);
	return res;
}


istream& operator>>(istream& in, Vector& vec) {
	cout << "Введите размер вектора:  ";
	in >> vec.size;
	vec.Memory = new double[vec.size];
	for (int i = 0; i < vec.size; i++) {
		cout << "Введите элемент: ";
		in >> vec.Memory[i];
	}
	return in;
}


ostream& operator<<(ostream& os, const Vector& vec) {
	os << "Ваш вектор" << endl;
	for (int i = 0; i < vec.size; i++) {
		os << vec.Memory[i] << "\n";
	}
	return os;
}


Vector Vector::operator=(const Vector& B) {
	if (this == &B) {
		return*this;
	}

	if (size != B.size) {
		delete[] Memory;
		Memory = new double[B.size];
		size = B.size;
	}

	for (int i = 0; i < size; i++) {
		Memory[i] = B.Memory[i];
	}
	return *this;
}


Vector Vector::operator+(const Vector& B) {
	Vector New_Vector(size);
	for (int i = 0; i < size; i++) {
		New_Vector.Memory[i] = Memory[i] + B.Memory[i];
	}
	return New_Vector;
}


Vector Vector::operator-(const Vector& B) {
	Vector New_Vector(size);
	for (int i = 0; i < size; i++) {
		New_Vector.Memory[i] = Memory[i] - B.Memory[i];
	}
	return New_Vector;
}


void Vector::Generate(double min, double max) {
	for (int i = 0; i < size; i++) {
		Memory[i] = min + (max - min) * ((double)rand() / double(RAND_MAX));
	}
}


double& Vector::operator[](const int i) {
	return Memory[i];
}


const double& Vector::operator[](const int i) const {
	return Memory[i];
}


Vector& Vector::operator+=(const Vector& B) {
	if (size < B.size) {
		Vector New_Vector(B.size);
		//Выделяем память под новый вектор
		New_Vector.Memory = new double[B.size];
		//Заполняем нулями
		for (int i = 0; i < B.size; i++) {
			New_Vector.Memory[i] = 0;
		}
		//Переносим данные из меньшего вектора
		for (int i = 0; i < size; i++) {
			New_Vector.Memory[i] = Memory[i];
		}
		//Складываем и возвращаем итоговую матрицу
		for (int i = 0; i < B.size; i++) {
			New_Vector.Memory[i] += B.Memory[i];
		}
		Vector::operator=(New_Vector);
	}
	else {
		for (int i = 0; i < B.size; i++) {
			Memory[i] += B.Memory[i];
		}
		return *this;
	}

}


Vector& Vector::operator-=(const Vector& B) {
	if (size < B.size) {
		Vector New_Vector(B.size);
		//Выделяем память под новый вектор
		New_Vector.Memory = new double[B.size];
		//Заполняем нулями
		for (int i = 0; i < B.size; i++) {
			New_Vector.Memory[i] = 0;
		}
		//Переносим данные из меньшего вектора
		for (int i = 0; i < size; i++) {
			New_Vector.Memory[i] = Memory[i];
		}
		//Вычитаем и возвращаем итоговую матрицу
		for (int i = 0; i < B.size; i++) {
			New_Vector.Memory[i] -= B.Memory[i];
		}
		Vector::operator=(New_Vector);
	}
	else {
		for (int i = 0; i < B.size; i++) {
			Memory[i] -= B.Memory[i];
		}
		return *this;
	}

}


Vector Vector::operator*(double k) {
	Vector New_Vector(size);
	New_Vector.Memory = new double[size];
	for (int i = 0; i < size; i++) {
		New_Vector.Memory[i] = Memory[i] * k;
	}
	return New_Vector;
}



Vector Vector::operator++(int k) {
	Vector tmp(*this);
	for (int i = 0; i < size; i++) {
		tmp.Memory[i] = tmp.Memory[i] + 1.0;
	}
	return tmp;
}


Vector& Vector::operator++() {
	for (int i = 0; i < size; i++) {
		Memory[i] = Memory[i] + 1.0;
	}
	return *this;
}




Matrix::Matrix(int n_, int m_) : n(n_), m(m_) {
	Memory = new double* [n];
	for (int i = 0; i < n; i++) {
		Memory[i] = new double[m];
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


int Matrix::Size_N() {
	return n;
}


int Matrix::Size_M() {
	return m;
}


Matrix Matrix::operator+(const Matrix& B) {
	Matrix New_Matrix(B.n, B.m);
	New_Matrix.Memory = new double* [n];
	for (int i = 0; i < B.n; i++) {
		New_Matrix.Memory[i] = new double[m];
	}
	for (int i = 0; i < B.n; i++) {
		for (int j = 0; j < B.m; j++) {
			New_Matrix.Memory[i][j] = Memory[i][j] + B.Memory[i][j];
		}
	}
	return New_Matrix;
}


Matrix& Matrix::operator=(const Matrix& B) {
	if (this == &B) {
		return*this;
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
	Matrix New_Matrix(B.n, B.m);
	New_Matrix.Memory = new double* [n];
	for (int i = 0; i < B.n; i++) {
		New_Matrix.Memory[i] = new double[m];
	}
	for (int i = 0; i < B.n; i++) {
		for (int j = 0; j < B.m; j++) {
			New_Matrix.Memory[i][j] = Memory[i][j] - B.Memory[i][j];
		}
	}
	return New_Matrix;
}



Matrix& Matrix::operator+=(const Matrix& B) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			Memory[i][j] += B.Memory[i][j];
		}
	}
	return *this;
}


Matrix& Matrix::operator-=(const Matrix& B) {
	for (int i = 0; i < B.n; i++) {
		for (int j = 0; j < B.m; j++) {
			Memory[i][j] -= B.Memory[i][j];
		}
	}
	return *this;
}


void Matrix::RandomMatrix(double min, double max) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			Memory[i][j] = min + (max - min) * ((double)rand() / double(RAND_MAX));
		}
	}
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




Gauss::Gauss(Matrix* c, Vector* x, Vector* b, int status): status(status), Coefficients(c), X(x), Answer(b) {};


void Gauss::Solve() {
	int n;
	double summa;
	double alpha;
	int max_elem;
	Matrix M = *Coefficients;
	Vector Ans = *Answer;
	n = M.Size_N();
	for (int i = 0; i < n - 1; i++) {
		max_elem = abs(M(i, i));
		for (int str = i; str < n; str++) {
			if (abs(M(str, i)) > max_elem) {
				M.Swap_Matrix(i, str);
				Ans.Swap_Vector(i, str);
				max_elem = abs(M(i, i));
			}
		}
		for (int j = i + 1; j < n; j++) {
			alpha = M(j, i) / M(i, i);
			for (int k = i; k < n; k++) {
				M(j, k) -= (alpha * M(i, k));
			}
			Ans[j] -= (alpha * Ans[i]);
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		summa = 0.0;
		for (int j = i + 1; j < n; j++) {
			summa += M(i, j) * (*X)[j];
		}
		(*X)[i] = (Ans[i] - summa) / M(i, i);
	}
	status = 1;
}


double Gauss::Check() {
	if (status != 1) {
		return -1;
	}

	Vector e = (*X) * (*Coefficients) - (*Answer);
	double a, y;
	a = e.Norma();
	y = (*Answer).Norma();
	return a / y;
}


void Matrix::Swap_Matrix(int first_str_matr, int second_str_matr) {
	double c;
	for (int i = 0; i < n; i++) {
		c = Memory[first_str_matr][i];
		Memory[first_str_matr][i] = Memory[second_str_matr][i];
		Memory[second_str_matr][i] = c;
	}
}


void Vector::Swap_Vector(int first_index, int second_index) {
	double n;
	n = Memory[first_index];
	Memory[first_index] = Memory[second_index];
	Memory[second_index] = n;
}