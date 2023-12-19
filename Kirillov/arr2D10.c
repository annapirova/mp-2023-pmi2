#include <stdio.h>
int main() {
	int arr[5][5];
	int tmp;
	int mx = -10000;
	int mxlineindex=0;

	for (int i = 0;i < 5;i++) {
		printf("print %d line:",i+1);
		for (int j = 0;j < 5;j++) {
			scanf_s("%d", &arr[i][j]);
		}
	}
	for (int i = 0;i < 5;i++) {
		if (arr[i][0] > mx) {
			mx = arr[i][0];
			mxlineindex = i;
		}
	}
	for (int j = 0;j < 5;j++) {
		tmp = arr[0][j];
		arr[0][j] = arr[mxlineindex][j];
		arr[mxlineindex][j] = tmp;
	}
	for (int i = 0;i < 5;i++) {
		for (int j = 0;j < 5;j++) {
			printf("%d ", arr[i][j]);
			if (j == 4) {
				printf("\n");
			}
		}
	}
}