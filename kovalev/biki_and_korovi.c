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
    int k=1,ch_mas[n];
    for(i=n-1;i>=0;i--)
    {
        ch_mas[i]=(ch%(int)pow(10,k))/pow(10,k-1);
        k++;
    }
    int popitka,popitka_mas[n];
    do
    {   int bik=0,kor=0,k=1;
        scanf("%d", &popitka);
        if(popitka==ch) break;
        for(i=n-1;i>=0;i--)
    {
        popitka_mas[i]=(popitka%(int)pow(10,k))/pow(10,k-1);
        k++;
    }
    for(i=0;i<n;i++)
    {
        if (ch_mas[i]==popitka_mas[i])
        {
            bik++;
        }
        else
        {
            for(j=0;j<n;j++)
            {
            if(ch_mas[i]==popitka_mas[j]) kor++;
            }
        }
    }
    printf("Кол-во быков-%d ",bik);
    printf("Кол-во коров-%d\n",kor);
     } while (1);
    printf("Вы угадали! Это число-%d",ch);
    return 0;
}