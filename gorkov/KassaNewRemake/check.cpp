#include "check.h"
#include <iostream>
Check::Check() {};
Check::~Check() {};
void Check::add(const std::string& name, const int& qty) 
{
	Item tmpItem(name, rand(), qty);
	auto iter = find(goods.begin(), goods.end(), tmpItem);
	if (iter != goods.end()) 
	{
		(*iter).add(qty);
	}
	else
	{
		goods.emplace_back(tmpItem);
	}

};

void Check::remove(const std::string& name) 
{	
	Item tmpItem(name, rand(), 0);
	auto s = find(goods.begin(), goods.end(), tmpItem);
	goods.erase(s);
};

void Check::print() const 
{
	for (auto it:goods)
	{
		std::cout << it;
	}
};
