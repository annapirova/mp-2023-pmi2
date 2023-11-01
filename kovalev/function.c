#include "stdio.h"
#include "locale.h"
#include "time.h"
#include "stdlib.h"
#include "math.h"
int binary_search(int a[], int n,int target)
{
    int r=n-1,l=0;
    while(l<=r)
    {
        int c=(l+r)/2;
        if(a[c]==target) return c;
        if(a[c]<target) l=c+1;
        if(a[c]>target) r=c-1;
    }
    return -2; 
}
void isk_repeat(int a[], int b[],int n,int m)
{
    
}

int main()
{
    srand(time(NULL));
    setlocale(LC_CTYPE, "Russian");
    int a[20],i;
    for(i=0;i<20;i++)
    {
        a[i]=i+300;
        printf("%d ", a[i]);
    }
    printf("\n");

    int zxc;
    scanf("%d",&zxc);
    printf("%d", binary_search(a,20,zxc));


return 0;
}
