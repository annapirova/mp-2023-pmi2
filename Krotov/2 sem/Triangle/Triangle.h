#pragma once
#include <iostream>
class Triangle
{
	double a, b, c;
public:
	Triangle(double valueA, double valueB, double valueC);
	double Perimeter(double a, double b, double c);
	double Square(double a, double b, double c, double Perimeter);
	void PrintPS();
};
