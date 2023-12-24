#include<stdio.h>
#include<math.h>

typedef double(*FirstT)(double);
typedef double(*NextT)(double, int);
double SinFirst(double x) { return x; }
double SinNext(double x, int n) { return  -x * x / (2 * n) / (2 * n + 1); }

double Teylor(double x, FirstT first, NextT f, double acc, double tochnoe, int N_MAX)
{
	double sum, prev, next;
	sum = first(x);
	prev = sum;
	int n = 1;
	while ((fabs(sum - tochnoe) > acc) && (n < N_MAX))
	{
		next = prev * f(x, n);
		sum += next;
		prev = next;
		n++;
	}
	printf("sum = %lf, n = %i, tochnoe = %lf\n ", sum, n, tochnoe);
	return sum;
}
double expfirst(double x)
{
	return 1;
}
double expf(double x,int n)
{
	return x / n;
}

void main()
{ 
	double x, acc;
	int N_MAX;
	scanf_s("%lf", &x);
	scanf_s("%lf", &acc);
	scanf_s("%i", &N_MAX);
	double tochnoe = exp(x);
	double y = Teylor(x, SinFirst, SinNext, acc, sin(x), N_MAX);
	double yy = Teylor(x, expfirst, expf, acc, tochnoe, N_MAX);
}
