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
	vector<Product> sklad;
public:
	friend class Product;
	friend class Shop;
	Shop();
	~Shop();
	void Sklad();
	Product Findproduct(string name);
	void Addproduct(string name, int ID, Category category, double price, double discount, int count);
	void Print();
};
#endif