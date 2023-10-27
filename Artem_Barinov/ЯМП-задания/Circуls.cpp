//#include <stdio.h>
//#include <math.h>
//
//double circle(char corVal, char n, char t) {
//	if(t==1)
//		printf("enter a coordinates of circel`s center.\n");
//	double coord = 0.0;
//	printf("%c", corVal); printf( "%d: ", n); scanf_s("%lf", &coord);
//	return coord;
//}
//double DisFrCen(double x1, double y1,
//				double x2, double y2) {
//
//	double dis = sqrt(pow(x2-x1, 2)+pow(y2-y1, 2));
//	return dis;
//}
//double rad(double x1, double y1) {
//	double r = 0.0;
//	printf("Enter a value of radius: "); scanf_s("%lf", &r);
//	return r;
//}
//void output(double dis, double r1, double r2) {
//	double max = (r1 > r2) ? r1 : r2;
//	double min = r1 + r2 - max;
//	if (dis > r1 + r2)
//		printf("The circles do not intersect!\n");
//	if (dis == r1 + r2)
//		printf("The circles touch each other!\n");
//	if (dis < r1 + r2) {
//		if (dis + min == max)
//			printf("One circle includes another! And they touch each other!\n");
//		if (dis == 0)
//			printf("Circles have one center! And one circle includes another!\n");
//		else
//			printf("One circle includes another!\n");
//	}
//}
//int main() {
//	double x1 = circle('x', 1, 1); double y1 = circle('y', 1, 0); // vvod coordinat i raschet rasstoania
//	double r1 = rad(x1, y1);										// i stitivaem radius
//	double x2 = circle('x', 1, 1); double y2 = circle('y', 1, 0);	
//	double r2 = rad(x2, y2);
//
//	double dis = DisFrCen(x1, y1, x2, y2);
//	output(dis, r1, r2); // reshaem kak raspolozeni
//	return 0;
//}