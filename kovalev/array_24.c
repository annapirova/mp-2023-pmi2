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
    int a[n], i, j, flag=0;
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
            if(a[i]==a[j])
            {
                flag=1;
                break;
            }
        }
    }
    if(flag!=0) printf("совпадение найдено");
    else printf("совпадений нет");
    return 0;

}