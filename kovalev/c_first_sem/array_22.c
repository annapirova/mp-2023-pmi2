#include "stdio.h"
#include "locale.h"
#include "time.h"
#include "math.h"
#include "stdlib.h"
int main()
{
    srand(time(NULL));
    setlocale(LC_CTYPE, "Russian");
    int n;
    scanf("%d",&n);
    int a[n], i, j, delta=100000, it,jt;
    for(i=0;i<n;i++)
    {
        a[i]=rand()%100;
        printf("%d ",a[i]);
    }
    printf("\n");
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(delta>abs(a[i]-a[j]))
            {
                delta=abs(a[i]-a[j]);
                it=i;
                jt=j;
            }
        }
    }
    printf("(%d;%d)\n",it,jt);
    return 0;

}