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
		Stock.push_back(Product("Bread", 100, 5.0));
		Catalog.push_back("Bread");
		Stock.push_back(Product("Banana", 100, 2.0));
		Catalog.push_back("Banana");
		Stock.push_back(Product("Milk", 100, 3.0));
		Catalog.push_back("Milk");
		Stock.push_back(Product("Fish", 100, 4.0));
		Catalog.push_back("Fish");
		Stock.push_back(Product("Egg", 1000, 1.0));
		Catalog.push_back("Egg");
		Stock.push_back(Product("Meat", 1000, 1.0));
		Catalog.push_back("Meat");
		Stock.push_back(Product("Hot Dog", 1000, 1.0));
		Catalog.push_back("Hot Dog");
	}
	bool In_Catalog(std::string Name);
	void Add_Product(std::string name, int quantity_in_stock, double cost);
	int Find_Product(std::string Name);
	friend class Product;
	friend class Check;
};


class Check {
	vector <Product> Prod;
public:
	void String_Processing(std::string booking, Cash_Register* C);
	std::string Add_Prod_In_Check(std::string Name, int Quantity, Cash_Register* C);
	void Print_Check();
	void File_Output(std::string file_name, Check* C, Cash_Register* CR);
	vector <pair <std::string, double>> Sort_Check(Check* C);
	friend class Product;
	friend class Cash_Register;
};

void File_Input(std::string file_name, Cash_Register* CR, Check* C);