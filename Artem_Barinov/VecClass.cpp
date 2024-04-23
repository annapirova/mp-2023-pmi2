#include <iostream>
#include "MVecClass.h"

// конструктор и деструктор
Vector::Vector(int N) : len(N) { vect = new double[N]; }
Vector::Vector(Vector& v) : len(v.len) {
	vect = new double[len];
	for (int i = 0; i < len; i++)
		vect[i] = v.vect[i];
}
Vector::~Vector() { delete[] vect; }
// функции
Vector Vector::operator+(Vector& v) {	
	int maxl; (len > v.len) ? maxl = len : maxl = v.len;
	Vector NewV(maxl);
	for (int i = 0; i < maxl; i++)
		NewV.vect[i] = vect[i] + v.vect[i];
	return NewV;
}
Vector Vector::operator-(Vector& v) {
	int maxl; (len > v.len) ? maxl = len : maxl = v.len;
	Vector NewV(maxl);
	for (int i = 0; i < maxl; i++)
		NewV.vect[i] = vect[i] - v.vect[i];
	return NewV;
}
Vector& Vector::operator+=(Vector& v) {
	for (int i = 0; i < len; i++)
		vect[i] += v.vect[i];
	return *this;
}
Vector& Vector::operator-=(Vector& v) {
	for (int i = 0; i < len; i++)
		vect[i] -= v.vect[i];
	return *this;
}
Vector& Vector::operator=(const Vector& v) {
	if (this != &v)	{ // перевыделять память, если надо
		len = v.len;
		vect = new double[len];
		for (int i = 0; i < len; i++)
			vect[i] = v.vect[i];
	}
	return *this;
}
Vector& Vector::operator*=(double a) {
	for (int i = 0; i < len; i++)
		vect[i] *= a;
	return *this;
}
Vector operator*( Matrix& matr,  Vector& vect) {
	Vector NewV(vect.len);
	for (int i = 0; i < vect.len; i++)
		for (int j = 0; j < matr.n; j++)
			for (int k = 0; k < matr.m; k++)
				NewV.vect[i] = matr.matrix[j][k] * vect.vect[k];
	return NewV;
}
// операторы
std::ostream& operator<<(std::ostream& os, const Vector& V) {
	for (int i = 0; i < V.len; i++)
		os << V.vect[i] << " ";
	return os;
}
std::istream& operator>>(std::istream& in, Vector& V) {
	std::cout << "Values of row: ";
	for (int i = 0; i < V.len; i++)
		in >> V.vect[i];
	return in;
}