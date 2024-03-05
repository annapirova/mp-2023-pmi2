#include <iostream>
#include "trian_gh.h"
using namespace std;
int main()
{
	int choice;
	trian_gh g(1.7, 6.8, 9.1);
	double x = g.S();
	double y = g.p();
	cout << "Choose an option to know about Perimeter(1) or Area(2)";
	cout << "\n";
	cin >> choice;
	cout << "\n";
	switch (choice)
	{
		case(1): cout << y; break;
		case(2): cout << x; break;
		default: cout << "sorry no matches to your search";
	}
}
