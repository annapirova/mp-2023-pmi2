//задача 24 массивы
#include"stdio.h"
#include"math.h"

int main()
{
	int n = 5;
	int a[5];
	int i, j;
	int k = 0;
	printf("Vvedite massiv:");
	for (i = 0; i < n;i++)
	{
		scanf_s("%i", &a[i]);
	}
	for (i = 0; i < n; i++)
	{
		printf("%i ", a[i]);
	}

	printf("\n");

	for (i = 0;i < n;i++)
	{
		for (j = i + 1;j < n;j++)
		{
			if (a[i] == a[j])
			{
				k++;
			}
		}
	}
	if (k > 0)
	{
		printf("da");
	}
	else
	{
		printf("net");
	}
}