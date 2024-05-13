#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Product {
	std::string Name;
	int Quantity;
	double Cost;
public:
	Product(std::string Name, int Quantity, double Cost);
	void Print_Prod();
	friend ostream& operator<<(ostream& os, const Product& prod);
	friend class Check;
	friend class Cash_Register;
};


class Cash_Register {
	vector <Product> Stock;
	vector <std::string> Catalog;
public:
	Cash_Register() {
		Catalog = {"Bread", "Banana", "Milk", "Fish", "Egg", "Meat", "Hot Dog" };
		Stock.push_back(Product("Bread", 100, 5.0));
		Stock.push_back(Product("Banana", 100, 2.0));
		Stock.push_back(Product("Milk", 100, 3.0));
		Stock.push_back(Product("Fish", 100, 4.0));
		Stock.push_back(Product("Egg", 1000, 1.0));
		Stock.push_back(Product("Meat", 1000, 1.0));
		Stock.push_back(Product("Hot Dog", 1000, 1.0));
	}
	bool In_Catalog(std::string Name);
	void Delete_Product(std::string Name);
	void Add_Product(std::string name, int quantity_in_stock, double cost);
	int Find_Product(std::string Name);
	friend class Product;
	friend class Check;
};

void File_Input(std::string file_name, Cash_Register* CR, Check* C);