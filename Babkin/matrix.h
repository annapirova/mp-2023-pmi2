#pragma once
#include <iostream>
#include "vector.h"
using namespace std;
class matrix
{
private:
	int size, sizex;
	vector* matr;
public:
	matrix(int _size = 3, int _sizex = 4) {
		size = _size;
		sizex = _sizex;
		matr = new vector[size];
		for (int u = 0; u < size; u++)
		{
			matr[u] = vector(sizex);
		}
	}
	~matrix()
	{
		delete[] matr;
	}
	matrix(const matrix& othl)
	{
		size = othl.size;
		sizex = othl.sizex;
		matr = new vector[size];
		for (int u = 0; u < size; u++)
		{
			matr[u] = othl.matr[u];
		}
	}
	double& operator()(const int i, const int x)
	{
		return matr[i][x];
	}
	const double& operator() (const int i, const int x) const
	{
		return matr[i][x];
	}
	matrix& operator=(const matrix& p)
	{
		if (this != &p)
		{
			if (size != p.size && sizex != p.sizex)
			{
				size = p.size;
				sizex = p.sizex;
			}
			matr = new vector(sizex);
			for (int u = 0; u < size; u++)
			{
				matr[u] = p.matr[u];
			}
		}
		
		return *this;
	}
	matrix& operator+=(const matrix& y)
	{
		for (int u = 0; u < size; u++)
		{
			matr[u] += y.matr[u];
		}
		return *this;
	}
	matrix& operator-=(const matrix& y)
	{
		for (int u = 0; u < size; u++)
		{
			matr[u] -= y.matr[u];
		}
		return *this;
	}
	matrix& operator*=(double& y)
	{
		for (int u = 0; u < size; u++)
		{
			matr[u] *= y;
		}
		return *this;
	}
	friend ostream& operator<<(ostream& vout, const matrix& Imma)
	{
		for (int i = 0; i < Imma.size; i++)
		{
			vout << Imma.matr[i] << " ";
			vout << "\n";
		}
		return vout;
	}
	friend istream& operator>>(istream& vin, const matrix& Imma)
	{
		for (int i = 0; i < Imma.size; i++)
		{
			vin >> Imma.matr[i];
		}
		return vin;
	}
	friend vector operator*(const matrix& somb, const vector& inc)
	{
		vector res;
		for (int t = 0; t < somb.size; t++) // по строкам матр
		{
			res[t] = (inc *= somb.matr[t]);
		}
		return res;
	}
};
