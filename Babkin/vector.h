#pragma once
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
		vector(vector& other);
		double& operator[](const int i)
		{
			return vect[i];
		}
		const double& operator[] (const int i) const
		{
			return vect[i];
		}
		double& operator=(const vector i)
		{
			return i;
		}
		const double& operator=(const vector i) const
		{
			return i;
		}

};
