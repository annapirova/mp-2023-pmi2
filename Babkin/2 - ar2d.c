#include "stdio.h"
#include "math.h"
#include "stdlib.h"
int main()
{
    int n;
    int *A; int *B;
    scanf("%d",&n);
    printf("\n");
    A = (int*)malloc(n*n*sizeof(int));
    for (int i = 0; i < n*n;i++)
    {
        A[i] = rand() % 101;
        printf("%d ",A[i]);
    }
    printf("\n");
    B = (int*)malloc(n*n*sizeof(int));
    for (int k = 0;k < n;k++)
    {
        for (int j = 0;j < n;j++)
        {
            B[n*k+j] = A[n*k+j];
            printf("%d ", B[n*k+j]);
        }
        printf("\n");
    }
    free(A);
    free(B);
}