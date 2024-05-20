#pragma once
class Matrix;
class Vector;


class Gauss {
	int status;
	Matrix* Coefficients;
	Vector* X, * Answer;
public:
	Gauss(Matrix* c, Vector* x, Vector* b, int status = 0);
	void Solve();
	double Check();
	friend class Vector;
	friend class Matrix;
};


class Matrix {
	double** Memory;
	int n, m;

public:
	Matrix(int n = 1, int m = 1);
	Matrix(const Matrix& B);
	~Matrix();
	Matrix operator+(const Matrix& B);
	Matrix operator-(const Matrix& B);
	Matrix operator*(const Matrix& B);
	Matrix& operator=(const Matrix& B);
	Matrix& operator+=(const Matrix& B);
	Matrix& operator-=(const Matrix& B);
	void Swap_Matrix(int first_str_matr, int second_str_matr);
	int Size_N();
	int Size_M();
	void RandomMatrix(double min, double max);
	double& operator()(const int i, const int j);
	const double& operator()(const int i, const int j) const;
	friend Vector operator*(const Vector& A, const Matrix& B);
	friend istream& operator>>(istream& in, Matrix& mat);
	friend ostream& operator<<(ostream& os, const Matrix& mat);
	friend class Vector;
};


class Vector
{
	double* Memory;
	int size;

public:
	Vector(int size = 1);
	Vector(const Vector& B);
	~Vector();
	void Generate(double min, double max);
	Vector& operator+=(const Vector& B);
	Vector& operator-=(const Vector& B);
	Vector operator+(const Vector& B);
	Vector operator-(const Vector& B);
	Vector operator=(const Vector& B);
	Vector operator*(double k);
	Vector operator++(int k);
	double Norma();
	friend Vector operator*(const Vector& A, const Matrix& B);
	int Size();
	Vector& operator++();
	double& operator[](const int i);
	const double& operator[](const int i) const;
	friend istream& operator>>(istream& in, Vector& vec);
	friend ostream& operator<<(ostream& os, const Vector& vec);
	void Swap_Vector(int first_index, int second_index);
	friend class Matrix;
};
