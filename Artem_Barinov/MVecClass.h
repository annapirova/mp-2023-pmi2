#pragma once
#include <iostream>
class Vector;

class Matrix {
private:
	int n, m;
	double** matrix;
public:
	Matrix(int row = 1, int column = 1); // конст копир-я
	Matrix(const Matrix& matr);	// перегрузка = через скобки (по образцу)
	int GetN() { return this->n; };
	int GetM() { return this->m; };
	double& Get(int i, int j) { return matrix[i][j]; }
	const double& Get(int i, int j) const { return matrix[i][j]; }
	Matrix operator+(const Matrix& matr);
	Matrix& operator+=(const Matrix& matr);
	Matrix operator-(const Matrix& matr);
	Matrix& operator-=(const Matrix& matr);
	Matrix operator*(Matrix& matr);
	Matrix& operator=(const Matrix& matr);
	double& operator()(int i, int j) { return matrix[i][j]; }
	void matrFill();
	const double& operator()(int i, int j) const { return matrix[i][j]; }	
	friend class Vector;
	friend Matrix Gaus(Matrix& matr, Vector& mvect); // отдельное разрешение методу Гаусса обращаться к матрице
	friend void ReGaus(Matrix& matr, Vector& mvect);
	friend void GSolCheck(Matrix& matr, Vector& solvect, Vector& mvect);
	friend std::ostream& operator<<(std::ostream& os, const Matrix& matr);
	friend std::istream& operator>>(std::istream& os, Matrix& matr);
	~Matrix() {
		for (int i = 0; i < n; i++)
			delete[] matrix[i];
		delete[] matrix;
	}
	friend Vector operator*(Matrix& matr, Vector& vect);

};

Vector operator*(Matrix& matr, Vector& vect);


class Vector {
private:
	double* vect;
	int len;
public:
	Vector(int N = 1);
	Vector(Vector& v);
	Vector operator+(Vector& v);
	Vector operator-(Vector& v);
	Vector& operator*=(double a);
	Vector& operator=(const Vector& v);
	Vector& operator+=(Vector& v);
	Vector& operator-=(Vector& v);
	friend class Matrix;
	friend Matrix Gaus(Matrix& matr, Vector& mvect);
	friend void ReGaus(Matrix& matr, Vector& mvect);
	friend void GSolCheck(Matrix& matr, Vector& solvect, Vector& mvect);
	friend Vector operator*(Matrix& matr, Vector& vect);
	friend std::ostream& operator<<(std::ostream& os, const Vector& vect);
	friend std::istream& operator>>(std::istream& in, Vector& V);
	~Vector();
};