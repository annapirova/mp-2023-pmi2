#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "stdbool.h"
int main()
{
    int n; int *hdmatrix;int *hay;int *howmuch;
    printf("Enter your n \n");
    scanf("%d",&n);
    printf("\n");
    hdmatrix = (int*)malloc(n*n*sizeof(int));
    for (int queo = 0;queo < n;queo++)
    {
        for (int sint = 0;sint < n;sint++)
        {
            hdmatrix[n*queo + sint] = 1 + rand()%(n);
            printf("%d ",hdmatrix[n*queo + sint]);
        }
        printf("\n");
    }
    hay = (int *)malloc(n*sizeof(int));
    for (int k = 0;k < n;k++)
    {
        hay[k] = k + 1;
    }
    bool what = true;
    for (int s = 0;s<n;s++)
    {
        howmuch = (int*)malloc(n*sizeof(int));
        for (int i = 0;i < n;i++)
        {
            howmuch[hdmatrix[n*s + i]-1]+=1;
        }
        for(int q = 0;q < n; q++)
        {
            if (howmuch[q] != 1)
            {
                what = false;
                break;
            }
        }
        free(howmuch);
        if (what == false)
        {
            break;
        }
    }
    if (what == true)
    {
        for (int s = 0;s<n;s++)
        {
            howmuch = (int*)malloc(n*sizeof(int));
            for (int i = 0;i < n;i++)
            {
                howmuch[hdmatrix[n*i + s]-1]+=1;
            }
            for(int q = 0;q < n; q++)
            {
                if (howmuch[q] != 1)
                {
                    what = false;
                    break;
                }
            }
            free(howmuch);
            if (what == false)
            {
                break;
            }
        }
    }
    if (what == true)
    {
        printf("You've got a LATIN SQUARE");
    }
    else
    {
        printf("It is unintresting usual matrix");
    }
}