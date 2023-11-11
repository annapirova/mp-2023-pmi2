#include "stdio.h"
#include "time.h"
#include "stdlib.h"
int main()
{
    srand(time(NULL));
    int a[20],n=20, i, max=-100000, maxi=-1, min=100000, mini=-1;
    for(i=0;i<n;i++)
    {
        a[i]=-100+rand()%201;
        printf("%d ", a[i]);
        if(a[i]<min)
        {
            min=a[i]; /* первый наименьший строго <*/
            mini=i;
        }
        if(a[i]>=max)
        {
            maxi=i;
            max=a[i]; /*последний намбольший нестрого >*/
        }
    }
    printf("\n");
    printf("%d ", min);
    printf("%d ", max);
    printf("\n");
    if(mini<maxi)
    {
        for(i=mini+1;i<mini+(maxi-mini)/2+1;i++)
        {
            int st=a[i];
            a[i]=a[maxi-(i-mini)];
            a[maxi-(i-mini)]=st;
        }
    }
    if(maxi<mini)
    {
        for(i=maxi+1;i<maxi+(mini-maxi)/2+1;i++)
        {
            int st=a[i];
            a[i]=a[mini-(i-maxi)];
            a[mini-(i-maxi)]=st;
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d ", a[i]);

    }
    
    return 0;
}