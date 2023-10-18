#include "stdio.h"
#include "math.h"
#include "stdlib.h"
int main()
{
    int a,num,j,i,comme;
    int m[100];
    for (a = 0; a < 100; a++)
    {
        m[a] = rand()%10000;
    }
    for (i = 0; i < 100 - 1; i++)
    {
        for (j = 1; j < 100; j++)
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