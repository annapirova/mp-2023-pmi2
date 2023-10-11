#include "stdio.h"
#include "locale.h"
#include "time.h"
#include "stdlib.h"
#include "math.h"
int main()
{
    srand(time(NULL));
    setlocale(LC_CTYPE, "Russian");
    int n,i,j,ch=0;;
    scanf("%d",&n);
    int isx[10]={0,1,2,3,4,5,6,7,8,9};
    if((n<2) || (n>5))
    {
        printf("Данные не коректны");
        return 1;
    }
    for(i=0;i<n;i++)
    {
        int j=rand()%9;
        while(isx[j]==-1)
        {
            j=rand()%9;
        }
        ch+=(isx[j]*pow(10,i));
        isx[j]=-1;
    }
    printf("%d\n",ch);
    /*random chisla*/
    int popitka;
    scanf("%d\n", &popitka);

    
    while (popitka!=ch)
    {
        int kor=0,bik=0;
        scanf("%d\n", &popitka);

    }

    printf("Вы угадали! Это число-%d",ch);
  return 0;
}