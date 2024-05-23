#include "gauss.h"
Vector::Vector(int s) : size(s) {
    values = new double[s];
}

Vector::Vector(const Vector& other) : size(other.size) {
    values = new double[size];
    for (int i = 0; i < size; ++i) {
        values[i] = other.values[i];
    }
}

Vector::~Vector() {
    delete[] values;
}

Vector& Vector::operator=(const Vector& other) {
    if (this == &other) {
        return *this;
    }
    delete[] values;
    size = other.size;
    values = new double[size];
    for (int i = 0; i < size; ++i) {
        values[i] = other.values[i];
    }
    return *this;
}

Vector Vector::operator+(const Vector& other) const {
    if (size != other.size) {
		cout << "Vectors must be of the same size" << endl;;
    }
    Vector result(size);
    for (int i = 0; i < size; ++i) {
        result.values[i] = values[i] + other.values[i];
    }
    return result;
    result.~Vector();
}

Vector Vector::operator-(const Vector& other) const {
    if (size != other.size) {
		cout << "Vectors must be of the same size" << endl;;
    }
    Vector result(size);
    for (int i = 0; i < size; ++i) {
        result.values[i] = values[i] - other.values[i];
    }
    return result;
    result.~Vector();
}

double& Vector::operator[](int i) {
    if (i < 0 || i >= size) {
		cout << "Index out of range" << endl;
    }
    return values[i];
}

int Vector::GiveSize() const {
    return size;
}

void Vector::Generate(double lg, double ug) {
    for (int i = 0; i < size; ++i) {
        double random_value = lg + (rand() * (ug - lg) / RAND_MAX);
        values[i] = random_value;
    }
}

void Vector::NullVector() {
    for (int i = 0; i < size; ++i) {
        values[i] = 0;
    }
}

std::ostream& operator<<(std::ostream& os, const Vector& vec) {
    for (int i = 0; i < vec.size; ++i) {
        os << vec.values[i] << " " << endl;
    }
    return os;
}

std::istream& operator>>(std::istream& is, Vector& vec) {
    for (int i = 0; i < vec.size; ++i) {
        is >> vec.values[i];
    }
    return is;
}
Matrix::Matrix(int n, int m) :row(n), col(m) {
	A = new double* [n];
	for (int i = 0; i < row; i++) {
		A[i] = new double[m];

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
Matrix::~Matrix() {
	for (int i = 0; i < row; i++) {
		delete A[i];
	}
	delete[] A;
}
void Matrix::NullMatrix() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			A[i][j] = 0;
		}
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
	c.~Matrix();
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
	result.~Matrix();
}

Matrix& Matrix::operator=(const Matrix& B) {
	if (this == &B) { return *this; }
	if ((row != B.row) || (col != B.col)) {
		for (int i = 0; i < row; i++) {
			delete[]A[i];
		}
		delete[]A;
		row = B.row;
		col = B.col;
		A = new double* [B.row];

		for (int i = 0; i < B.row; i++) {
			A[i] = new double[B.col];
		}

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				A[i][j] = B.A[i][j];
			}
		}
	}
	else {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				A[i][j] = B.A[i][j];
			}
		}
	}



}

Matrix& Matrix::operator+=(const Matrix& B) {
	if (row != B.row || col != B.col) {
		cout << "The matrices are not the right size" << endl;
		return *this;
	}
	if ((row == B.row) && (col == B.col)) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				A[i][j] += B.A[i][j];
			}
		}
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
	result.~Matrix();
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
	result.~Vector();
}
double& Matrix:: operator()(int i, int j) {
	return A[i][j];
}
int Matrix::getRow() const {
	return row;
}
int Matrix::getCol() const {
	return col;
}
Gauss::Gauss(Matrix& mat, Vector& ans) : matrix(&mat), m_copy(mat), answer(&ans), X(mat.getRow()) {}

void Gauss::transformToUpperTriangular() {
	m_copy = *matrix;
	int n = m_copy.getRow();
	for (int i = 0; i < n - 1; i++) {
		// Поиск строки с максимальным элементом в текущем столбце
		int maxRow = i;
		for (int k = i + 1; k < n; k++) {
			if (abs(m_copy(k, i)) > abs(m_copy(maxRow, i))) {
				maxRow = k;
			}
		}

		// Перестановка текущей строки с найденной строкой с максимальным элементом
		if (maxRow != i) {
			for (int j = 0; j < n; j++) {
				std::swap(m_copy(i, j), m_copy(maxRow, j));
			}
			std::swap((*answer)[i], (*answer)[maxRow]);
		}

		for (int k = i + 1; k < n; k++) {
			double alpha = m_copy(k, i) / m_copy(i, i);
			for (int j = i; j < n; j++) {
				m_copy(k, j) -= alpha * m_copy(i, j);
			}
			(*answer)[k] -= alpha * (*answer)[i];
		}
	}
}

void Gauss::solve() {
	transformToUpperTriangular();
	int n = m_copy.getRow();
	X.NullVector();

	for (int i = n - 1; i >= 0; --i) {
		double sum = 0;
		for (int j = i + 1; j < n; ++j) {
			sum += m_copy(i, j) * X[j];
		}
		X[i] = ((*answer)[i] - sum) / m_copy(i, i);
	}
}

Vector Gauss::getAnswer2() {
	return *answer;
}
Vector Gauss::getAnswer() {
	return X;
}
Matrix Gauss::getMCopy() {
	return m_copy;
}
int Gauss::Check(Vector B,double cr) {
	int status=1;
	int i = 0;
	Vector corr = (m_copy.multiplyVector(X) - B);
	while ((status == 1) && (i < corr.GiveSize())) {
		status = (abs(corr[i]) < cr);
		i++;
	}
	return status;
}

ostream& operator<<(ostream& os, const Matrix& B) {
	for (int i = 0; i < B.row; i++) {
		for (int j = 0; j < B.col; j++) {
			os << B.A[i][j] << " ";
		}
		os << endl;
	}
	return os;
}
istream& operator>>(istream& is, const Matrix& B) {
	for (int i = 0; i < B.row; i++) {
		for (int j = 0; j < B.col; j++) {
			is >> B.A[i][j];
		}
	}
	return is;
}
