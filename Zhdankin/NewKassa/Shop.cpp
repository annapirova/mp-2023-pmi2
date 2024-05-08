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

void Shop::ALL_PROD()
{
	Storage.push_back(Product("Pineapple", 1111, CATEGORY::Fruits, 400.0, 35.0, 2));
	Storage.push_back(Product("Tomatoes", 2222, CATEGORY::Vegetables, 120.0, 42.0, 10));
	Storage.push_back(Product("Bananas", 3333, CATEGORY::Fruits, 80.0, 10.0, 30));
	Storage.push_back(Product("Bread", 4444, CATEGORY::Grocery, 55.0, 5.0, 38));
	Storage.push_back(Product("Milk", 5555, CATEGORY::Dairy, 156.0, 8.0, 22));
}

Product Shop::FindProd(string Name)
{
	Product target(Name);
	vector<Product>::iterator it;
	
	for (it = Storage.begin(); it != Storage.end(); it++)
	{
		if (*it == target)
		{
			return *it;
		}
	}

	return Product();
}

void Shop::AddStorage(string Name, int ID, CATEGORY category, double price, double discount, int count)
{
	Product tmp(Name, ID, category, price, discount, count);
	Storage.push_back(tmp);
}

void Shop::Print()
{
	for (auto it = Storage.begin(); it != Storage.end(); it++)
	{
		std::cout << *it << std::endl;
	}
}
