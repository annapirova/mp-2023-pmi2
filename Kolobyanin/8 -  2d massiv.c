#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int stroka, stolbec, tmp, st1, st2;
	srand(time(NULL));
	printf("Vvedite kolichestvo strok: ");
	scanf_s("%d", &stroka);
	printf("Vvedite kolichestvo stolbcov: ");
	scanf_s("%d", &stolbec);
	int** A = (int*)malloc(sizeof(int) * stroka);
	for (int i = 0; i < stroka;i++)
		A[i] = (int*)malloc(sizeof(int) * stolbec);
	for (int i = 0; i < stroka; i++)
	{
		for (int j = 0; j < stolbec; j++)
		{
			A[i][j] = 0 + rand() % 100;
		}
	}
	printf("\nSgenerirovannay matrica: \n");
	for (int i = 0; i < stroka; i++)
	{
		for (int j = 0; j < stolbec; j++)
		{
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
	printf("\nVvedite stroki dlya perestanovki:\n");
	scanf_s("%d", &st1);
	scanf_s("%d", &st2);
	printf("\n");
	for (int j = 0; j < stolbec; j++)
	{
		tmp = A[st1 - 1][j];
		A[st1 - 1][j] = A[st2 - 1][j];
		A[st2 - 1][j] = tmp;
	}
	printf("Itog: \n");
	for (int i = 0; i < stroka; i++)
	{
		for (int j = 0; j < stolbec; j++)
		{
			printf("%d ", A[i][j]);
		}
		printf("\n");

	}
}