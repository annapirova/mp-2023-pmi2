#include <stdio.h>

void output(int* arr, int len) { // vivod snachala chotnih potom nechetnih
	for (int i = 0; i < len; i++) {(i % 2 == 0) ? printf("%d", arr[i]) : printf("  "); }
	for (int i = 0; i < len; i++) { (i % 2 != 0) ? printf("%d", arr[i]) : printf("  ");	}
}
void locmax(int* arr, int len) {
	for (int i = 0; i < len; i++) {
		if (i == len - 2 && arr[i - 1] < arr[i] || arr[i] > arr[i + 1])
			printf(" %d ", arr[i++]);
	}
}
int main() {
	int arr[10] = {0, 10, 1, 2, 3, 1, 4, 23, 8, 9}; int len = *(&arr + 1) - arr;
	locmax(arr, len);
	return 0;
}