#include "Matrix.h"
#include <iostream>

using namespace std;

int main()
{
	Matrix M1(2, 3);
	M1.Generate(2,10);
	cout << "Matrix 1:" << endl << M1 << endl;

	Matrix M2(3, 5);
	M2.Generate(5, 10);
	cout << "Matrix 2:" << endl << M2 << endl;

	Matrix sum = M1 + M2;
	cout << "Sum:" << endl << sum << endl;

	Matrix umnoj = M1 * M2;
	cout << "Umnoj:" << endl << umnoj << endl;
}