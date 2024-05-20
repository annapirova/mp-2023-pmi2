using namespace std;
#include <iostream>
#include "matrix.h"
#include <locale.h>
#include <random>
#include <ctime>


int main() {
	setlocale(LC_CTYPE, "Rus");
	double x;
	Matrix A(5, 5), B(5, 5), C, D, M3, M4, E;
	srand(time(NULL));
	cout << "GENERATE" << endl;
	cout << endl;
	A.RandomMatrix();
	B.RandomMatrix();
	cout << A << B << endl;
	cout << "OPERATOR + AND +=" << endl;
	cout << endl;
	B += A;
	cout << B << endl;
	E = B + A;
	cout << E << endl;
	cout << "OPERATOR - AND -=" << endl;
	cout << endl;
	B -= A;
	cout << B << endl;
	C = E - A;
	cout << C << endl;
	cout << "OPERATOR *" << endl;
	cout << endl;
	cin >> M3;
	cin >> M4;
	D = M3 * M4;
	cout << D << endl;
	cout << "OPERATOR ()" << endl;
	cout << endl;
	cin >> D;
	cout << D(0, 0) << endl;
	cout << "Input x:  ";
	cin >> x;
	cout << D(0, 0) + x;
}
