#include "stdio.h"
#include "math.h"
#include "stdlib.h"
int main()
{
    int p[10];
    int o,mini,s,a1,a2,p1,p2;
    mini = 102;
    scanf_s("%d",&o);
    for (int i = 0;i < 10;i++)
    {
        p[i] = rand() % 101;
    }
    for (int k = 0;k < 10;k++)
    {
        for (int m = k + 1;m < 10;m++)
        {
            s = abs(p[k] + p[m] - o);
            if (s < mini)
            {
                mini = s;
                a1 = p[k];
                a2 = p[m];
                p1 = k;
                p2 = m;
            }
        }
    }
    printf_s("The nearest numbers are %d on %d and %d on %d",a1,p1,a2,p2);
}