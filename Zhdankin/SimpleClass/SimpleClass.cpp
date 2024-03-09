#include "Complex.h"

#include <iostream>


int main()
{
	Complex a(2, 5);
	Complex b(4, -6);

	Complex c = a.Plus(b);
	Complex d = c.Minus(b);
	Complex e = d.Multi(c);

	std::cout << "c = ";
	c.Print();
	std::cout << "d = ";
	d.Print();
	std::cout << "e = ";
	e.Print();

	return 0;
}