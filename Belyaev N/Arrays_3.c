#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "malloc.h"

int main()
{
	int pos_a, pos_b, length, length_b, length_c, sum, average;
	int* A;
	int* B;
	int* C;
	length = sizeof(A) / sizeof(A[0]);
	pos_a = 0; pos_b = 0; sum = 0;
	printf("Enter length of array - ");
	scanf_s("%d", &length);
	A = (int*)malloc(length * sizeof(int));
	B = (int*)malloc(0 * sizeof(int));
	C = (int*)malloc(0 * sizeof(int));
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
	length_b = sizeof(B) / sizeof(B[0]);
	length_c = sizeof(C) / sizeof(C[0]);
	for (int k = 0; k < length_c; k++)
	{
		sum += C[k];
	}
	average = sum / length_c;
	for (int i = 0; i < length_b + 1; i++)
	{
		if (C[i] > average) 
		{
			printf("%d\n", B[i]);
		}
	}
	return 0;
}