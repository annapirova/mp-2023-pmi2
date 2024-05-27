#include <iostream>
#include "Vector.h"
#include "Matrix.h"
#include <ctime>

using namespace std;

int main()
{
	
	setlocale(LC_ALL, "ru");
	
	Matrix m1(3, 3), m2(3, 3), m3(3, 3);
	
	m1.Generate(2.00, 68.00);
	cout << m1 << endl;

	m2.Generate(-19.00, 52.00);
	cout << m2 << endl;

	m3.Generate(-19.00, 52.00);
	cout << m3 << endl;

	cout << "operator m3=m1" << endl;
	m3 = m1;
	cout << m3 << endl;

	cout << "operator m1 * m2" << endl;
	cout << m1 * m2 << endl;

	cout << "operator m1 - m2" << endl;
	cout << m1 - m2 << endl;

	cout << "operator m1 + m3" << endl;
	cout << m1 + m3 << endl;

	cout << "operator m1(1,1)" << endl;
	cout << m1(1,1) << endl;

	return 0;
}