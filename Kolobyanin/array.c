#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	int a[10] = { 1,2,3,4,5 };
	int i;
	for (i = 0; i < 9; i++)
	{
		if (a[i] + 1 == a[i + 1] || a[i] - 1 == a[i+1])
		{
			printf("Перестановка");
			return 0;
		}
		else
		{
			printf("Не перестановка");
			return 0;
		}
	}
}