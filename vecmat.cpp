#include <iostream>
#include <locale.h>
#include "vecmat.h"
#include <iomanip>
#include <ctime>
using namespace std;
Matrix::Matrix(int row, int col) : n(row), m(col) {
    matrix = new double* [n];
    for (int j = 0; j < n; j++)
        matrix[j] = new double[m];
}

Matrix::Matrix(const Matrix& matr) : n(matr.n), m(matr.m) {
    matrix = new double* [n];
    for (int j = 0; j < n; j++)
        matrix[j] = new double[m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            matrix[i][j] = matr.matrix[i][j];
}

Matrix::~Matrix() {
    for (int i = 0; i < n; i++)
        delete[] matrix[i];
    delete[] matrix;
}

Matrix Matrix::operator+(const Matrix& matr) {
    Matrix NewMatr(matr.n, matr.m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            NewMatr.matrix[i][j] = this->matrix[i][j] + matr.matrix[i][j];
    return NewMatr;
}

Matrix& Matrix::operator+=(const Matrix& matr) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            matrix[i][j] += matr.matrix[i][j];
    return *this;
}

Matrix Matrix::operator-(const Matrix& matr) {
    Matrix NewMatr(matr.n, matr.m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            NewMatr.matrix[i][j] = this->matrix[i][j] - matr.matrix[i][j];
    return NewMatr;
}

Matrix& Matrix::operator-=(const Matrix& matr) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            matrix[i][j] -= matr.matrix[i][j];
    return *this;
}

Matrix Matrix::operator*(Matrix& matr) {
    Matrix NewMatr(n, matr.m);
    for (int l = 0; l < n; l++)
        for (int i = 0; i < matr.m; i++) {
            NewMatr.matrix[l][i] = 0;
            for (int k = 0; k < matr.n; k++) {
                NewMatr.matrix[l][i] += matrix[l][k] * matr.matrix[k][i];
            }
        }
    return NewMatr;
}

Matrix& Matrix::operator=(const Matrix& matr) {
    if (this == &matr) return *this;
    if (n != matr.n || m != matr.m) {
        for (int i = 0; i < n; i++)
            delete[] matrix[i];
        delete[] matrix;
        n = matr.n; m = matr.m;
        matrix = new double* [n];
        for (int j = 0; j < n; j++)
            matrix[j] = new double[m];
    }

    for (int i = 0; i < n; i++) // создаём матрицу
        for (int j = 0; j < m; j++)
            matrix[i][j] = matr.matrix[i][j];
    return *this;
}

double& Matrix::operator()(int i, int j) {
    return matrix[i][j];
}

const double& Matrix::operator()(int i, int j) const {
    return matrix[i][j];
}

ostream& operator<<(ostream& os, const Matrix& matr) {
    for (int i = 0; i < matr.n; i++) {
        for (int j = 0; j < matr.m; j++) {
            os << matr.matrix[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

istream& operator>>(istream& in, Matrix& matr) {
    int rw, clmn;
    cout << "Количество строк и столбцов: "; in >> rw >> clmn;
    matr = Matrix(rw, clmn);
    for (int i = 0; i < matr.n; i++) {
        cout << "строка " << i << " элементы: ";
        for (int j = 0; j < matr.m; j++)
            in >> matr.matrix[i][j];
    }
    return in;
}

Vector::Vector(int N) : len(N) { vect = new double[N]; }

Vector::Vector(const Vector& v) : len(v.len) {
    vect = new double[len];
    for (int i = 0; i < len; i++)
        vect[i] = v.vect[i];
}

Vector::~Vector() { delete[] vect; }

Vector Vector::operator+(const Vector& v) {
    int maxl; (len > v.len) ? maxl = len : maxl = v.len;
    Vector NewV(maxl);
    for (int i = 0; i < maxl; i++)
        NewV.vect[i] = vect[i] + v.vect[i];
    return NewV;
}

Vector Vector::operator-(const Vector& v) {
    int maxl; (len > v.len) ? maxl = len : maxl = v.len;
    Vector NewV(maxl);
    for (int i = 0; i < maxl; i++)
        NewV.vect[i] = vect[i] - v.vect[i];
    return NewV;
}

Vector& Vector::operator+=(const Vector& v) {
    for (int i = 0; i < len; i++)
        vect[i] += v.vect[i];
    return *this;
}

Vector& Vector::operator-=(const Vector& v) {
    for (int i = 0; i < len; i++)
        vect[i] -= v.vect[i];
    return *this;
}

Vector Vector::operator*(double a) {
    Vector NewV(len);
    for (int i = 0; i < len; i++)
        NewV.vect[i] = vect[i] * a;
    return NewV;
}
Vector operator*(const Matrix& matr, const Vector& vect) {
    Vector result(matr.Rows());
    for (int i = 0; i < matr.Rows(); ++i) {
        double sum = 0.0;
        for (int j = 0; j < matr.Cols(); ++j) {
            sum += matr(i, j) * vect(j);
        }
        result(i) = sum;
    }
    return result;
}

Vector& Vector::operator=(const Vector& v) {
    if (this == &v) return *this;
    len = v.len;
    delete[] vect;
    vect = new double[len];
    for (int i = 0; i < len; i++)
        vect[i] = v.vect[i];
    return *this;
}

double& Vector::operator()(int i) {
    return vect[i];
}

const double& Vector::operator()(int i) const {
    return vect[i];
}

double Vector::Norm() const {
    double norm = 0.0;
    for (int i = 0; i < len; i++)
        norm += vect[i] * vect[i];
    return sqrt(norm);
}

Vector operator*(Matrix& matr, Vector& vect) {
    Vector NewV(vect.len);
    for (int i = 0; i < vect.len; i++) {
        NewV.vect[i] = 0;
        for (int j = 0; j < matr.n; j++)
            NewV.vect[i] += matr.matrix[i][j] * vect.vect[j];
    }
    return NewV;
}

ostream& operator<<(ostream& os, const Vector& V) {
    for (int i = 0; i < V.len; i++)
        os << V.vect[i] << " ";
    return os;
}
void Matrix::RandomMatrix(double min, double max) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = min + (max - min) * ((double)rand() / double(RAND_MAX));
        }
    }
}

void Vector::Generate(double min, double max) {
    for (int i = 0; i < len; i++) {
        vect[i] = min + (max - min) * ((double)rand() / double(RAND_MAX));
    }
}


istream& operator>>(istream& in, Vector& V) {
    cout << "";
    for (int i = 0; i < V.len; i++)
        in >> V.vect[i];
    return in;
}
