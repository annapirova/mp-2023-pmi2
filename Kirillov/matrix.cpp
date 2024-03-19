#include "matrix.h"
using namespace std;
Matrix::Matrix(int n, int m) :row(n), col(m) {
	A = new double* [n];
	for (int i = 0;i < row;i++) {
		A[i] = new double[m];

	}
}
Vector::Vector(int s) : size(s) {
	C = new double* [s];
	for (int i = 0; i < s; ++i) {
		C[i] = new double[1];
	}
}
Matrix::Matrix(const Matrix& B) :row(B.row), col(B.col) {
	A = new double* [row];
	for (int i = 0; i < row; i++) {
		A[i] = new double[col];
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++) {
			A[i][j] = B.A[i][j];
		}
	}
}
Vector::Vector(const Vector& B) : size(B.size) {
	C = new double* [size];
	for (int i = 0; i < size; ++i) {
		C[i] = new double[1];
		C[i][0] = B.C[i][0];
	}
}

Matrix::~Matrix() {
	for (int i = 0; i < row; i++) {
		delete A[i];
	}
	delete[] A;
}
Vector::~Vector() {
	for (int i = 0; i < size; ++i) {
		delete[] C[i];
	}
	delete[] C;
}

void Matrix::NullMatrix() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			A[i][j] = 0;
		}
	}
}
void Vector::NullVector() {
	for (int i = 0; i < size; ++i) {
		C[i][0] = 0;
	}
}
void Vector::Generate(double lg, double ug) {
	for (int i = 0; i < size; ++i) {
		double random_value = lg + (rand() * (ug - lg) / RAND_MAX);
		C[i][0] = random_value;
	}
}

void Matrix::Generate(double lg, double ug) {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			double random_value = lg + (rand() * (ug - lg) / RAND_MAX);
			A[i][j] = random_value;

		}
	}
}
Matrix Matrix::operator+(const Matrix& B) {
Matrix c(row, col);
if (row != B.row || col != B.col) {
	cout << "The matrices are not the right size" << endl;
	return Matrix();
}
for (int i = 0; i < row; i++) {
	for (int j = 0; j < col; j++) {
		c.A[i][j] = B.A[i][j] + A[i][j];
	}
}
return c;
}
Vector Vector::operator+(const Vector& B) {
	Vector result(size);
	if (size != B.size) {
		cout << "The vectors are not the same size" << endl;
		return result;
	}
	for (int i = 0; i < size; ++i) {
		result.C[i][0] = C[i][0] + B.C[i][0];
	}
	return result;
}

Matrix Matrix::operator-(const Matrix& B) {
	if (row != B.row || col != B.col) {
		cout << "The matrices are not the right size" << endl;
		return Matrix();
	}
	Matrix result(row, col);
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			result.A[i][j] = A[i][j] - B.A[i][j];
		}
	}
	return result;
}
Vector Vector::operator-(const Vector& B) {
	Vector result(size);
	if (size != B.size) {
		cout << "The vectors are not the same size" << endl;
		return result;
	}
	for (int i = 0; i < size; ++i) {
		result.C[i][0] = C[i][0] - B.C[i][0];
	}
	return result;
}
Matrix& Matrix::operator=(const Matrix& B) {
	if (this == &B) { return *this; }
	if ((row != B.row) || (col != B.col)) {
		for (int i = 0;i < row;i++) {
			delete[]A[i];
		}
		delete[]A;
		row = B.row;
		col = B.col;
		A = new double* [B.row];

		for (int i = 0;i < B.row;i++) {
			A[i]=new double[B.col];
		}

		for (int i = 0;i < row;i++) {
			for (int j = 0;j < col;j++) {
				A[i][j] = B.A[i][j];
			}
		}
	}
	else {
		for (int i = 0;i < row;i++) {
			for (int j = 0;j < col;j++) {
				A[i][j] = B.A[i][j];
			}
		}
	}

	

}
Vector& Vector::operator=(const Vector& B) {
	if (this == &B) { return *this; }
	for (int i = 0; i < size; ++i) {
		delete[] C[i];
	}
	delete[] C;
	size = B.size;
	C = new double* [size];
	for (int i = 0; i < size; ++i) {
		C[i] = new double[1];
		C[i][0] = B.C[i][0];
	}
	return *this;
}
Matrix& Matrix::operator+=(const Matrix& B) {
	if (row != B.row || col != B.col) {
		cout << "The matrices are not the right size" << endl;
		return *this;
	}
	if ((row == B.row) && (col == B.col)) {
		for (int i = 0;i < row;i++) {
			for (int j = 0;j < col;j++) {
				A[i][j] += B.A[i][j];
			}
		}
	}
	return *this;
}
Vector& Vector::operator+=(const Vector& B) {
	if (size != B.size) {
cout << "The vectors are not the same size" << endl;
		return *this;
	}
	for (int i = 0; i < size; i++) {
		C[i][0] += B.C[i][0];
	}
	return *this;
}
Matrix& Matrix::operator-=(const Matrix& B) {
	if (row != B.row || col != B.col) {
		cout << "The matrices are not the right size" << endl;
		return *this;
	}
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			A[i][j] -= B.A[i][j];
		}
	}
	return *this;
}
Vector& Vector::operator-=(const Vector& B) {
	if (size != B.size) {
		cout << "The vectors are not the same size" << endl;
		return *this;
	}
	for (int i = 0; i < size; ++i) {
		C[i][0] -= B.C[i][0];
	}
	return *this;
}
Matrix Matrix::operator*(const Matrix& B) {
	if (col != B.row) {
		cout << "The matrices are not the right size" << endl;
		return Matrix();
	}
	Matrix result(row, B.col);
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < B.col; ++j) {
			double sum = 0;
			for (int k = 0; k < col; ++k) {
				sum += A[i][k] * B.A[k][j];
			}
			result.A[i][j] = sum;
		}
	}
	return result;
}
double& Vector::operator[](int i) {
	return C[i][0];
}
Vector Matrix::multiplyVector(Vector& v) {
	if (col != v.GiveSize()) {
		cout << "Matrix and vector dimensions do not match." << endl;
		return Vector();
	}

	Vector result(row);
	for (int i = 0; i < row; ++i) {
		double sum = 0;
		for (int j = 0; j < col; ++j) {
			sum += A[i][j] * v[j];
		}
		result[i] = sum;
	}
	return result;
}
int Vector::GiveSize() const {
	return size;
}
double& Matrix:: operator()(int i, int j) {
	return A[i][j];
}
ostream& operator<<(ostream& os, const Matrix& B) {
	for (int i = 0;i < B.row;i++) {
		for (int j = 0;j < B.col;j++) {
			os << B.A[i][j] << " ";
		}
		os << endl;
	}
	return os;
}
ostream& operator<<(std::ostream& os, const Vector& B) {
	for (int i = 0; i < B.size; ++i) {
		os << B.C[i][0] << " "<<endl;
	}
	return os;
}