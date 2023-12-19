﻿#define _USE_MATH_DEFINES
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

double nextCos(double x, int N)
{
	double fac = 1;
	for (double i = 1; i <= 2*N; i++)
	{
		fac *= i;
	}
	double res = 1.0 / fac;
	for (int i = 0; i < 2 * N; i++)
	{
		res *= x;
	}
	if (N % 2 == 0)
	{
		return res;
	}
	else
	{
		return -res;
	}
}

double nextCh(double x, int N)
{
	double fac = 1;
	for (double i = 1; i <= 2 * N; i++)
	{
		fac *= i;
	}
	double res = 1.0 / fac;
	for (int i = 0; i < 2 * N; i++)
	{
		res *= x;
	}
	return res;
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
		elem = next(x, n);
		sum += elem;
		current = fabs(sum - corr);
		n++;
	}
	printf("Sum: %.10f\n", sum);
	printf("Reference value: %.10f\n", cos(x));
	printf("Difference: %.10f\n", fabs(cos(x)) - fabs(sum));
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
		elem = next(x, n);
		sum += elem;
		current = fabs(sum - corr);
		n++;
	}
	printf("Sum: %.10f\n", sum);
	printf("Reference value: %.10f\n", cosh(x));
	printf("Difference: %.10f\n", fabs(cosh(x)) - fabs(sum));
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
	printf("Operation list:\n 1. Choise x (default 1)\n 2. Choise calculation accuracy (default 0.00001)\n 3. Select the number of series elements to perform the calculation (default 20)\n 4. cos(x)\n 5. ch(x)\n 6. Exit\n");
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
		case 5: getCh(x, accuracy, first, nextCh, N, cosh(x)); break;
		default: func_error(); break;
		}
	} while (operation != 6);
	return 0;
}