using namespace std;
#include <iostream>
#include <random>
#include <ctime>
#include <math.h>
#include "Gauss.h"
Gauss::Gauss(int condition, Matrix* matrix, Vector* b, Vector* result) : condition(condition), matrix(matrix), b(b), result(result) {};

void Gauss::Solve()
{
    int n = matrix->GetRow();

    for (int i = 0; i < n; i++) {
        // Прямой ход метода Гаусса
        for (int k = i + 1; k < n; k++) {
            double factor = matrix->operator()(k, i) / matrix->operator()(i, i);
            for (int j = i; j < n; j++) {
                matrix->operator()(k, j) -= factor * matrix->operator()(i, j);
            }
            b->operator[](k) -= factor * b->operator[](i);
        }
    }

    // Обратный ход метода Гаусса для нахождения решения
    result->operator[](n - 1) = b->operator[](n - 1) / matrix->operator()(n - 1, n - 1);
    for (int i = n - 2; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j < n; j++) {
            sum += matrix->operator()(i, j) * result->operator[](j);
        }
        result->operator[](i) = (b->operator[](i) - sum) / matrix->operator()(i, i);
    }
}



double Gauss::Result()
{
    double res = 0.0;
    int n = matrix->GetRow();

    for (int i = 0; i < n; i++) {
        double temp = 0.0;
        for (int j = 0; j < n; j++) {
            temp += matrix->operator()(i, j) * result->operator[](j);
        }
        if (abs(temp - b->operator[](i)) > res) {
            res = abs(temp - b->operator[](i));
        }
    }

    return res;
}
std::ostream& operator<<(std::ostream& os, const Gauss& other)
{
    os << "Matrix:" << std::endl;
    os << *(other.matrix) << std::endl;

    os << "Vector b:" << std::endl;
    for (int i = 0; i < other.b->Sizevec(); i++) {
        os << (*(other.b))[i] << " ";
    }
    os << std::endl;

    os << "Result Vector:" << std::endl;
    for (int i = 0; i < other.result->Sizevec(); i++) {
        os << (*(other.result))[i] << " ";
    }
    os << std::endl;

    return os;
}
Vector::Vector(int Size) : Size(Size)
{
    vec = new double[Size];
    for (int i = 0; i < Size; i++)
    {
        vec[i] = i;
    }
}
Vector::Vector(const Vector& other) : Size(other.Size)
{

    vec = new double[Size];
    for (int i = 0; i < other.Size; i++)
    {
        vec[i] = other.vec[i];
    }
}
Vector& Vector:: operator =(const Vector& other)
{
    Size = other.Size;
    if (this == &other)
    {
        return *this;
    }

    if (vec != nullptr)
    {
        delete[] vec;

    }
    vec = new double[other.Size];

    for (int i = 0; i < other.Size; i++)
    {
        vec[i] = other.vec[i];
    }

    return *this;
}
Vector::~Vector()
{
    delete[] vec;
}
Vector Vector:: operator +(const Vector& other)
{
    Vector tmp(Size);
    if (tmp.Size == other.Size)
    {
        for (int i = 0; i < Size; i++)
        {
            tmp.vec[i] = vec[i] + other.vec[i];
        }
    }

    return tmp;
}
Vector Vector:: operator -(const Vector& other)
{
    Vector tmp(Size);
    if (tmp.Size == other.Size)
    {
        for (int i = 0; i < Size; i++)
        {
            tmp.vec[i] = vec[i] - other.vec[i];
        }
    }

    return tmp;
}
Vector Vector:: operator +=(const Vector& other)
{

    if (Size == other.Size)
    {
        for (int i = 0; i < Size; i++)
        {
            vec[i] = vec[i] + other.vec[i];
        }
    }

    return *this;
}
Vector Vector:: operator -=(const Vector& other)
{


    if (Size == other.Size)
    {
        for (int i = 0; i < Size; i++)
        {
            vec[i] = vec[i] - other.vec[i];
        }
    }
    else
    {
        cout << "Error: size1 != size2" << endl << "return NULL vector" << endl;
    }
    return *this;
}
double& Vector:: operator [](int index)
{
    return vec[index];
}
double Vector::Sizevec() const
{
    return Size;
}
double Vector::Element(int index) const
{
    if (index <0 || index > Size)
    {
        return 0;
    }
    else {
        return vec[index];
    }
}
Vector Vector:: operator *(const Vector& other)
{
    if (Size != other.Size)
    {
        delete[] vec;
        vec = new double[other.Size];
        Size = other.Size;
    }
    Vector result(other);
    for (int i = 0; i < other.Size; i++)
    {
        result[i] = vec[i] * other.vec[i];
    }
    return result;
}
Vector Vector:: operator ++(int)
{
    Vector tmp(*this);
    {
        for (int i = 0; i < Size; i++)
        {
            vec[i] += 1.0;
        }
        return tmp;
    }
}
Vector Vector:: operator ++()
{
    for (int i = 0; i < Size; i++)
    {
        vec[i] += 1.0;
    }
    return *this;
}
void Vector::Generate(double min_, double max_)
{
    double min = min_;
    double max = max_;
    srand(time(NULL));
    for (int i = 0; i < Size; i++)
    {
        vec[i] = 1. * (max - min) * rand() / RAND_MAX + min;
    }
}
double Vector::norma()
{
    double sum2 = 0.0;
    for (int i = 0; i < Size; i++)
    {
        sum2 = sum2 + vec[i] * vec[i];
    }
    return sqrt(sum2);
}
ostream& operator<<(ostream& osin, const Vector& other)
{
    for (int i = 0; i < other.Size; i++)
    {
        osin << other.vec[i] << endl;
    }
    return osin;
}
istream& operator>>(istream& isin, const Vector& other)
{
    for (int i = 0; i < other.Size; i++)
    {
        isin >> other.vec[i];
    }
    return isin;
}

Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols)
{
    matrix = new double* [rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new double[cols];
        for (int j = 0; j < cols; j++)
            matrix[i][j] = 0.0;
    }
}
Matrix::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols)
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
        
    }
    delete[] matrix;
}
int Matrix::GetRow() const
{
    return rows;
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
Vector Matrix:: operator *(const Vector& other)
{
    if (rows != other.Sizevec())
    {
        return Vector(0);
    }
    Vector result(cols);
    for (int i = 0; i < cols; i++)
    {
        double tmp = 0.0;
        for (int j = 0; j < rows; j++)
        {
            tmp = tmp + matrix[i][j] * other.Element(j);
        }
        result[i] = tmp;
    }
    return result;
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
void Matrix::Generate(double min_, double max_)
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
