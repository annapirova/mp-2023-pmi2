#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <locale.h>
#include <sstream>
#include <fstream>
#include "Cash_Register.h"
#include "Check.h"




void split(const std::string& s, char delimiter, std::vector<std::string>& elems) {
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delimiter)) {
		elems.push_back(item);
	}
}


std::string To_Name_In_Catalog(std::string Name) {
	std::string word1 = "";
	for (int j = 0; j < Name.size(); j++) {
		if (j == 0) {
			word1 += std::toupper(Name[j]);
		}
		else {
			word1 += std::tolower(Name[j]);
		}
	}
	return word1;
}


ostream& operator<<(ostream& os, const Product& prod) {
	os << prod.Name << "................." << prod.Quantity << "...." << prod.Cost * prod.Quantity;
	return os;
}


std::string slice(std::string str, int start_index, int end_index) {
	std::string new_slice = "";
	end_index += str.size();
	for (int i = start_index; i < end_index; i++) {
		new_slice += str[i];
	}
	return new_slice;
}


void File_Input(std::string file_name, Cash_Register* CR, Check* C) {
	int qu = 0;
	std::string str;
	std::string name = "";
	vector <std::string> bkng;
	ifstream booking_file(file_name);
	while (getline(booking_file, str)) {
		split(str, ' ', bkng);
		for (int i = 0; i < bkng.size(); i++) {
			std::string word = To_Name_In_Catalog(bkng[i]);
			if (std::isalpha(bkng[i][0])) {
				if ((CR->In_Catalog(word))) {
					name = word;
				}
				else if (CR->In_Catalog(slice(word, 0, -1))) {
					name = slice(word, 0, -1);
				}
				else if (CR->In_Catalog(slice(word, 0, -2))) {
					name = slice(word, 0, -2);
				}
				else {
					for (int j = i + 1; j < bkng.size(); j++) {
						word += ' ' + To_Name_In_Catalog(bkng[j]);
						if ((CR->In_Catalog(word))) {
							name = word;
							i = j;
							break;
						}
						else if (CR->In_Catalog(slice(word, 0, -1))) {
							name = slice(word, 0, -1);
							i = j;
							break;
						}
						else if (CR->In_Catalog(slice(word, 0, -2))) {
							name = slice(word, 0, -2);
							i = j;
							break;
						}
					}
				}
			}
			else if (std::isdigit(bkng[i][0])) {
				qu = stoi(bkng[i]);
			}

			if ((qu != 0) && (name != "")) {
				C->Add_Prod_In_Check(name, qu, CR);
			}
		}
	}
}



vector <pair <std::string, double>> replace(vector <pair <std::string, double>> B) {
	int i, j;
	pair <std::string, double> tmp;
	for (i = 1; i < B.size(); ++i)
	{
		j = i;
		while ((j > 0) && (B[j - 1].second > B[j].second)) {
			tmp = B[j - 1];
			B[j - 1] = B[j];
			B[j] = tmp;
			j--;
		}
	}
	return B;
}


std::string Check::Add_Prod_In_Check(std::string Name, int Quantity, Cash_Register* C) {
	for (int i = 0; i < Prod.size(); i++) {
		if (Prod[i].Name == Name) {
			if (C->Stock[C->Find_Product(Name)].Quantity >= Quantity) {
				C->Stock[C->Find_Product(Name)].Quantity -= Quantity;
				Prod[i].Quantity += Quantity;
				return "OK";
			}
			else {
				return "Not OK";
			}
		}
	}
	if (C->Stock[C->Find_Product(Name)].Quantity >= Quantity) {
		C->Stock[C->Find_Product(Name)].Quantity -= Quantity;
		Product New(Name, Quantity, C->Stock[C->Find_Product(Name)].Cost);
		Prod.push_back(New);
		return "OK";
	}
}


void Check::Print_Check() {
	double summa = 0.0;
	for (int i = 0; i < Prod.size(); i++) {
		cout << Prod[i] << endl;
	}
	cout << endl;
	for (int i = 0; i < Prod.size(); i++) {
		summa += Prod[i].Cost * Prod[i].Quantity;
	}
	cout << "хрнц" << "........................." << summa;
}


void Check::String_Processing(std::string booking, Cash_Register* C) {
	vector <std::string> bkng;
	split(booking, ' ', bkng);
	for (int i = 0; i < bkng.size(); i += 2) {
		Add_Prod_In_Check(bkng[i], stoi(bkng[i + 1]), C);
	}
}


vector <pair <std::string, double>> Check::Sort_Check(Check* C) {
	vector <Product> check = C->Prod;
	vector <pair <std::string, double>> vector_for_sort;
	pair <std::string, double> position_in_check;
	for (int i = 0; i < check.size(); i++) {
		position_in_check.first = check[i].Name;
		position_in_check.second = check[i].Quantity * check[i].Cost;
		vector_for_sort.push_back(position_in_check);
	}
	return replace(vector_for_sort);
}


void Check::File_Output(std::string file_name, Check* C, Cash_Register* CR) {
	vector <pair <std::string, double>> Final_Check;
	double summa = 0.0;
	Final_Check = C->Sort_Check(C);
	ofstream output_check(file_name);
	for (int i = 0; i < Final_Check.size(); i++) {
		output_check << Final_Check[i].first << "..............." << Final_Check[i].second << endl;
		if (i == Final_Check.size() - 1) {
			output_check << endl;
		}
	}
	for (int i = 0; i < C->Prod.size(); i++) {
		summa += Final_Check[i].second;
	}

	output_check << "хрнц" << "........................." << summa;
}

