#include "stdio.h"
#include "math.h"
#include "stdlib.h"
int main()
{
    int a,num,j,i,comme;
    int m[100];
    for (a = 0; a < 100; a++)
    {
        m[a] = rand()%1000;
        printf("%d\n",m[a]);
    }
    for (i = 0; i < 100; i++)
    {
        for (j = 0; i + j < 100; j++)
        {
            if ((m[i] == m[i+j]) && (j + i != i))
            {
                printf("It has some equal elements: %d on %d and %d on %d",m[i],i,m[i+j],i+j);
                return 0;
            }
        }
    }
    return 0;
}
