#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#define MAX_NUMS 10

int main()
{
    srand(time(0));
    int n, i,b,k,p, min,max,l, a[MAX_NUMS];
    n=MAX_NUMS;
    
    for (i = 0; i < n; i++)
    {
        b = rand() % 10;
        a[i] = b;
    }

    for (i = 0; i < n; i++)
    {
        printf("%d", a[i]);
    }

    k = 0;
    min = a[0];
    for (i = 0; i < n; i++)
    {   
        if (a[i] < min) {
            min = a[i]; k = i;
        }
    }

    l = 0;
    max = a[0];
    for (i = 0; i < n; i++)
    {
        if (a[i] >= max) {
            max = a[i]; l = i;
        }
    }
  
    int c;
    if (k > l) {
        c = k;
        k = l;
        l = c;
        }
    if ((l - k)< 3) printf("no changes");
    printf("\n\npos_l= %d pos_r= %d\n\n", k, l);
    int z = k + 1;

    for (i = z; i < (z+((l-z)/2)); i++)
    {
        p = a[i];
        a[i] = a[k+l-i];
        a[k+l-i] = p;
    }
    //printf("  %d %d   ", z, l );
  
    for (i = 0; i < n; i++)
    {
        printf("%d", a[i]);
    }
    printf("\n");
    return 0;
}