#include "stdio.h"

void shift(int A[], int start,int end) {
	int i = 0;
	for (i = end;i > start;i--) {
		A[i] = A[i - 1];
	}
}

int main() {
	int N,A[50],temp,k = 0;
	printf("Enter array length:");
	scanf_s("%d", &N);
	int i;
	for (i = 0;i < N;i++) {
		scanf_s("%d", &A[i]);
	}
	for (i = 0;i < N;i++) {
		if (A[i] < 0) {
			temp = A[i];
			shift(A, k,i);
			A[k] = temp;
			k++;
		}
	}
	for (i = 0;i < N;i++) {
		printf("%d  ", A[i]);
	}
}
