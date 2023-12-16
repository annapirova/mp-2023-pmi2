#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

//9. переставляет местами столбцы с заданными номерами j и k;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	int nr, nc, tmp, g ,k;
	srand(time(NULL));
	printf("Введите количество строк матрицы\n");
	scanf_s("%d", &nr);
	printf("Введите количество столбцов матрицы\n");
	scanf_s("%d", &nc);
	int** M = (int*)malloc(sizeof(int) *  nr);
	for(int i = 0; i< nr;i++)
		M[i] = (int*)malloc(sizeof(int) * nc);
	for (int i = 0; i < nr; i++)
	{
		for (int j = 0; j < nc; j++)
		{
			M[i][j] = 0 + rand() % 100;
		}
	}
	printf("Сгенерированная матрица: \n");
	for (int i = 0; i < nr; i++)
	{
		for (int j = 0; j < nc; j++)
		{
			printf("%d ", M[i][j]);
		}
			printf("\n");
	}
	printf("Введите номера столбцов для перестановки:\n");
	scanf_s("%d",&g);
	scanf_s("%d",&k);
	printf("\n");
	for (int i = 0; i < nr; i++)
	{
		tmp = M[i][g-1];
		M[i][g-1] = M[i][k-1];
		M[i][k-1] = tmp;
	}
	printf("Полученная матрица: \n");
	for (int i = 0; i < nr; i++)
	{
		for (int j = 0; j < nc; j++)
		{
			printf("%d ", M[i][j]);
		}
		printf("\n");

	}
	return 0;
}