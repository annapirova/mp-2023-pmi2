#include "stdio.h"
#define MAX_NUMS 5

int main()
{
	int A[MAX_NUMS], B[MAX_NUMS], C[MAX_NUMS];
	int i, n;
	n = MAX_NUMS;
	printf("enter A\n");
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &A[i]);
	}

	printf("\nenter B");
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &B[i]);
	}

	int posA = 0, posB = 0, posC = 0;
	while ((posA < n) && (posB < n))
	{
		if (A[posA] < B[posB]) {
			C[posC] = A[posA];
			posA++;
			posC++;
		}
		else {
			
			if (A[posA] == B[posB]) {
				C[posC] = -1; posC++; posA++;
				posB--;
			}
			posB++;
		}
		
	}
	while (posA < n) {
		C[posC] = A[posA];
		posA++;
		posC++;
	}
	for (i = 0; i < n; i++) {
		printf("%d ", C[i]);
	}
	return 0;
}