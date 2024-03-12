#include <iostream>
#include "Header.h"

int main() {
	Complex c1(10, 3);
	Complex c2(12, 4);
	std::cout << "Complex: " << c1.GetA() << " + " << c1.GetB() << "i" << std::endl;
	std::cout << "Complex: " << c2.GetA() << " + " << c2.GetB() << "i\n" << std::endl;
	std::cout << "Summe of two complex numbers: " << c1.Sum_DiffA(c1.GetA(), c2.GetA(), '+') << " + " << c1.Sum_DiffB(c1.GetB(), c2.GetB(), '+') << "i" << std::endl;
	std::cout << "Difference of two complex numbers: " << c1.Sum_DiffA(c1.GetA(), c2.GetA(), '-') << " + " << c1.Sum_DiffB(c1.GetB(), c2.GetB(), '-') << "i\n" << std::endl;
	std::cout << "Product of two complex numbers: " << c1.MltplyA(c1.GetA(), c1.GetB(), c2.GetA(), c2.GetB()) << " + " << c1.MltplyB(c1.GetA(), c1.GetB(), c2.GetA(), c2.GetB()) << "i\n";
	return 0;
}