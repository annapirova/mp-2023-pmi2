#include <iostream>
#include "ComplexClass.h"

using namespace std;

int main()
{
	Complex a(3, 5);
	Complex b(8, 4);

	Complex c = a + b;
	Complex d = a - c;
	Complex e = b * d;

	cout << "a = " << a << " ;b = " << b << " ;c = " << c << " ;d = " << d << " ;e = " << e << endl;
	
	return 0;
}