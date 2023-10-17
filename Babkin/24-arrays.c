#include "stdio.h"
#include "math.h"
#include "stdlib.h"
int main()
{
    int n,a,num,j,i,comme;
    n = 5 + rand()%95;
    int m[n];
    for (a = 0; a < n; a++)
    {
        m[a] = rand()%10000;
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = 1; j < n; j++)
        {
            comme = 0;
            if (m[i] == m[j])
            {
                comme = 1;
                printf("This array has some equal elements");
            }
            if (comme == 1) {break;}
        }
        if (comme == 1) {break;}
    }
    return 0;
}