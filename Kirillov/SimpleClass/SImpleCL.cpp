#include "Fraction.h"

Fraction::Fraction(int c , int zh ) {
	numerator = 1;
	denominator = 1;
}
void Fraction::SetFraction(int ch, int zh) {
	if (zh != 0) {
		numerator = ch;
		denominator = zh;
	}
	else { cout << "error"; }
}
int Fraction::GeneralDenominator(Fraction A,Fraction D) {
	int i = min(A.denominator, D.denominator);
	while (((i%A.denominator == 0) && (i%D.denominator == 0))!=1){
		i += 1;
	}
	
	return i;
}
void Fraction::FractionSum(Fraction A, Fraction D) {
	numerator = (A.numerator * (GeneralDenominator(A,D) / A.denominator)) + (D.numerator * (GeneralDenominator(A, D) / D.denominator));
	denominator = GeneralDenominator(A, D);
}
void Fraction::FractionDif(Fraction A, Fraction D) {
	numerator = (A.numerator * (GeneralDenominator(A, D) / A.denominator)) - (D.numerator * (GeneralDenominator(A, D) / D.denominator));
	denominator = GeneralDenominator(A, D);
}
void Fraction::Print() {
	cout << numerator << "/" << denominator << endl;
}