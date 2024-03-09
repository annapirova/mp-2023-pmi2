#include "Complex.h"

#include <iostream>

Complex::Complex(int a, int b)
{
	re = a;
	im = b;
}

Complex::Complex(const Complex& c)
{
	re = c.re;
	im = c.im;
}

Complex Complex::Plus(const Complex& c)
{
	return Complex(re + c.re, im + c.im);
}

Complex Complex::Minus(const Complex& c)
{
	return Complex(re - c.re, im - c.im);
}

Complex Complex::Multi(const Complex& c)
{
	return Complex((re * c.re - im * c.im), (c.re * im + re * c.im));
}

void Complex::Print()
{
	std::cout << re << " + " << im << "i" << std::endl;
}