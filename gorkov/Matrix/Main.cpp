#include "matrix.h"
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	Matrix K(3, 3), B(3, 5), D(1, 2);
	int min, max;
	cout << "Enter min and max of numbers" << endl;
	cin >> min >> max;
	B.Generate(min, max);
	//D.Print();
	K.Generate(min, max);
	Matrix C(B);
	//B.Print();
	//K.Print();
	K = K * B;
	B += B;
	B.Null();
	//B.Print();
	//K.Print();
	
	Vector T(3),Y, L;
	T.Genetate(min, max);
	Y = T;
	Y.Print();
	L = (Y + T);
	L.Print();
	
	return 0;
}
