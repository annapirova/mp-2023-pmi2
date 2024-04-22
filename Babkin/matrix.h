#pragma once
#include <iostream>
#include "vector.h"
using namespace std;
class matrix
{
	private:
	int size,sizex; 
	vector* matr;
	public:
		matrix(int _size = 3,int _sizex = 4) { 
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
		matrix(const matrix &othl)
		{
			size = othl.size;
			sizex = othl.sizex;
			matr = new vector[size];
			for (int u = 0; u < size; u++)
			{
				matr[u] = vector(sizex);
			}
			memcpy(matr, othl.matr, sizeof(vector)* sizex);
		}
		double& operator()(const int i,const int x)
		{
			return matr[i][x];
		}
		const double& operator() (const int i,const int x) const
		{
			return matr[i][x];
		}
		matrix& operator=(const matrix& p)

		{
			if (this != &p)
			{
				size = p.size;
				sizex = p.sizex;
				matr = new vector(size);
				for (int u = 0; u < size; u++)
				{
					matr[u] = vector(sizex);
				}
			}
			memcpy(matr, p.matr, sizeof(vector) * sizex);
			return *this;
		}
		matrix& operator+=(const matrix& y)
		{
			for (int u = 0; u < size; u++)
			{
				for (int h = 0;h < sizex;h++)
				{
					matr[u][h] += y.matr[u][h];
				}
			}
			return *this;
		}
		matrix& operator-=(const matrix& y)
		{
			for (int u = 0; u < size; u++)
			{
				for (int h = 0;h < sizex;h++)
				{
					matr[u][h] -= y.matr[u][h];
				}
			}
			return *this;
		}
		matrix& operator*=(double& y)
		{
			for (int u = 0; u < size; u++)
			{
				for (int h = 0; h<sizex;h++)
				{
					matr[u][h] *= y;
				}
			}
			return *this;
		}
		friend ostream& operator<<(ostream& vout,const matrix& Imma)
		{
			for (int i = 0; i < Imma.size; i ++)
			{
				for (int u = 0; u < Imma.sizex; u++)
				{
					vout << Imma.matr[i][u] << " ";
				}
				vout << "\n";
			}
			return vout;
		}
		friend istream& operator>>(istream& vin,const matrix& Imma)
		{
			for (int i = 0; i < Imma.size; i++)
			{
				for (int ox = 0; ox < Imma.sizex; ox++)
				{
					vin >> Imma.matr[i][ox];
				}
			}
			return vin;
		}
};
