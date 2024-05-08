#pragma once
#ifndef CHECK__
#define CHECK__
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Shop.h"
#include "Product.h"

using namespace std;

class Check
{
private:
	vector<Product> Ch;
public:
	friend class Product;
	friend class Shop;
	Check();
	~Check();

	void AddCheck(string Name, int count, Shop* m);
	void Print();
	void Parsing(string str, Shop* m);
};
#endif
