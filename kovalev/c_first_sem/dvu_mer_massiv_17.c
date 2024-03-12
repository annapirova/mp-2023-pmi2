#include "stdio.h"
#include "time.h"
#include "stdlib.h"

// transponirovanie

int main()
{
    srand(time(NULL));
    printf("input size of matrix n*n\n");
    int n,i,j;
    scanf("%d", &n);
    int **matrix=(int**)malloc(n*sizeof(int*));
    for(i=0;i<n;i++)
    {
        matrix[i]=(int*)malloc(n*sizeof(int));
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
       for (int j = 0; j < n; j++) {
        matrix[i][j]=1+rand()%20;
       printf("%2d ", matrix[i][j]);
       }
       printf("\n");
    }
    for (int i = 0; i < n/2; i++) {
       for (int j = i; j < n-i-1; j++) {
          int temp = matrix[i][j];
          matrix[i][j] = matrix[n-j-1][i];
            matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
            matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
            matrix[j][n-i-1] = temp;
        }
    }
    printf("\n");
    printf("\n");
    for (int i = 0; i < n; i++) {
       for (int j = 0; j < n; j++) {
       printf("%2d ", matrix[i][j]);
       }
       printf("\n");
    }
    
    for(i=0;i<n;i++)
    {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}