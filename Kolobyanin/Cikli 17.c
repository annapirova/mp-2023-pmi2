#include <stdio.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "Russian");
	int n,i, a;
	int k = 0;
	printf("Введите число n от 0 до 27: ");
	scanf_s("%d", &n);
	if ((n < 0) || (n > 27))
	{
		printf("Неподходящее n");
		return 0;
	}
	for (i = 1; i < 1000; i++)
	{
		int sum = 0;
		a = i;
		while (a > 0)
		{
			sum = sum + a % 10;
			a = a / 10;
		}
		if (sum == n)
		{
			k++;
		}
	}
	printf("Количество чисел: %d", k);
}
