#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "stdbool.h"
int main()
{
    int *matrrix;
    int n;
    int *pixmassive;
    int *whatmassive; int *etalonmassive;
    bool mihp = true;
    scanf_s("%d",&n);
    printf("\n");
    etalonmassive = (int*)malloc(n*sizeof(int));
    for (int y = 0;y < n;y++)
    {
        etalonmassive[y] = 1;
    }
    matrrix = (int*)malloc(n*n*sizeof(int));
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n;j++)
        {
            matrrix[n*i+j] = 1 + rand() % (n);
            printf("%d ",matrrix[n*i+j]);
        }
        printf("\n");
    }
    pixmassive = (int*)malloc(n*sizeof(int));
    for (int k = 1;k<n+1;k++)
    {
        pixmassive[k-1] = k;
    }
    for (int i = 0;i < n;i++)
    {
        whatmassive = (int*)malloc(n*sizeof(int));
        for (int j = 0; j < n;j++)
        {
            for (int s = 0; s < n; s++)
            {
                if (matrrix[n*i + j] == pixmassive[s])
                {
                    whatmassive[s] += 1;
                }
            }
        }
        for (int p = 0;p<n;p++)
        {
            if (etalonmassive[p] != whatmassive[p])
            {
                mihp = false;
                break;
            }
        }
        if (mihp == false)
        {break;}
        free(whatmassive);
    }
    if (mihp == true)
    {
        for (int j = 0;j < n;j++)
        {
            whatmassive = (int*)malloc(n*sizeof(int));
            for (int i = 0; i < n;i++)
            {
                for (int s = 0; s < n; s++)
                {
                    if (matrrix[n*i + j] == pixmassive[s])
                    {
                        whatmassive[s] += 1;
                    }
                }
            }
            for (int p = 0;p<n;p++)
            {
                if (etalonmassive[p] != whatmassive[p])
                {
                    mihp = false;
                    break;
                }
            }
            if (mihp == false)
            {break;}
            free(whatmassive);
        }
    }
    if (mihp == true)
    {
        printf("LATIN MATRIX");
    }
    if (mihp == false)
    {
        printf("NOT LATIN MATRIX");
    }
}
