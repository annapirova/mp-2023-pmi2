#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <locale>
#include "Shop.h"
#include "Product.h"
#include "Check.h"
#include <iomanip>
#include <fstream>
#include <sstream>


Check::Check()
{
}

Check::~Check()
{
}

void Check::AddCheck(string Name, int new_count, Shop* m)
{
	Product t = m->FindProd(Name);
	t.count = new_count;

	bool found = false;
	for (auto it = Ch.begin(); it != Ch.end(); it++)
	{
		if (t.Name == it->Name)
		{
			it->count += t.count;
			found = true;
			break;
		}
	}

	if (!found)
	{
		Ch.push_back(t);
	}
}

void Check::Print()
{
	double sum = 0;
	ofstream out("Check.txt");

	out << "Name					Count						Old_Price					New_Price" << endl;
	for (auto it = Ch.begin(); it != Ch.end(); it++)
	{
		double New_Price = ((*it).price - ((*it).price * ((*it).discount / 100.0)));
		out << setw(25) << left << (*it).Name << setw(25) << (*it).count << setw(25) << (*it).price << setw(25) << New_Price << endl;
		sum += ((*it).count * New_Price);
	}
	out << "Sum:  " << sum << endl;
	out.close();
}

void Check::Parsing(string str, Shop* m)
{

	const string symbols = " ,";
	size_t start = str.find_first_not_of(symbols);
	size_t end = 0;

	while (start != std::string::npos)
	{	
		if (isdigit(str[start]))
		{
			end = str.find_first_of(symbols, start + 1);
			if (end == std::string::npos)
			{
				end = str.length();
			}

			string count_str = str.substr(start, end - start);
			int count = std::stoi(count_str);

			size_t prod_start = str.find_first_not_of(symbols, end + 1);
			size_t prod_end = str.find_first_of(symbols, prod_start);
			string prod_name = str.substr(prod_start, prod_end - prod_start);

			AddCheck(prod_name, count, m);

			start = end;
		}

		start = str.find_first_not_of(symbols, start + 1);
	}
}

//"Good afternoon, I would like to buy 2 Bread, 3 Tomatoes and 1 Pineapple with 321 Bananas"
//"2 Bread, 3 Tomatoes and 1 Pineapple"