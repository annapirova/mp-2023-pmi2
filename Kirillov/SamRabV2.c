#include "stdio.h"
int main() {
	
	int A[5] = { 1,2,3,4,5 };
	int B[5] = { 3,4,6,8,9 };
	int C[5];
	int i = 0, j = 0, k = 0;
	
	while (i < 5) {
		if ((A[i] != B[j]) && (A[i] < B[j + 1])) {
			C[k]=A[i];
			k++;
			i++;
			j = 0;
			}
		else   {
			j++;
		}
		if (A[i] == B[j]) {
			i++;
			j = 0;
		}
		
	}
	for (i = 0;i < k;i++) {
		printf("%d ", C[i]);
	}
	
	
	return 0;

}