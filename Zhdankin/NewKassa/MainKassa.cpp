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
	cout << "1. Print Storage" << endl;
	cout << "2. Add New Product in Storage" << endl;
	cout << "3. Add New Product to Cart" << endl;
	cout << "4. Add New Product to Cart From File" << endl;
	cout << "5. Parse String" << endl;
	cout << "6. Print Check" << endl;
	cout << "7. Exit" << endl;
	cout << endl;
}

//string parse = "Good afternoon, I would like to buy 2 Bread, 3 Tomatoes and 1 Pineapple with 1 Pineapple";

int main()
{
	Shop Mag;
	Check CH;
	Mag.ALL_PROD();

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
			Mag.Print();
			cout << endl;
			break;
		}
		case 2:
		{
			string N;
			int ID, COUNT, CatSwitch;
			CATEGORY CAT;
			double PRICE, DIS;

			cout << "Enter Product Name: ";
			cin >> N;
			cout << "Enter Product ID: ";
			cin >> ID;
			cout << "Enter Product Category(0 - Fruits, 1 - Vegetables, 2 - Berries, 3 - Dairy, 4 - Grocery): ";
			cin >> CatSwitch;
			CAT = static_cast<CATEGORY>(CatSwitch);
			cout << "Enter Product Price: ";
			cin >> PRICE;
			cout << "Enter Product Discount: ";
			cin >> DIS;
			cout << "Enter Product Count: ";
			cin >> COUNT;

			Mag.AddStorage(N, ID, CAT, PRICE, DIS, COUNT);
			cout << endl;
			break;
		}
		case 3:
		{
			string NAME;
			int COUNT;
			cout << "Enter Name:" << endl;
			cin >> NAME;
			cout << "Enter count:" << endl;
			cin >> COUNT;

			CH.AddCheck(NAME, COUNT, &Mag);
			cout << endl;
			break;
		}
		case 4:
		{
			string line;
			ifstream in("List.txt");
			
			if (in.is_open())
			{
				while (getline(in, line))
				{
					CH.Parsing(line, &Mag);
				}
			}
			in.close();
			cout << endl;
			break;
		}
		case 5:
		{
			cout << "Enter String to Parse" << endl;
			string str;
			cin.ignore();
			getline(cin, str);

			CH.Parsing(str, &Mag);
			cout << endl;
			break;
		}
		case 6:
		{
			CH.Print();
			cout << endl;
			break;
		}
		case 7:
		{
			return 0;
		}
		default:
			break;
		}
	}

	return 0;
}
