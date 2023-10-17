#include "stdio.h"
#include "math.h"
#include "stdlib.h"
int main()
{
    int n,a,num,j,i,k;
    n = 5 + rand()%95;
    int m[n];
    for (a = 0; a < n; a++)
    {
        m[a] = rand()%100;
    }
    scanf("%d",&num);
    for (k = 0; k < 200;k++)
    {
        for (i = 0; i < n - 1;i++)
        {
            for (j = i + 1; j < n;j++)
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