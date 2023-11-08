#include "stdio.h"
#include "math.h"
int main()
{
    int m,n,i,fact,fact1,fact2,p,p1,p2,c;
    scanf_s("%d\n",&n);
    for (i = 1; i <= n;i++)
    {
        for (m = 0;m<=i;m++)
        {
            fact = 1;
            fact1 = 1;
            fact2 = 1;
            for (p = 1;p<=i;p++)
            {
                fact = fact*p;
            }
            for (p1 = 1;p1<=m;p1++)
            {
                fact1 = fact1*p1;
            }
            for (p2 = 1;p2<=(i - m);p2++)
            {
                fact2 = fact2*p2;
            }
            c = fact/(fact1*fact2);
            printf_s("%d ",c);
        }
        printf_s("\n");
    }
}