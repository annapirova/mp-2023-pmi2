#include "data.h"
#include <iostream>

int main()
{
	data d1, d2;
	int d, m, y;
	std::cin >> d;
	std::cin >> m;
	std::cin >> y;
	d1.vvod(d, m, y);
	d2.vvod(13, 2, 2024);
	d1.print();
	d2.print();
	d2.sum(d1);
	d2.print();
}