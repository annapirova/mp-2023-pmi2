#pragma once
#include <iostream>
using namespace std;
class vector
{
	private:
	int size; 
	double* vect;
	public:
		vector(int _size = 3) { 
			size = _size; 
			vect = new double[size];
		}
		~vector()
		{
			delete[] vect;
		}
		vector(const vector &othl)
		{
			size = othl.size;
			vect = new double[size];
			memcpy(vect, othl.vect, sizeof(double) * size);
		}
		double& operator[](const int i)
		{
			return vect[i];
		}
		const double& operator[] (const int i) const
		{
			return vect[i];
		}
		vector& operator=(const vector& p)

		{
			if (this != &p)
			{
				size = p.size;
				vect = new double[size];
			}
			memcpy(vect, p.vect, sizeof(double) * size);
			return *this;
		}
		vector& operator+=(const vector& y)
		{
			for (int u = 0; u < size; u++)
			{
				vect[u] += y.vect[u];
			}
			return *this;
		}
		vector& operator-=(const vector& y)
		{
			for (int u = 0; u < size; u++)
			{
				vect[u] -= y.vect[u];
			}
			return *this;
		}
		vector& operator*=(double& y)
		{
			for (int u = 0; u < size; u++)
			{
				vect[u] *= y;
			}
			return *this;
		}
		friend ostream& operator<<(ostream& vout,const vector& Imma)
		{
			for (int i = 0; i < Imma.size; i ++)
			{vout << Imma.vect[i];}
			return vout;
		}
		friend istream& operator>>(istream& vin,const vector& Imma)
		{
			for (int i = 0; i < Imma.size; i ++)
			{vin >> Imma.vect[i];}
			return vin;
		}
};
