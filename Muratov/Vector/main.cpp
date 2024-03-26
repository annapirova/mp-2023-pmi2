using namespace std;
#include <iostream>
#include "vector.h"
#include <locale.h>
#include <ctime>
#include <random>

int main() {
	srand(time(NULL));
	setlocale(LC_CTYPE, "Rus");
	double x;
	Vector A(5), B(5), C, D, E(4), F(5), G, H(2), I;
	cout << "GENERATE" << endl;
	cout << endl;
	A.Generate();
	B.Generate();
	cout << A << B << endl;
	cout << "OPERATOR + AND +=" << endl;
	cout << endl;
	C = A + B;
	cout << C;
	A += B;
	cout << A << endl;
	cout << "OPERATOR - AND -=" << endl;
	cout << endl;
	D = A - B;
	cout << D << endl;
	A -= B;
	cout << A << endl;
	cout << "OPERATOR *" << endl;
	cout << endl;
	E.Generate();
	F.Generate();
	cout << E << F;
	G = E * F;
	cout << G << endl;
	cout << "OPERATOR []" << endl;
	cout << endl;
	cout << G[0] << endl;
	cout << "Input x:  ";
	cin >> x;
	cout << G[0] + x;
	cout << "OPERATOR ++" << endl;
	cout << endl;
	H.Generate();
	cout << H;
	H = H++;
	cout << H;
	I = ++H;
	cout << I;
}
