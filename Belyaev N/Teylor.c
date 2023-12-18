#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "malloc.h"

int choise_func()
{
	int x;
	printf("Enter x - ");
	scanf_s("%d", &x);
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

void cos_func(int x, double accuracy, int N)
{
	double sum = 1;
	double current = 1;
	int n = 1;
	int k = -1;
	do
	{
		current = (pow(k, n) * pow(x, 2 * n)) / fact(2 * n);
		sum += current;
		n++;
	} while ((fabs(current) > accuracy) && (n < N));
	printf("Sum: %.10f\n", sum);
	printf("Reference value: %.10f\n", cos(x));
	printf("Difference: %.10f\n", fabs(cos(x)) - fabs(sum));
	printf("N = %d\n", n);
}

void ch_func(int x, double accuracy, int N)
{
	double sum = 1;
	double current = 1;
	int n = 1;
	do
	{
		current = pow(x, 2 * n) / fact(2 * n);
		sum += current;
		n++;
	} while ((fabs(current) > accuracy) && (n < N));
	printf("Sum: %.10f\n", sum);
	printf("Reference value: %.10f\n", cosh(x));
	printf("Difference: %.10f\n", fabs(cosh(x)) - fabs(sum));
	printf("N = %d\n", n);
}

int fact(n)
{
	int fac = 1;
	for (int i = 1; i <= n; i++)
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
	int x = 1;
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
		case 4: cos_func(x, accuracy, N); break;
		case 5: ch_func(x, accuracy, N); break;
		default: func_error(); break;
		}
	} while (operation != 5);
	return 0;
}