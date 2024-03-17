using namespace std;
#include <iostream>
#include "matrix.h"
#include <locale.h>
#include <random>
#include <ctime>


int main() {
	setlocale(LC_CTYPE, "Rus");
	double x;
	Matrix M1(3, 6), M2(3, 3), A, B, C, D, M3, M4;
	srand(time(NULL));
	M1.RandomMatrix();
	cout << M1;
	M2.RandomMatrix();
	cout << M2;
	cout << "FIRST EX" << endl;
	cout << endl;
	B += A;
	cout << B;
	cout << "SECOND EX" << endl;
	cout << endl;
	D = B;
	C = B - A;
	cout << C;
	cout << "THIRD EX" << endl;
	cout << endl;
	C -= D - A;
	cout << C;
	cout << "FOUTH EX" << endl;
	cout << endl;
	cin >> M3;
	cin >> M4;
	D = M3 * M4;
	cout << D;
	cout << "FIVE EX" << endl;
	cout << endl;
	cin >> D;
	cout << D(0, 0) << endl;
	cout << "¬ведите х:  ";
	cin >> x;
	cout << D(0, 0) + x;
}