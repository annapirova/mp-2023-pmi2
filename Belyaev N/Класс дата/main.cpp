#include "date.h"
#include <iostream>

int main()
{
	Date date1, date2;
	int d, m, y;
	std::cin >> d;
	std::cin >> m;
	std::cin >> y;
	date1.Set(10, 4, 2024);
	date2.Set(d, m, y);
	date1.Print();
	date2.Print();
	date1.AddToDate(10, 1, 30);
	date1.Print();
	date2.SumDate(date1);
	date2.Print();
}