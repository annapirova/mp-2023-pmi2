#include "Product.h"
#include "Check.h"
#include "Shop.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

void Menu()
{
	cout << "1. Product in shop" << endl;
	cout << "2. Add product on Sklad" << endl;
	cout << "3. Shopping list in file" << endl;
	cout << "4. Check" << endl;
	cout << "5. Exit" << endl;
	cout << endl;
}
int main()
{
	Shop Shop;
	Check Check;
	Shop.Sklad();
	int k = 0;
	while (k != 6)
	{
		Menu();
		cout << "Enter number:" << endl;
		cin >> k;
		switch (k)
		{
		case 1:
		{
			Shop.Print();
			cout << endl;
			break;
		}
		case 2:
		{
			string N;
			int ID, Count, Switch;
			Category Category1;
			double PRICE, DIS;
			cout << "Enter Product Name: ";
			cin >> N;
			cout << "Enter Product ID: ";
			cin >> ID;
			cout << "Enter Product Category(0 - Fruits, 1 - Vegetables, 2 - Berries, 3 - Dairy, 4 - Grocery): ";
			cin >> Switch;
			Category1 = static_cast<Category>(Switch);
			cout << "Enter Product Price: ";
			cin >> PRICE;
			cout << "Enter Product Discount: ";
			cin >> DIS;
			cout << "Enter Product Count: ";
			cin >> Count;
			Shop.Addproduct(N, ID, Category1, PRICE, DIS, Count);
			cout << endl;
			break;
		}
		case 3:
		{
			string line;
			ifstream in("shopping list.txt");

			if (in.is_open())
			{
				while (getline(in, line))
				{
					Check.Parsing(line, &Shop);
				}
			}
			in.close();
			cout << endl;
			break;
		}
		case 4:
		{
			Check.Print();
			cout << endl;
			break;
		}
		case 5:
		{
			return 0;
		}
		default:
			break;
		}
	}
	return 0;
}