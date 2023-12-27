#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef double(*first_t)(double);
typedef double(*next_t)(double, int);

void typeX(double *x)
{
	printf("Type X:\n");
	scanf_s("%lf", x);
	printf("Enter another comand\n");
}

void typePogr(double* pogr)
{
	printf("Type pogreshnost:\n");
	scanf_s("%lf", pogr);
	printf("Enter another comand\n");
}

void typeN(int* N)
{
	printf("Type N:\n");
	scanf_s("%i", N);
	printf("Enter another comand\n");
}

double firstLn(double x)
{
	return x - 1;
}

double nextLn(double x, int n)
{
	return pow(-1, n - 1) * pow(x - 1, n) / n;
}

void Print(double sum, int n, double math)
{
	printf("Sum of Taylor = %lf\n", sum);
	printf("Real result = %lf\n", math);
	printf("Num of elements = %i\n", n);
	printf("Pogreshnost = %lf\n", fabs(sum-math));
}

void Taylor(double x, double pogr, int N, first_t first, next_t next, double math)
{
	int n = 1;
	double element = first(x);
	double sum = first(x);
	while ((fabs(sum - math) > pogr) && (n < N))
	{
		n++;
		element = next(x, n);
		sum += element;
		
	}

	Print(sum, n, math);
}

void Menu()
{
	printf("hi, user, what do u want to do?\n");
	printf("1. Type new X\n");
	printf("2. Type pogr\n");
	printf("3. Type Num\n");
	printf("4. Ln(x)\n");
	printf("5. go to check\n");
}


int main()
{
	double x = 0.0;
	double pogr = 0.001;
	int N = 12;
	int k;

	Menu();

	do
	{
		scanf_s("%i", &k);
		switch (k)
		{
		case 1:
		{
			typeX(&x);
			//printf("x = %lf\n", x);
			break;
		}

		case 2:
		{
			typePogr(&pogr);
			//printf("pogr = %lf\n", pogr);
			break;
		}

		case 3:
		{
			typeN(&N);
			//printf("N = %i\n", N);
			break;
		}

		case 4:
		{
			Taylor(x, pogr, N, firstLn, nextLn, log(x));
			break;
		}

		case 5:
		{
			
			break;
		}

		default:
			printf("type another number\n");
			break;
		}
	} while (k != 5);







	return 0;
}