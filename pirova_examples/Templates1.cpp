#include <iostream>

template <typename T> // объявление параметра шаблона функции
T max(T a, T b)
{
	return (a > b) ? a : b;
}

template <typename T> // объявление параметра шаблона функции
void swap(T& a, T& b) 
{
	T tmp = { a };
	a = b;
	b = tmp;
}


template <> // объявление параметра шаблона функции
void swap(char*& a, char*& b)
{
	char* tmp = new char[strlen(a)];
	strcpy(tmp, a);
	strcpy(a, b);
	strcpy(b, tmp);
}

void main1()
{
	int i = max(3, 5);
	int j = max(3.0, 3.5);

	char* line1 = new char[5];
	char* line2 = new char[5];
	strcpy(line1, "1234");
	strcpy(line2, "9876");
	swap(line1, line2);
	std::cout << line1 << " " << line2;
}


