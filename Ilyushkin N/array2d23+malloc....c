<<<<<<< HEAD
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void zerkalo(int** matrix, int n) {
    int minelstr = 0;
    int minelement = (*matrix)[0];

    for (int i = 1; i < n; i++) {
        if ((*matrix)[i * n + i] < minelement) {
            minelement = (*matrix)[i * n + i];
            minelstr = i;
        }
    }

    int vr;
    for (int i = 0; i < n / 2; i++) {
        vr = (*matrix)[minelstr * n + i];
        (*matrix)[minelstr * n + i] = (*matrix)[minelstr * n + (n - 1) - i];
        (*matrix)[minelstr * n + (n - 1) - i] = vr;
    }
}

void printmatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", (*matrix)[i * n + j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int n;
    int* matrix;

    printf("vvedite por-ok matrix n: ");
    scanf_s("%d", &n);
    matrix = (int*)malloc(n * n * sizeof(int));

    printf("vvedite el-ti matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf_s("%d", &matrix[i * n + j]);
        }
    }

    printf("vasha matrix:\n");
    printmatrix(&matrix, n);

    zerkalo(&matrix, n);

    printf("result:\n");
    printmatrix(&matrix, n);

    free(matrix);

    return 0;
=======
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void zerkalo(int** matrix, int n) {
    int minelstr = 0;
    int minelement = (*matrix)[0];

    for (int i = 1; i < n; i++) {
        if ((*matrix)[i * n + i] < minelement) {
            minelement = (*matrix)[i * n + i];
            minelstr = i;
        }
    }

    int vr;
    for (int i = 0; i < n / 2; i++) {
        vr = (*matrix)[minelstr * n + i];
        (*matrix)[minelstr * n + i] = (*matrix)[minelstr * n + (n - 1) - i];
        (*matrix)[minelstr * n + (n - 1) - i] = vr;
    }
}

void printmatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", (*matrix)[i * n + j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int n;
    int* matrix;

    printf("vvedite por-ok matrix n: ");
    scanf_s("%d", &n);
    matrix = (int*)malloc(n * n * sizeof(int));

    printf("vvedite el-ti matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf_s("%d", &matrix[i * n + j]);
        }
    }

    printf("vasha matrix:\n");
    printmatrix(&matrix, n);

    zerkalo(&matrix, n);

    printf("result:\n");
    printmatrix(&matrix, n);

    free(matrix);

    return 0;
>>>>>>> 12a20275fd310e33fd88048f2857584b8b54a5d0
}