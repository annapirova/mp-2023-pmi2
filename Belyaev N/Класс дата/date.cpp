#include "date.h"
#include <iostream>

void Date::Reset()
{
	day = 1;
	month = 1;
	year = 2000;
}


void Date::Set(int d, int m, int y)
{
	day = d;
	month = m;
	year = y;
}


void Date::Print()
{
	std::cout << day << "." << month << "." << year << std::endl;
}

void Date::SumDate(const Date& D)
{
	day = day + D.day;
	month = month + D.month;
	year = year + D.year;
}
void Date::AddToDate(int d, int m, int y)
{
	day += d;
	month += m;
	year += y;
}