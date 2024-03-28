#include "matrix.h"
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

int main()
{
	srand(time(NULL));
	Matrix matrix1(2, 4);
	matrix1.Generate(3.0, 10.0);
	cout << "Matrix 1:" << endl << matrix1 << endl;
	Matrix matrix2(4, 6);
	matrix2.Generate(6.0, 10.0);
	cout << "Matrix 2:" << endl << matrix2 << endl;
	Matrix summa = matrix1 + matrix2;
	cout << "Summa:" << endl << summa << endl;
	Matrix proizvedenie = matrix1 * matrix2;
	cout << "Proizvedenie:" << endl << proizvedenie << endl;
}