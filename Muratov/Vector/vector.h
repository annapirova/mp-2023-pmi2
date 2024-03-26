class Vector {
	double* Memory;
	int size;

public:
	Vector(int size = 1);
	Vector(const Vector& B);
	~Vector();
	void Generate();
	Vector& operator+=(const Vector& B);
	Vector& operator-=(const Vector& B);
	Vector operator+(const Vector& B);
	Vector operator-(const Vector& B);
	Vector operator=(const Vector& B);
	Vector operator*(const Vector& B);
	Vector operator++(int k);
	Vector& operator++();
	double& operator[](const int i);
	const double& operator[](const int i) const;
	friend istream& operator>>(istream& in, Vector& vec);
	friend ostream& operator<<(ostream& os, const Vector& vec);
};
