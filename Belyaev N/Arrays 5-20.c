#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "malloc.h"
#define SIZE 8

int main()
{	
	int m = SIZE;
	int n = 2;
	int array[SIZE][2];
	int k = 0;
	int sum = 0;
	int salary[SIZE] = { 0 };
	srand(time(NULL));
	for (int i = 0; i < m; i++)
	{
		array[i][0] = 30 + rand() % (50 - 30); // Hours
		array[i][1] = 300 + rand() % (1200 - 300); // Salary per hour
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", array[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < m; i++)
	{
		salary[i] = array[i][0] * array[i][1];
		sum += array[i][0] * array[i][1];
	}
	for (int i = 0; i < m; i++)
	{
		printf("Salary[%d] = %d\n", i, salary[i]);
	}
	printf("Total: %d", sum);
	return 0;
}
