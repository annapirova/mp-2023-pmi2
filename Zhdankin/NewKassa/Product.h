#pragma once
#ifndef PRODUCT__
#define PRODUCT__
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Product.h"

using namespace std;
enum class CATEGORY{ Fruits, Vegetables, Berries, Dairy, Grocery };

class Product
{
private:
	int ID;
	string Name;
	CATEGORY category;
	double price;
	double discount;
	int count;
public:
	Product(string Name, int ID, CATEGORY category, double price, double discount, int count);
	Product();
	Product(string Name);
	Product(const Product& other);
	~Product();

	friend class Shop;
	friend class Check;

	string GetName() const;
	int GetID() const;
	CATEGORY GetCategory() const;
	double GetPrice() const;
	double GetDiscount() const;
	int GetCount() const;
	string CategoryString() const;

	friend ostream& operator<<(ostream& os, const Product& other);
	Product& operator++();
	bool operator==(const Product& other);
	bool operator<(const Product& other);
	Product operator+(const Product& other);
	Product operator-(const Product& other);
};
#endif
