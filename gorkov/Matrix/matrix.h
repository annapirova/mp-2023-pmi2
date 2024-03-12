class  Matrix
{
	int n, m;
	double** A;
public:
	Matrix(int n = 1, int m = 1);
	~Matrix();
	Matrix(const Matrix& B);
	void Print();
	void Generate(int a, int b);
	void Null();
	Matrix& operator= (const Matrix& B);
	Matrix& operator+= (const Matrix& B);
	Matrix operator+ (const Matrix& B);
	Matrix operator- (const Matrix& B);
	Matrix& operator-= (const Matrix& B);
	Matrix operator* (const Matrix& B);
private:

};

class Vector
{
	int size;
	double* vec;
public:
	Vector(int size = 1);
	void Print();
	void Genetate(int min, int max);
	//istream operator>>(istream& in, Vector& tor);
	Vector& operator= (const Vector& tor);
	Vector operator+ (const Vector& tor);
	~Vector();
};