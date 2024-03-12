#pragma once
class vector
{
	private:
	int size; double* vect = new double[size];
	public:
		vector(int _size, double* _vect) { size = _size; vect = _vect;}
		void set(int index, double value)
		{
			vect[index] = value;
		}
		double& operator[](const int i)
		{
			return vect[i];
		}
		const double& operator[] (const int i) const
		{
			return vect[i];
		}
};