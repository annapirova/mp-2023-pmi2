#include <stdio.h>
#define MAX_ROWS 100
#define MAX_COLS 100
void findSaddlePoints(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols, int saddlePoints[MAX_ROWS * MAX_COLS][2], int* numSaddlePoints)
{
    *numSaddlePoints = 0;
    for (int i = 0; i < rows; i++)
    {
        int minRow = matrix[i][0];
        int colIndex = 0; // Находим минимальное значение в строке и запоминаем индекс столбца
        for (int j = 1; j < cols; j++)
        {
            if (matrix[i][j] < minRow)
            {
                minRow = matrix[i][j];
                colIndex = j;
            }
        }
        // Проверяем, является ли минимальное значение в строке максимальным в столбце
        int isSaddlePoint = 1;
        for (int k = 0; k < rows; k++)
        {
            if (matrix[k][colIndex] > minRow)
            {
                isSaddlePoint = 0;
                break;
            }
        }
        // Если является, добавляем индексы в массив седловых точек
        if (isSaddlePoint)
        {
            saddlePoints[*numSaddlePoints][0] = i;
            saddlePoints[*numSaddlePoints][1] = colIndex;
            (*numSaddlePoints)++;
        }
    }
}
int main()
{
    int matrix[MAX_ROWS][MAX_COLS];
    int rows, cols;
    printf("Vvedite count strok: ");
    scanf_s("%d", &rows);
    printf("Vvedite count stolbcov: ");
    scanf_s("%d", &cols);
    printf("vvedi element matrici:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf_s("%d", &matrix[i][j]);
        }
    }
    int saddlePoints[MAX_ROWS * MAX_COLS][2];
    int numSaddlePoints;
    findSaddlePoints(matrix, rows, cols, saddlePoints, &numSaddlePoints);
    printf("sedlovie tochki:\n");
    for (int i = 0; i < numSaddlePoints; i++)
    {
        printf("(%d, %d)\n", saddlePoints[i][0], saddlePoints[i][1]);
    }
    return 0;
}