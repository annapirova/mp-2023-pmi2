#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j;
    int f = -1;
    int sum1 = 0, sum2 = 0;
    int a = 0, b = 0;
    int n;
    printf("Vvedite kolichestvo strok i stolbcov kvadratnoi matrici: ");
    scanf_s("%d", &n);
    int** A = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n;i++)
        A[i] = (int*)malloc(sizeof(int) * n);
    printf("Vvedite elementi matrici:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf_s("%d", &A[i][j]);
        }
    }
    printf("\nSgenerirovannay matrica: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
   for (i = 0; i < n; i++)
    {
        sum1 += A[i][i];
        sum2 += A[i][n - 1 - i];
    }
   f = n;
   for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            a += A[i][j];
            b += A[j][i];
        }
        if ((a == b) && (b == sum1) && (sum1 == sum2))
            f = f - 1;
        a = 0; b = 0;
    }

   if (f == 0)
       printf("Magic Square");
   else
       printf("Not a magic Square");

   for (int i = 0; i < n + 1; i++)
       for (int j = 0; j < n + 1; j++)
           free(A[i][j]);
   free(A);
   return 0;
}
