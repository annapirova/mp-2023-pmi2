#pragma once
using namespace std;

class Matrix;
class Vector;

class Gauss
{
	int condition;
	Matrix* matrix;
	Vector* result;
	Vector* b;
public:
	friend class Vector;
	friend class Matrix;
	Gauss(int condition, Matrix* matrix, Vector* b, Vector* result);
	void Solve();
	double Result();
	friend std::ostream& operator<<(std::ostream& os, const Gauss& other);
};


class Matrix
{
	double** matrix;
	int rows, cols;

public:
	Matrix(int rows, int cols);
	Matrix() : matrix(nullptr), rows(0), cols(0) {}
	Matrix(const Matrix& other);
	int GetRow() const;
	~Matrix();
	Matrix& operator =(const Matrix& other);
	Matrix operator +(const Matrix& other);
	Matrix operator -(const Matrix& other);
	Matrix operator +=(const Matrix& other);
	Matrix operator -=(const Matrix& other);
	double& operator ()(int i, int j);
	Matrix operator *(const Matrix& other);
	Vector operator *(const Vector& other);
	void Generate(double min_, double max_);
	friend ostream& operator <<(ostream& osin, const Matrix& other);
	friend istream& operator >>(istream& isin, const Matrix& other);
	friend class Vector;
};


class Vector
{
	int Size;
public:
	friend class Matrix;
	double* vec;
	Vector(int Size);
	Vector() : Size(0), vec(nullptr) {}
	Vector(const Vector& other);
	Vector& operator =(const Vector& other);
	~Vector();
	double Sizevec() const;
	double Element(int index) const;
	Vector operator +(const Vector& other);
	Vector operator -(const Vector& other);
	Vector operator +=(const Vector& other);
	Vector operator -=(const Vector& other);
	double& operator [](int index);
	Vector operator *(const Vector& other);
	Vector operator ++(int temp);
	Vector operator ++();
	void Generate(double min_, double max_);
	double norma();
	friend ostream& operator <<(ostream& osin, const Vector& other);
	friend istream& operator >>(istream& isin, const Vector& other);
};
