#include <iostream>
#include "matr_class.h"
#include "Class.h"

int getrow(std::string str) {
	bool flag = 0;
	int num;
	do {
		std::cout << str <<": ";
		if ((std::cin >> num).good() != 1)
			std::cout << "Invalid character! Try again!\n";
		else {
			if (num >= 0 && num < 10)
				flag = 1;
			else
				std::cout << "Invalid range! Try again!\n";
		}
	} while (!flag);
	return num;
}
char getOr() {
	bool flag = 0;
	char ch;
	do {
		std::cout << "Orientation: ";
		std::cin >> ch;
		if (ch == 'E' || ch == 'W' || ch == 'S' || ch == 'N')
			flag = 1;
		else
			std::cout << "Wrong simbol! Try again!\n";
	} while (!flag);
	return ch;
}

void GetShipField(Field& field) {
	int maxships = 0;
	std::cout << "\nYou have to set up your ships.\nFirst - coordinates of the ship's bow;\nSecond - Where is the tail of the ship oriented (East, West, South or North);\n";
	int i = 4; int j = 1;
	while (i > 0) {			
		for (int k = 0; k < j; k++)	{
			std::cout << "\n" << i << "-ship`s bow coordinates:\n";
			int row, column;
			row = getrow("Row");
			column = getrow("Column");

			std::cout << "Where is the tail of the ship oriented (W, E, S, N)?\n";
			char orientation = getOr();
			bool flag = field.shipToField(row, column, i, orientation, field);
			if (!flag) {
				std::cout << "Wrong position of ship! Try again!\n";
				k--;
			}
		}
		j++;
		i--;
	}
}