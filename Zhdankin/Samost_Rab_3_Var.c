#include <stdio.h>
#include <locale.h>


int  main()
{
	setlocale(LC_ALL, "Russian");
	int n, i, sum = 0, average = 0, count = 0;
	int A[100], pos_a = 0;
	int B[100], pos_b = 0;
	int C[100];
	int D[100];

	printf("¬ведите длину массива: ");
	scanf_s("%i", &n);

	for (i = 0; i < n; i++)
	{
		scanf_s("%i", &A[i]);
	}
	
	while (pos_a < n)
	{
		int k = 0;
		while ((k < pos_b) && (B[k] != A[pos_a])) k++;
		{
			if (k == pos_b)
			{
				B[pos_b] = A[pos_a];
				C[pos_b] = 1;
				pos_a++; pos_b++;
			}
			
			else
			{
				C[k]++; pos_a++;
			}
		}
	}
	
	
	for (i = 0; i < pos_b; i++)
	{
		sum += C[i];
	}
	
	average = sum / pos_b;
	
	for (i = 0; i < pos_b; i++)
	{
		if (C[i] > average)
		{
			D[i] = B[i];
			count++;
		}
	}
	
	for (i = 0; i < count; i++)
	{
		printf("%i ", D[i]);
	}


	return(0);
}