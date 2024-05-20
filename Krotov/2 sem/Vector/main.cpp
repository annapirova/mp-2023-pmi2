#include <iostream>
#include "Vector.h"

using namespace std;

int main()
{
	
	setlocale(LC_ALL, "ru");
	
	Vector v1(5),v2(5),v3(5);
	v1.Generate(2.00, 68.00);
	cout << v1 << endl;

	v2.Generate(-19.00, 52.00);
	cout << v2 << endl;

	v3.Generate(-19.00, 52.00);
	cout << v3 << endl;

	cout << "operator v3=v1" << endl;
	v3 = v1;
	cout << v3  << endl;
	
	cout << "operator ++" << endl;
	v3++;
	cout << v3 << endl;
	
	cout << "operator v1 + v3" << endl;
	cout << v1 + v3 << endl;

	cout << "operator v1 - v2" << endl;
	cout << v1 - v2 << endl;

	cout << "operator v1 * v2" << endl;
	cout << v1 * v2 << endl;
	
	cout << "operator v1[3]" << endl;
	cout << v1[3] << endl;

	return 0;
}
