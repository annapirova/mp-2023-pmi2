#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

int main()
{
	int i, j;
	int tmp;
	int a[10];
	printf("Vvedite massiv iz 10 elementov\n");
	for (int i = 0; i < 10; i++)
	{
		scanf_s("%d", &a[i]);
	}
	for (j = 0;j < 10;j++)
	{
		for (i = 0;i < 9;i++)
		{
			if ((a[i] >= 0) && (a[i + 1] < 0))
			{
				tmp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = tmp;
			}
		}
	}
	printf("Itog: \n");
	for (i = 0;i < 10;i++)
	{
		printf(" %d", a[i]);
	}
	printf(" \n");
	return 0;
}