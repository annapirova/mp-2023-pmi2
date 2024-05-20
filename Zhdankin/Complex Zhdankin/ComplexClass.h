#pragma once
#ifndef COMPLEX__
#define COMPLEX__
#include <iostream>

using namespace std;

class Complex
{
	int re;
	int im;
public:
	Complex(int a, int b);
	Complex(const Complex& c);

	Complex& operator=(const Complex& c);

	Complex operator+(const Complex& c);
	Complex operator-(const Complex& c);
	Complex operator*(const Complex& c);

	friend ostream& operator<<(ostream& os, const Complex& c);
};
#endif