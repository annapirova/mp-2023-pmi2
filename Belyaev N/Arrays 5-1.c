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
	int sum[2 * SIZE] = { 0 };
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
		sum[k++] = sumUp[i];
		sum[k++] = sumDown[i];
	}
	for (int i = 0; i < 2 * m - 2; i++)
	{
		printf("Sum[%d] = %d\n", i, sum[i]);
	}
	return 0;
}
