#include <iostream>
#include "ComplexClass.h"

using namespace std;


Complex::Complex(int a, int b)
{
	re = a;
	im = b;
}

Complex::Complex(const Complex& c)
{
	re = c.re;
	im = c.im;
};

Complex & Complex::operator=(const Complex & c)
{
	re = c.re;
	im = c.im;

	return *this;
};

Complex Complex::operator+(const Complex& c) {
	return Complex(re + c.re, im + c.im);
};

Complex Complex::operator-(const Complex& c) {
	return Complex(re - c.re, im - c.im);
};

Complex Complex::operator*(const Complex& c) {
	return Complex((re * c.re - im * c.im), (c.re * im + re * c.im));
};

std::ostream& operator<<(ostream& os, const Complex& c) {
	os << c.re << " + " << c.im << "i";
	return os;
};