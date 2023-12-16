#include<stdio.h>
#include<time.h>
#include<locale.h>

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	int n, i;
	int a[4];
	int number, number1, number2, number3;
	int a2 = 0, b2 = 0, a3 = 0, b3 = 0, c3 = 0, a4 = 0, b4 = 0, c4 = 0, d4 = 0;
	printf("Введите n: ");
	scanf_s("%i", &n);
	if (n == 2)
	{
		while (a2 == b2)
		{
			number = 10 + rand() % (100 - 10 + 1);
			number1 = number;
			a2 = number1 % 10;
			number1 = number1 / 10;
			b2 = number1 % 10;
		}
		printf("%d", number);
	}
	if (n == 3)
	{
		while (a3 == b3 && a3 == c3 && c3 == b3)
		{
			number = 100 + rand() % (1000 - 100 + 1);
			number2 = number;
			a3 = number2 % 10;
			number2 = number2 / 10;
			b3 = number2 % 10;
			number2 = number2 / 10;
			c3 = number2 % 10;
		}
		printf("%d", number);
	}
	if (n == 4)
	{
		while (a4 == b4 && a4 == c4 && a4 == d4 && b4 == c4 && b4 == d4 && c4 == d4)
		{
			number = 1000 + rand() % (10000 - 1000 + 1);
			number3 = number;
			a4 = number3 % 10;
			number3 = number3 / 10;
			b4 = number3 % 10;
			number3 = number3 / 10;
			c4 = number3 % 10;
			number3 = number3 / 10;
			d4 = number % 10;
		}
		printf("%d", number);
	}
	for (i = n - 1; i >= 0; i--)
	{
		a[i] = number % 10;
		number = number / 10;
	}
	int chislo, bulls = 0, cows = 0;
	int j;
	int b[4];
	while (bulls != n)
	{
		printf("\nВведите вашу догадку: ");
		scanf_s("%i", &chislo);

		for (i = n - 1;i >= 0;i--)
		{
			b[i] = chislo % 10;
			chislo = chislo / 10;
		}
		bulls = 0;
		cows = 0;
		for (i = 0;i < n;i++)
		{
			if (a[i] == b[i])
			{
				bulls++;
			}
			else
			{
				for (j = 0;j < n;j++)
				{
					if (a[i] == b[j])
					{
						cows++;
					}
				}
			}
		}
		if (bulls != n)
		{
			printf("Быки: %i Коровы: %i", bulls, cows);
		}
		else
		{
			printf("Вы угадали число");
		}
	}
}
