#define _USE_MATH_DEFINES
#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "malloc.h"


double choise_func()
{
	double x;
	printf("Enter x - ");
	scanf_s("%lf", &x);
	return x;
}

double accuracy_func()
{
	double accuracy;
	printf("Enter calculation accuracy - ");
	scanf_s("%lf", &accuracy);
	return accuracy;
}

int elements_func()
{
	int N;
	printf("Enter N - ");
	scanf_s("%d", &N);
	return N;
}
typedef double (*nextT)(double, int);

typedef double (*firstT)(double);

double first(double x)
{
	return 1;
}

double firstSin(double x)
{
	return x;
}

double nextCos(double x, int N)
{
	return (-x * x / (2*N-1) / (2 * N));
}

double nextSin(double x, int N)
{
	return (-x*x / (2*N) / (2 * N + 1));
}

double nextExp(double x, int N)
{

	return (x / N);
}

double nextCh(double x, int N)
{
	return ((x * x) / (2 * N - 1) / (2 * N));
}

double getCos(double x, double accuracy, firstT first, nextT next,  int N, double corr)
{
	int n = 0;
	double elem = first(x);
	n++;
	double sum = elem;
	double current = fabs(sum - corr);
	while ((current > accuracy) && (n <= N))
	{
		elem = elem * next(x, n);
		sum += elem;
		current = fabs(sum - corr);
		n++;
	}
	printf("Sum: %.10f\n", sum);
	printf("Reference value: %.10f\n", corr);
	printf("Difference: %.10f\n", fabs(corr) - fabs(sum));
	printf("N = %d\n", n);
}

double getSin(double x, double accuracy, firstT first, nextT next, int N, double corr)
{
	int n = 0;
	double elem = first(x);
	n++;
	double sum = elem;
	double current = fabs(sum - corr);
	while ((current > accuracy) && (n <= N))
	{
		elem = elem * next(x, n);
		sum += elem;
		current = fabs(sum - corr);
		n++;
	}
	printf("Sum: %.10f\n", sum);
	printf("Reference value: %.10f\n", corr);
	printf("Difference: %.10f\n", fabs(corr) - fabs(sum));
	printf("N = %d\n", n);
}

double getExp(double x, double accuracy, firstT first, nextT next, int N, double corr)
{
	int n = 0;
	double elem = first(x);
	n++;
	double sum = elem;
	double current = fabs(sum - corr);
	while ((current > accuracy) && (n <= N))
	{
		elem = elem * next(x, n);
		sum += elem;
		current = fabs(sum - corr);
		n++;
	}
	printf("Sum: %.10f\n", sum);
	printf("Reference value: %.10f\n", corr);
	printf("Difference: %.10f\n", fabs(corr) - fabs(sum));
	printf("N = %d\n", n);
}

double getCh(double x, double accuracy, firstT first, nextT next, int N, double corr)
{
	int n = 0;
	double elem = first(x);
	n++;
	double sum = elem;
	double current = fabs(sum - corr);
	while ((current > accuracy) && (n <= N))
	{
		elem = elem * next(x, n);
		sum += elem;
		current = fabs(sum - corr);
		n++;
	}
	printf("Sum: %.10f\n", sum);
	printf("Reference value: %.10f\n", corr);
	printf("Difference: %.10f\n", fabs(corr) - fabs(sum));
	printf("N = %d\n", n);
}

double fact(n)
{
	double fac = 1;
	for (double i = 1; i <= n; i++)
	{
		fac *= i;
	}
	return fac;
}
void func_error()
{
	printf("Operation not found");
}

int main()
{	
	double x = 1;
	double accuracy = 0.00001;
	int N = 20;
	int operation = 0;
	printf("Operation list:\n 1. Choise x (default 1)\n 2. Choise calculation accuracy (default 0.00001)\n 3. Select the number of series elements to perform the calculation (default 20)\n 4. cos(x)\n 5. sin(x)\n 6. e(x)\n 7. ch(x)\n 8. Exit\n");
	do
	{
		printf("Enter number of operation - ");
		scanf_s("%d", &operation);
		switch (operation)
		{
		case 1: x = choise_func(); break;
		case 2: accuracy = accuracy_func(); break;
		case 3: N = elements_func(); break;
		case 4: getCos(x, accuracy, first, nextCos, N, cos(x)); break;
		case 5: getSin(x, accuracy, firstSin, nextSin, N, sin(x)); break;
		case 6: getExp(x, accuracy, first, nextExp, N, exp(x)); break;
		case 7: getCh(x, accuracy, first, nextCh, N, cosh(x)); break;
		default: func_error(); break;
		}
	} while (operation != 8);
	return 0;
}