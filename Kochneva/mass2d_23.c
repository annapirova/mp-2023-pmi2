#include <stdio.h>
#include <stdlib.h>


// Функция для поиска минимального элемента в массиве
float findMinElement(float arr[], int n) {
    float min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// Функция для зеркального разворота строки матрицы
void mirrorReverse(float arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        float temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}

int main() {
    int n;
    printf("Enter the size of the square matrix: ");
    scanf_s("%d", &n);

    float** A = (float**)malloc(n * sizeof(float*));
    for (int i = 0; i < n; i++) {
        A[i] = (float*)malloc(n * sizeof(float));
    }

    printf("Enter the elements of the matrix: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf_s("%f", &A[i][j]);
        }
    }

    float minElement = findMinElement(A[0], n);
    int minIndex = 0;

    for (int i = 1; i < n; i++) {
        if (A[i][i] == minElement) {
            minIndex = i;
            break;
        }
    }

    // Зеркальный разворот строки с минимальным элементом на главной диагонали
    mirrorReverse(A[minIndex], n);

    printf("The matrix after the mirror reversal:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2f ", A[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++) {
        free(A[i]);
    }
    free(A);

    return 0;
}
