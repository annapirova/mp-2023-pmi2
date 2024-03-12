#include "stdio.h"
#include "locale.h"
int main()
{
    setlocale(LC_CTYPE, "Russian");
    int n, sum=0, i=0;
    scanf("%d",&n);
    do
    {i++;
    if(n%i==0) sum+=i;
    } while (sum<n);
    printf("%d- ",n);
    if (sum==n) printf("Число совершенное");
    else printf("Число не совершенное");
    return 0;
}