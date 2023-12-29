#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void zerkalo(int matrix[100][100], int n) {
    int minelstr = 0;
    int minelement = matrix[0][0];

    for (int i = 1; i < n; i++) {
        if (matrix[i][i] < minelement) {
            minelement = matrix[i][i];
            minelstr = i;
        }
    }

    int vr;
    for (int i = 0; i < n / 2; i++) {
        vr = matrix[minelstr][i];
        matrix[minelstr][i] = matrix[minelstr][(n - 1) - i];
        matrix[minelstr][(n - 1) - i] = vr;
    }
}

void printmatrix(int matrix[100][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int n;
    int matrix[100][100];

    printf("vvedite por-ok matrix n: ");
    scanf("%d", &n);

    printf("vvedite el-ti matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("vasha matrix:\n");
    printmatrix(matrix, n);

    zerkalo(matrix, n);

    printf("result:\n");
    printmatrix(matrix, n);

    return 0;
}
