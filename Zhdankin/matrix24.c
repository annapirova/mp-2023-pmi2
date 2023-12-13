#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int m, n, z, k = 0;
	int indexes[100];

	printf("Enter size of matrix(m*n):\n");
	scanf_s("%i", &m);
	scanf_s("%i", &n);

	int** Matrix_A = (int**)malloc(m * sizeof(int*));
	for (int i = 0; i < m; i++)
	{
		Matrix_A[i] = (int*)malloc(n * sizeof(int));
	}

	for (int i = 0; i < m; i++)
	{
		printf("type elements of %i row\n", i+1);
		for (int j = 0; j < n; j++)
		{
			scanf_s("%d", &z);
			Matrix_A[i][j] = z;
		}
	}
	
	int mid = n / 2;

	for (int i = 0; i < m; i++)
	{
		int isSymmetric = 1;
		for (int j = 0; j < mid; j++)
		{
			if (Matrix_A[i][j] != Matrix_A[i][n - 1 - j])
			{
				isSymmetric = 0;
				break;
			}
		}

		if (isSymmetric)
		{
			indexes[k] = i;
			k++;
		}
	}

	printf("\nMatrix:\n");

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", Matrix_A[i][j]);
		}
		printf("\n");
	}

	printf("\narray of rows:\n");

	for (int i = 0; i < k; i++)
	{
		printf("%i ", indexes[i]);
	}


	for (int i = 0; i < m; i++) {
		free(Matrix_A[i]);
	}
	free(Matrix_A);
	return 0;
}
