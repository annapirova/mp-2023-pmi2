#include <iostream>
#include "trian_gh.h"
using namespace std;
int main()
{
	trian_gh g(10, 4, 5), g2(g);
	double x = g.S();
	cout << x;
}