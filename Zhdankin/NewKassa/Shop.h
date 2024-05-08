#pragma once
#ifndef SHOP__
#define SHOP__
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Product.h"

using namespace std;

class Shop
{
private:
	vector<Product> Storage;
public:
	friend class Product;
	friend class Shop;
	Shop();
	~Shop();

	void ALL_PROD();
	Product FindProd(string Name);
	void AddStorage(string Name, int ID, CATEGORY category, double price, double discount, int count);
	void Print();
};
#endif
