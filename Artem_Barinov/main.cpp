#include "MVecClass.h"

int main() {
	Matrix matrix, smatr;
	std::cin >> matrix; smatr = matrix;
	std::cout << matrix << std::endl;

	Vector vect(3);
	std::cin >> vect;
	Vector sv(vect);

	matrix = Gaus(matrix, vect);
	std::cout << matrix << std::endl;
	std::cout << vect << std::endl;
	ReGaus(matrix, vect);

	GSolCheck(smatr, vect, sv);
	return 0;
}