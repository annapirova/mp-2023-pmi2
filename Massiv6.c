#include <stdio.h>
#include <locale.h>
int sumElementsWithShift(int matrix[][100], int n, int k) {
    int sum = 0;
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (j == i + k || j == i - k) {
                sum += matrix[i][j];
            }
        }
    }

    return sum;
}

int main() {
    setlocale(LC_CTYPE, "Russian");
    int matrix[100][100];
    int n, k;
    int i, j;

    printf("Vvedi razmer matrici (N): ");
    scanf_s("%d", &n);

    printf("Znachenie sdviga(k): ");
    scanf_s("%d", &k);

    printf("Введите элементы матрицы:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf_s("%d", &matrix[i][j]);
        }
    }

    int sum = sumElementsWithShift(matrix, n, k);

    printf("Сумма элементов со сдвигом %d от диагонали матрицы: %d\n", k, sum);

    return 0;
}