#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <locale>
#include "Shop.h"
#include "Product.h"
#include "Check.h"

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
	Ch.push_back(t);
}

void Check::Print()
{
	for (auto it = Ch.begin(); it != Ch.end(); it++)
	{
		std::cout << *it << std::endl;
	}
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

//"Good afternoon, I would like to buy 2 Bread, 3 Tomatoes and 1 Pineapple with 321123 Bananas"
//"2 Bread, 3 Tomatoes and 1 Pineapple"