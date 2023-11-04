#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "malloc.h"

int main()
{
	int pos_a, pos_b, length, sum, average, elements;
	int* A;
	int B[10] = {0};
	int C[10] = {0};
	pos_a = 0; pos_b = 0; sum = 0;
	printf("Enter length of array - ");
	scanf_s("%d", &length);
	A = (int*)malloc(length * sizeof(int));
	elements = 0;
	printf("Enter elements of array != 0\n");
	for (int j = 0; j < length; j++) 
	{
		printf("A[%d] = ", j);
		scanf_s("%d", &A[j]);
	}
	while (pos_a < length)
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
	for (int j = 0; j < length; j++)
	{
		if (B[j] != 0)
		{
			elements = elements + 1;
		}
	}
	for (int k = 0; k < length; k++)
	{
		sum += C[k];
	}
	average = sum / elements;
	for (int i = 0; i < length; i++)
	{
		if (C[i] > average) 
		{
			printf("%d\n", B[i]);
		}
	}
	return 0;
}