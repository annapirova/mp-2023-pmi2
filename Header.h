#pragma once

class Complex {
	int a;
	int b;

public:
	Complex(int first = 0, int second = 0) {
		a = first;
		b = second;
	}
	int GetA() { return a; }
	int GetB() { return b; }
	int Sum_DiffA(int a1, int a2, char f) { return (f == '+') ? a1 + a2 : a1 - a2; }
	int Sum_DiffB(int b1, int b2, char f) { return (f == '+') ? b1 + b2 : b1 - b2; }
	int MltplyA(int a1, int a2, int b1, int b2) { return a1 * a2 + (b1 * b2) * (-1); }
	int MltplyB(int a1, int a2, int b1, int b2) { return a1 * b2 + b1 * a2; }
};