#include "matrix.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "Enter min and max of numbers" << endl;
	Matrix K(2, 2), B(2, 2), D(1, 2);
	int min, max;
	cin >> min >> max;
	B.Generate(min, max);
	//D.Print();
	K.Generate(min, max);
	Matrix C(B); 
	
	B.Print();
	cout << endl;
	K.Print();
	cout << endl;
	K = K * B;
	B += B;
	//B.Null();
	B.Print();
	K.Print();
	
	Vector T(3),Y, L, x;
	T.Genetate(min, max);
	//cin >> T;
	Y = T;
	Y.Print();
	L = (Y + T);
	L.Print();
	L[0] = Y[1] * 5;
	++L;
	cout << L;

	return 0;
}
