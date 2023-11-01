#include "stdio.h"
#include "locale.h"
#include "time.h"
#include "stdlib.h"
#include "math.h"
int main()
{
    srand(time(NULL));
    setlocale(LC_CTYPE, "Russian");
    int zxc[10]={1,1,1,12,1,4,1,1,7,11};
    int i,j,n=10;
    printf("\n");
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        if(zxc[i]>zxc[j])
        {
            int tmp=zxc[i];
            zxc[i]=zxc[j];
            zxc[j]=tmp;
        }
    }
    int sump=0,razl=1,p=1;
    for(i=0;i<n;i++)
    {
        if(zxc[i]!=zxc[i+1])
        {
            sump+=p;
            if(p==1) razl++;
            p=1;
        }
        else
        {
            p++;
        }
    }
    printf("\n%d\n",(sump/razl));
    for(i=0;i<n;i++)
    {
        if(zxc[i]>(int)(sump/razl)) printf("%d ",zxc[i]);
    }
   



    




    return 0;
}