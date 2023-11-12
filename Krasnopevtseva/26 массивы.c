#include "stdio.h"
#include "locale.h"
#include "math.h"
//определяет количество участков, на которых элементы данного массива возрастают;

int kolsegments(int arr[], int size) {
    int count = 0;
    int i = 0;

    while (i < size - 1) {
        while (i < size - 1 && arr[i] >= arr[i + 1]) {
            i++;
        }

        if (i == size - 1) {
            break;
        }

        while (i < size - 1 && arr[i] < arr[i + 1]) {
            i++;
        }

        count++;
    }

    return count;
}
int main() {
	setlocale(LC_CTYPE, "Russian");
    int arr[] = { 1, 2, 3, 2, 4, 5, 7, 6, 9 };
    int size = sizeof(arr) / sizeof(arr[0]);

    int res = kolsegments(arr, size);

    printf("Количество участков возрастания: %d\n", res);

return 0;
}