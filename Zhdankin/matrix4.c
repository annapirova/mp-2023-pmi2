#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand((unsigned int)time(NULL));
	int m = 3, n, z, k;
	
	int Matrix_A[3][3] = { {1, 4, 5}, {2, 6, 2}, {0, 0, 0} };
	int Matrix_B[3][3] = { {1, 0, 0}, {0, 1, 0}, {0, 0, 1} };

	int check = 1;
	for (int i = 0; i < m; i++)
	{
		for (int j = i+1; j < m; j++)
		{
			int sum = 0;
			for (int k = 0; k < m; k++)
			{
				sum += Matrix_A[i][k] * Matrix_A[j][k];
			}

			if ((i == j && sum != 1) || (i != j && sum != 0))
			{
				check = 0;
				break;
			}
		}
		if (!check)
		{
			break;
		}
	}

	if (check == 1)
	{
		printf("The matrix is orthogonal.\n");
	}
	else
	{
		printf("The matrix is not orthogonal.\n");
	}
	printf("\n");

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", Matrix_A[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	int check1 = 1;
	for (int i = 0; i < m; i++)
	{
		for (int j = i + 1; j < m; j++)
		{
			int sum1 = 0;
			for (int k = 0; k < m; k++)
			{
				sum1 += Matrix_B[i][k] * Matrix_B[j][k];
			}

			if ((i == j && sum1 != 1) || (i != j && sum1 != 0))
			{
				check1 = 0;
				break;
			}
		}
		if (!check1)
		{
			break;
		}
	}

	if (check1 == 1)
	{
		printf("The matrix is orthogonal.\n");
	}
	else
	{
		printf("The matrix is not orthogonal.\n");
	}
	printf("\n");



	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", Matrix_B[i][j]);
		}
		printf("\n");
	}
	return 0;
}
