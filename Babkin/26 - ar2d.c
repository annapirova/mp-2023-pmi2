#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "stdbool.h"
int main()
{
    int n; int *hdmatrix;int *hay;int *howmuch;
    printf_s("Enter your n \n");
    scanf_s("%d",&n);
    printf("\n");
    hdmatrix = (int*)malloc(n*n*sizeof(int));
    for (int queo = 0;queo < n;queo++)
    {
        for (int sint = 0;sint < n;sint++)
        {
            hdmatrix[n*queo + sint] = 1 + rand()%(n);
            printf_s("%d ",hdmatrix[n*queo + sint]);
        }
        printf_s("\n");
    }
    bool cond = true;
    hay = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++)
    {
        for (int u = 0; u < n; u++)
        {
            for (int j = 0; j < n; j++)
            {
            }
        }
    }
}
