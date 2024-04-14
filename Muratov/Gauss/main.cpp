using namespace std;
#include <iostream>
#include "gauss.h"
#include <locale.h>
#include <random>
#include <ctime>
#include <math.h>


int main() {
	setlocale(LC_CTYPE, "Rus");
	double err;
	int n;
	cout << "¬ведите размерность: ";
	cin >> n;
	Matrix A(n, n);
	Vector X(n);
	Vector B(n);
	Vector Ans(n);
	A.RandomMatrix(-3, 3);
	X.Generate(-10, 10);
	B = X * A;
	Gauss G(&A, &Ans, &B);
	G.Solve();
	err = G.Check();
	cout << err;
}