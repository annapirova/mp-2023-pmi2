#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand((unsigned int)time(NULL));
	int m, n, z, k;
	
	printf("Enter size of matrix(m*m):\n");
	scanf_s("%i", &m);
	
	int** Matrix_A = (int**)malloc(m * sizeof(int*));
	for (int i = 0; i < m; i++)
	{
		Matrix_A[i] = (int*)malloc(m * sizeof(int));
	}

	for (int i = 0; i < m; i++)
	{
		printf("type elements of %i row\n", i + 1);
		for (int j = 0; j < m; j++)
		{
			scanf_s("%d", &z);
			Matrix_A[i][j] = z;
		}
	}
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

	for (int i = 0; i < m; i++) {
		free(Matrix_A[i]);
	}
	free(Matrix_A);
	return 0;
}
