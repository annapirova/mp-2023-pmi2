#include <math.h>
#include <stdio.h>
typedef double(*FirstT)(double);
typedef double(*NextT)(double,int);
double SinFirst(double x) { return x; }
double SinNext(double x, int n) { return -x * x /( 2 * n * (2 * n + 1)); }
double LnFirst(double x) { return x; }//ln (1+x)
double LnNext(double x, int n) { return -x/n; } //ln(1+x)

double Teylor(double x, FirstT first, NextT nextt, double acc, double corr, int N_max) {
	int i=1,prev,sum;
	int next;
	sum = first(x);
	prev = sum;
	while ((fabs(sum - corr)>acc) && (i < N_max)) {	
		next = prev * nextt(x,i);
		sum += next;
		prev = next;
		i++;
	}
	return sum;
}
void main() {
	double x, acc;
	int N_max;
	printf("Enter x:\n");
	scanf_s("%lf", &x);
	if (x > (2 * 3,14)) {
		while (x > (2 * 3,14)) {
			x = x - (2 * 3,14);
		}
	}
	if (x < 0) {
		while (x < 0) {
			x = x + (2 * 3,14);
		}
	}
	
	printf("Enter accuracy: \n");
	scanf_s("%lf", &acc);
	printf("\nEnter max elements");
	scanf_s("%d", &N_max);
	double y1 = Teylor(x, SinFirst, SinNext, acc, sin(x), N_max);
	double y2 = Teylor(x, LnFirst, LnNext, acc, log(1+x), N_max);
	printf("sin(x) = %lf \n", y1);
	printf("correct sin(x) = %lf \n", sin(x));
	printf("Ln(1+x) = %lf \n", y2);
	printf("correct Ln(1+x) = %lf \n", log(1 + x));
}