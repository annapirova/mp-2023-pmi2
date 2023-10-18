#include <stdio.h>


double circle(char corVal, char n, char t) {
	if(t==1)
		printf("enter a coordinates of circel`s center.\n");
	double coord = 0.0;
	printf("%c", corVal); printf( "%d: ", n); scanf_s("%lf", &coord);
	return coord;
}
int main() {
	DisFrCent(circle('x', 1, 1), circle('y', 1, 0)); // vvod coordinat i raschet rasstoania
	DisFrCent(circle('x', 2, 1), circle('y', 2, 0));
	return 0;
}