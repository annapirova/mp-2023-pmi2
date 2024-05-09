#include "Fraction.h"

int main() {
	Fraction A=Fraction(1,1);
	A.SetFraction(2, 3);
	Fraction B;
	B.SetFraction(3,4);
	Fraction C, D;
	C.FractionSum(A, B);
	D.FractionDif(A, B);
	cout << "Summa drobei:" << endl; 
	C.Print();
	cout << "Raznost drobei:"<<endl;
	D.Print();

	
	return 0;
}
