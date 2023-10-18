#include <stdio.h>
#include <math.h>

double circle(char corVal, char n, char t) {
	if(t==1)
		printf("enter a coordinates of circel`s center.\n");
	double coord = 0.0;
	printf("%c", corVal); printf( "%d: ", n); scanf_s("%lf", &coord);
	return coord;
}
double DisFrCen(double x1, double y1,
				double x2, double y2) {

	double dis = sqrt(pow(x2-x1, 2)+pow(y2-y1, 2));
	return dis;
}
int main() {
	double x1 = circle('x', 1, 1); double y1 = circle('y', 1, 0); // vvod coordinat i raschet rasstoania
	double x2 = circle('x', 1, 1); double y2 = circle('y', 1, 0);
	double dis = DisFrCen(x1, y1, x2, y2);
	printf("Distens: %lf\n", dis);
	return 0;
}