#pragma once
#include <iostream>
#include <math.h>
using namespace std;

class Fraction {
	int numerator;
	int denominator;
public:
	Fraction(int c=1, int zh=1);
	void SetFraction(int ch, int zh);
	void FractionSum(Fraction A,Fraction D);
	void FractionDif(Fraction A, Fraction D);
	int GeneralDenominator(Fraction A,Fraction D);
	void Print();
};