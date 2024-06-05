#pragma once
#include "math.h"
class trian_gh
{
	private:
		double a, b, c;
	public:
		trian_gh(double a_, double b_, double c_) { a = a_; b = b_; c = c_; }
		int p()
		{
			int P;
			return P = a + b + c;
		};
		double S()
		{
			double s;
			double cosl, sinl;
			cosl = (a * a + b * b - c * c) / (2 * a * b);
			sinl = sqrt(1 - cosl * cosl);
			return s = a * b * sinl;
		};
};
