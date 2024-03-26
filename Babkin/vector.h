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
		vector(const vector& othl)
		{
			size = othl.size;
			vect = othl.vect;

		}
		double& operator[](const int i)
		{
			return vect[i];
		}
		const double& operator[] (const int i) const
		{
			return vect[i];
		}
		vector& operator==(const vector& i)
		{
			if (this != &i)
			{
				size = i.size;
				vect = i.vect;
			}
			return *this;
		}
};
