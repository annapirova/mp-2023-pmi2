#pragma once
#include "math.h"
class trian_gh
{
	private:
		int a, b, c;
	public:
		trian_gh(int a_, int b_, int c_) { a = a_; b = b_; c = c_; }
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
			if (cosl > 0)
			{
				sinl = sqrt(1 - cosl * cosl);
			}
			else
			{
				sinl = -1 * sqrt((1 - cosl * cosl));
			}
			return s = a * b * sinl;
		};
};