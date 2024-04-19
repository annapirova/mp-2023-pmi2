#include "vector.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
	Vector vec1(3);
	vec1.Generate(5, 25);
	cout << vec1 << endl;
	Vector vec2(3);
	vec2.Generate(3, 7);
	cout << vec2 << endl;
	Vector sum = vec1 + vec2;
	Vector razn = vec1 - vec2;
	Vector prisv = vec1 += vec2;
	cout << "sum" << endl << sum << endl;
	cout << "razn" << endl << razn << endl;
	cout << "prisv" << endl << prisv << endl;
	return 0;
}