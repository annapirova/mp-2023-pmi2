#include "stdio.h"
#include "math.h"

void main() {
	int N, K, V = 10000, i, j, o1, o2;
	int a[20];
	printf("Enter array length:", "\n");
	scanf_s("%d", &N);
	printf("Enter number:", "\n");
	scanf_s("%d", &K);
	printf("Enter array","\n");
	for (i = 0;i < N;i++) {
		scanf_s("%d", &a[i]);
	}

	for (i = 0;i < N - 1;i++) {
		for (j = i;j < N;j++) {
			if (abs(a[i] + a[j] - K) < V) {
				V = abs(a[i] + a[j] - K);
				o1 = a[i];
				o2 = a[j];
			}
		}
	}
	printf("%d %d", o1, o2);
}