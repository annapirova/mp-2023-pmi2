#include "stdio.h"
#include "stdbool.h"
int simp(num) {
	int i = 0;
	int k = 0;
	for (i = 1;i <= num;i++) {
		k += (num % i == 0);
		if (k > 2) {
			return 0;
			break;
		}
		
	}
	if (k == 2) {
		return 1;
	}
}
void main() {
	int a[20], g[20];
	int n, i, j = 0;
	printf("Enter array length:", "\n");
	scanf_s("%d", &n);
	printf("Enter array:", "\n");
	for (i = 0;i < n;i++) {
		scanf_s("%d", &a[i]);
	}

	for (i = 0;i < n;i++) {
		if (simp(a[i])==1) {
			g[j] = i;
			j++;
		}
	}
	for (i = 0;i < j;i++) {
		printf("%d  ", g[i]);
	}
}