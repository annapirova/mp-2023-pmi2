#include "item.h"
#include "check.h"
#include <iostream>
#include <string>

int main() {
    std::string name;
    int qty;
    Check myCheck;
	int k;
	do
	{
		std::cout << "Enter number: 1-add in check, 2-remove from check 3-print check 0-out" << std::endl;
		std::cin >> k;
		switch (k)
		{
		case 1:
		{	std::cout << "Enter name and quantity\n";
			std::cin >> name >> qty;
			if (qty <= 0) { break; }
			myCheck.add(name, qty);
			break;
		}
		case 2:

		{	std::cout << "Enter name" << std::endl;
			std::cin >> name;
			myCheck.remove(name);
			break;
		}
		case 3:
		{
			myCheck.print();
			break;
		}
		default:
		{
			if (k != 0)
			{
				std::cout << "wrong operation" << std::endl;
			}
			break;
		}
		}
	} while (k != 0);
   
}
