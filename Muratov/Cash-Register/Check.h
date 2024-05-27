#pragma once
#include "Cash_Register.h";

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