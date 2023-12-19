#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n;
    printf("Enter the number of rows and columns: ");
    scanf_s("%d %d", &m, &n);

    int** matrix = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
    }

    // Input the elements of the matrix
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf_s("%d", &matrix[i][j]);
        }
    }

    // Find the row with the minimum element
    int minRow = 0;
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] < matrix[minRow][j]) {
                minRow = i;
            }
        }
    }

    // Delete the row with the minimum element
    for (int i = minRow; i < m - 1; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = matrix[i + 1][j];
        }
    }

    // Decrement the number of rows
    m--;

    // Print the modified matrix
    printf("Modified matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Free the dynamically allocated memory
    for (int i = 0; i < m; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
