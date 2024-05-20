#include "Triangle.h"
Triangle::Triangle(double valueA, double valueB, double valueC)
{
	a = valueA;
	b = valueB;
	c = valueC;
}
double  Triangle::Perimeter(double a, double b, double c)
{
	double sum = 0.0;
	sum = a + b + c;
	return sum;
}
double Triangle::Square(double a, double b, double c, double Perimeter)
{
	double square = 0.0;
	square = pow(Perimeter * (Perimeter - a) * (Perimeter - b) * (Perimeter - c), 0.5);
	return square;
}
void Triangle::PrintPS()
{
	std::cout << "Периметр треугольника: " << Perimeter(a, b, c) << "\nПлощадь треугольника: " << Square(a, b, c, Perimeter(a, b, c)) << std::endl;
}
