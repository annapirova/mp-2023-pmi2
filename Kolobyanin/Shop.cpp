#include "Shop.h"
#include "Product.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Shop::Shop()
{
}

Shop::~Shop()
{
}

void Shop::Sklad()
{
	sklad.push_back(Product("Banana", 45, Category::Fruits, 100.0, 15.0, 10));
	sklad.push_back(Product("Cucumber", 52, Category::Vegetables, 50.0, 42.0, 8));
	sklad.push_back(Product("Kiwi", 101, Category::Fruits, 150.0, 19.0, 2));
	sklad.push_back(Product("Bread", 3, Category::Grocery, 35.0, 7.0, 15));
	sklad.push_back(Product("Yogurt", 87, Category::Dairy, 110.0, 10.0, 20));
}

Product Shop::Findproduct(string Name)
{
	Product target(Name);
	vector<Product>::iterator it;

	for (it = sklad.begin(); it != sklad.end(); it++)
	{
		if (*it == target)
		{
			return *it;
		}
	}

	return Product();
}

void Shop::Addproduct(string name, int ID, Category category, double price, double discount, int count)
{
	Product tmp(name, ID, category, price, discount, count);
	sklad.push_back(tmp);
}

void Shop::Print()
{
	for (auto it = sklad.begin(); it != sklad.end(); it++)
	{
		std::cout << *it << std::endl;
	}
}