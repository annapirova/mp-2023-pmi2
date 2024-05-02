#pragma once
#ifndef GAUSS__
#define GAUSS__
#include "Matrix.h"
#include "Vector.h"
#include <iostream>

class Gauss
{
	int status;
	Matrix* A;
	Vector* res;
	Vector* b;
	Matrix Z;
	Vector swsw;
public:
	Gauss(Matrix* myA, Vector* myx, Vector* myb);
	friend std::ostream& operator<<(std::ostream& os, const Gauss& G);
	void Solve();
	double Check();
	friend class Vector;
	friend class Matrix;
};
#endif
