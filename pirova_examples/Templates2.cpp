#include <iostream>

template <class T>
class Vector
{
private:
	T* vec;
	int size;
public:
	Vector(int s) : size(s)
	{
		vec = new T [size];
	}

	~Vector()
	{
		delete[] vec;
	}

	void print()
	{
		for (int i = 0; i < size; i++)
			std::cout << vec[i] << " ";
		std::cout << "\n";
	}

	T& operator[](int i)
	{
		return vec[i];
	}
};

// специализация метода
template <>
void Vector<bool>::print() 
{
	for (int i = 0; i < size; i++)
		if (vec[i])
			std::cout << '1 ';
		else std::cout << '0 ';
	std::cout << "\n";
}

// полная специализация класса
template <>
class Vector<char>
{
private:
	char* vec;
	int size;
public:
	Vector(int s) : size(s)
	{
		vec = new char[size + 1];
	}

	~Vector()
	{
		delete[] vec;
	}

	void print()
	{
		for (int i = 0; i < size; i++)
			std::cout << vec[i];
		std::cout << "\n";
	}

	char& operator[](int i)
	{
		return vec[i];
	}
};

// шаблон с двумя параметрами
template <class T, int size>
class SVector
{
private:
	T* vec;
public:
	SVector(int s) 
	{
		vec = new T[size];
	}

	~SVector()
	{
		delete[] vec;
	}

	void print()
	{
		for (int i = 0; i < size; i++)
			std::cout << vec[i] << " ";
		std::cout << "\n";
	}

	T& operator[](int i)
	{
		return vec[i];
	}
};

// частичная спецификация шаблона
template <int size>
class SVector<char, size>
{
private:
	char* vec;
public:
	SVector(int s = 1)
	{
		vec = new char[size + 1];
	}

	~SVector()
	{
		delete[] vec;
	}

	void print()
	{
		for (int i = 0; i < size; i++)
			std::cout << vec[i] << " ";
		std::cout << "\n";
	}

	char& operator[](int i)
	{
		return vec[i];
	}
};

///////////////////////////////////////////////////////////////////////////////
void main()
{
	Vector<double> r(2);
	r[0] = 1.0;
	r[1] = 2.0;
	r.print();

	Vector<char> str(2);
	str[0] = 'a';
	str[1] = 'b';
	str.print();

	SVector<int, 2> v(2);
	v[0] = 2;
	v[1] = 3;

	SVector<char, 3> b;
	b[0] = 'x';
	b[1] = 'y';
	b[2] = 'z';
	b.print();
}