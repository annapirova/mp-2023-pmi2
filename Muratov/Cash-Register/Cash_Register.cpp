#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <locale.h>
#include <sstream>
#include <fstream>
#include "Cash_Register.h"
#include "Check.h"
using namespace std;


void Cash_Register::Add_Product(std::string Name, int Quantity_in_stock, double Cost) {
	Stock.push_back(Product(Name, Quantity_in_stock, Cost));
	Catalog.push_back(Name);
}


bool Cash_Register::In_Catalog(std::string Name) {
	for (int i = 0; i < Catalog.size(); i++) {
		if (Name == Catalog[i]) {
			return 1;
		}
	}
	return 0;
}


void Cash_Register::Delete_Product(std::string Name) {
	for (int i = 0; i < Stock.size(); i++) {
		if (Stock[i].Name == Name) {
			Stock.erase(Stock.begin() + i);
			Catalog.erase(Catalog.begin() + i);
		}
	}
}


int Cash_Register::Find_Product(std::string Name) {
	for (int i = 0; i < Stock.size(); i++) {
		if (Stock[i].Name == Name) {
			return i;
		}
	}
}


Product::Product(std::string Name, int Quantity, double Cost) :
	Name(Name), Quantity(Quantity), Cost(Cost) {};


void Product::Print_Prod() {
	cout << Name << "  " << Quantity << "  " << Cost << endl;
}
