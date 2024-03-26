class Matrix {
	double** Memory;
	int n, m;

public:
	Matrix(int n = 1, int m = 1);
	Matrix(const Matrix &B);
	~Matrix();
	Matrix operator+(const Matrix& B);
	Matrix operator-(const Matrix& B);
	Matrix operator*(const Matrix& B);
	Matrix &operator=(const Matrix& B);
	Matrix &operator+=(const Matrix& B);
	Matrix &operator-=(const Matrix& B);
	Matrix& RandomMatrix();
	double& operator()(const int i, const int j);
	const double& operator()(const int i, const int j) const;
	friend istream& operator>>(istream& in, Matrix& mat);
	friend ostream& operator<<(ostream& os, const Matrix& mat);
	void Print();
};
