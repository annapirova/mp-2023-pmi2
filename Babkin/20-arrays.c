#include "stdio.h"
#include "math.h"
#include "stdlib.h"
int main()
{
    int a,num,j,i,k;
    int m[100];
    for (a = 0; a < 100; a++) //o
    {
        m[a] = rand()%100;
    }
    scanf("%d",&num);
    for (k = 0; k < 200;k++)
    {
        for (i = 0; i < 100 - 1;i++)
        {
            for (j = i + 1; j < 100;j++)
            {
                if (num + k == m[i] + m[j])
                {
                    printf("%d , %d", &m[i],&m[j]);
                    return 0;
                }
            }
        }
    }
}