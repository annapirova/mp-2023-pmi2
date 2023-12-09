#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols;
    printf("Vvedite kol-vo strok i stolbtsov matrix: ");
    scanf_s("%d %d", &rows, &cols);

    // выделение памяти под исходную матрицу
    int** matrix = malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = malloc(cols * sizeof(int));
    }

    // заполнение исходной матрицы
    printf("Vvedite elementi matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf_s("%d", &matrix[i][j]);
        }
    }

    // выделение памяти под транспонированную матрицу
    int** transposedMatrix = malloc(cols * sizeof(int*));
    for (int i = 0; i < cols; i++) {
        transposedMatrix[i] = malloc(rows * sizeof(int));
    }

    // транспонирование матрицы
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposedMatrix[j][i] = matrix[i][j];
        }
    }

    // вывод транспонированной матрицы
    printf("Transponirovanaya matrix:\n");
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            printf("%d ", transposedMatrix[i][j]);
        }
        printf("\n");
    }

    // освобождение памяти
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    for (int i = 0; i < cols; i++) {
        free(transposedMatrix[i]);
    }
    free(transposedMatrix);

    return 0;
}
