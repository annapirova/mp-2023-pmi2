#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "malloc.h"
#define SIZE 7

int main()
{	
	int m = SIZE;
	int array[SIZE][SIZE];
	int k = 0;
	int sumUp[SIZE] = { 0 };
	int sumDown[SIZE] = { 0 };
	srand(time(NULL));
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			array[i][j] = 10 + rand() % (100 - 10);
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d  ", array[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < m - 1; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			sumUp[i] = sumUp[i] + array[j][m - 1 - (i-j)];
			sumDown[i] = sumDown[i] + array[m - 1 - (i - j)][j];
		}
	}
	for (int i = 0; i < m-1; i++)
	{
		printf("sumUp[%d] = %d\n", i, sumUp[i]);
	}
	for (int i = 0; i < m - 1; i++)
	{
		printf("sumDown[%d] = %d\n", i, sumDown[i]);
	}
	return 0;
}
