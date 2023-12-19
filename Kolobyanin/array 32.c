#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

int main()
{
	int n;
	int i, j;
	int tmp;
	printf("Vvedite dlinu massiva\n");
	scanf_s("%d", &n);
	printf(" \n");
	int** a = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		printf("Vvedite element massiva\n");
		scanf_s("%d", &a[i]);
	}
	for (j = 0;j < n;j++)
	{
		for (i = 0;i < n - 1;i++)
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
	for (i = 0;i < n;i++)
	{
		printf(" %d", a[i]);
	}
	printf(" \n");
	free(a);
	return 0;
}