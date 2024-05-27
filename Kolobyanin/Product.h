#pragma once
#ifndef PRODUCT__
#define PRODUCT__
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Product.h"

using namespace std;
enum class Category { Fruits, Vegetables, Berries, Dairy, Grocery };

class Product
{
private:
	int ID;
	string name;
	Category category;
	double price;
	double discount;
	int count;
public:
	Product(string name, int ID, Category category, double price, double discount, int count);
	Product();
	Product(string name);
	Product(const Product& other);
	~Product();
	string GetName() const;
	int GetID() const;
	Category GetCategory() const;
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
	friend class Shop;
	friend class Check;
};
#endif