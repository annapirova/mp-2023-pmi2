#include "Vector.h"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	Vector vec1(5);
	vec1.Generate(2, 20);
	//cin >> vec1;
	cout << vec1 << endl;

	Vector vec2(5);
	vec2.Generate(1, 10);
	cout << vec2 << endl;

	Vector sum = vec1 + vec2;
	Vector razn = vec1 - vec2;

	Vector umnoj = vec1 * vec2;

	cout << "///////////////////////" << endl;

	cout << "umnoj" << endl << umnoj << endl;
	
	cout << "sum" << endl << sum << endl;
	cout << "razn" << endl << razn << endl;

	return 0;
}