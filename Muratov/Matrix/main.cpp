using namespace std;
#include <iostream>
#include "matrix.h"
#include <locale.h>
#include <random>
#include <ctime>


int main() {
	setlocale(LC_CTYPE, "Rus");
	double x;
	Matrix M1(3, 6), M2(3, 3), A(2, 5), B(6, 3), C, D, M3, M4, E;
	srand(time(NULL));
	M1.RandomMatrix();
	cout << M1;
	M2.RandomMatrix();
	cout << M2;
	cout << "FIRST EX" << endl;
	cout << endl;
	A.RandomMatrix();
	B.RandomMatrix();
	B += A;
	cout << B << endl;
	E = B + A;
	cout << E;
	cout << "SECOND EX" << endl;
	cout << endl;
	B -= A;
	cout << B << endl;
	C = E - A;
	cout << C;
	cout << "THIRD EX" << endl;
	cout << endl;
	cin >> M3;
	cin >> M4;
	D = M3 * M4;
	cout << D;
	cout << "FOURTH EX" << endl;
	cout << endl;
	cin >> D;
	cout << D(0, 0) << endl;
	cout << "Input x:  ";
	cin >> x;
	cout << D(0, 0) + x;
}
