#include "data.h"
#include <iostream>

void data::res()
{
	day = 1;
	month = 1;
	year = 2000;
}
void data::vvod(int d, int m, int y)
{
	day = d;
	month = m;
	year = y;
}
void data::print()
{
	std::cout << day << "." << month << "." << year << std::endl;
}
void data::sum(const data& h)
{
	day = day + h.day;
	month = month + h.month;
	year = year + h.year;
}
