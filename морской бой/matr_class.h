#pragma once


class Field;
class Matrix {
private:
	int n, m;
	int** matrix;
public:
	/*int i, j;*/

	Matrix(int row = 1, int column = 1); // конст копир-я
	Matrix(const Matrix& matr);	// перегрузка = через скобки (по образцу)

	int GetN() { return this->n; };
	int GetM() { return this->m; };

	int& Get(int i, int j) { return matrix[i][j]; }
	const int& Get(int i, int j) const { return matrix[i][j]; }

	Matrix operator+(const Matrix& matr);
	Matrix& operator+=(const Matrix& matr);
	Matrix operator-(const Matrix& matr);
	Matrix& operator-=(const Matrix& matr);
	Matrix operator*(Matrix& matr);
	Matrix& operator=(const Matrix& matr);
	

	int& operator()(int i, int j) { return matrix[i][j]; }
	const int& operator()(int i, int j) const { return matrix[i][j]; };
	friend std::ostream& operator<<(std::ostream& os, const Matrix& matr);
	friend std::istream& operator>>(std::istream& os, Matrix& matr);
	friend class Field;
	friend bool Prov(int x, int y, Field& field);
	void matrFill();

	~Matrix() {
		for (int i = 0; i < n; i++)
			delete[] matrix[i];
		delete[] matrix;
	}
};