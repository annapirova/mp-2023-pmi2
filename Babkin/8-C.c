#include "stdio.h"
#include "math.h"
int main()
{
    int h,n,nex;
    scanf("%d",&h);
    n = 1;
    nex = 0;
    while (h != n)
    {
        if(h % n == 0)
        {
            nex = nex + n;
            n += 1;
        }
        else
        {n+= 1;}
    }
    if (nex == h)
    {
        printf("Ideal");
    }
    else
    {printf("NOT IDEAL");}
}