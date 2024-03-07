#pragma once
#ifndef COMPLEX__
#define COMPLEX__


class Complex
{
	int re;
	int im;
public:
	Complex(int a, int b);
	Complex(const Complex& c);

	Complex Plus(const Complex& c);
	Complex Minus(const Complex& c);
	Complex Multi(const Complex& c);
	void Print();
};

#endif