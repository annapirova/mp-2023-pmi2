#include "stdio.h"
int dry(int a[],int samma)
{
    int op = 0,drya = 0;
    printf("Dry days data collecting...\n");
    for (op;op < samma;op++)
    {
        if (a[op] == 0)
        {drya += 1;
        printf("Day %d\n",op+1);}
    }
    printf("\n");
    printf("All amount: %d",drya);
}
int average(int a[],int samma)
{
    printf("Average falls calculating...\n");
    int hem;
    int i = 0; int sum = 0;
    for (i;i < samma;i++)
    {
        sum = sum + a[i];
    }
    hem = sum / samma;
    printf("Average falls: %d",hem);
}
int averagerain(int a[],int samma)
{
    printf("Average falls (with rain only) calculating...\n");
    int hem; int cadet = 0;
    int i = 0; int sum = 0;
    for (i;i < samma;i++)
    {
        if (a[i] != 0)
        {sum = sum + a[i];}
        else
        {cadet += 1;}
    }
    hem = sum / (samma - cadet);
    printf("Average falls (with rain only): %d",hem);
}
int minmax(int a[],int samma)
{
    int min = 78787878;
    int max = 0;
    int i = 0;
    int save,save1;
    for (i;i < samma;i++)
    {
        if (a[i] != 0)
        {
            if (a[i] < min)
            {min = a[i];
            save = i + 1;}
            if (a[i] > max)
            {max = a[i];
            save1 = i + 1;}
        }
    }
    printf("Min fell in %d : %d, Max fell in %d : %d.",save,min,save1,max);
}
int extendedstats(int a[],int samma,double avg)
{
    printf("Days when falls were lower than monthly ones: \n");
    int i = 0;
    for (i;i < samma;i++)
    {
        if ((a[i] != 0) && (a[i] < avg))
        {
            printf("%d\n",i + 1);
        }
    }
}
int main()
{
    int datamain[] = {412,515,0,24,14,693,182,35,102,0,0,0,0,0,0,24,294,47,0,192,390,100,0,0,24,64,97,90,290,567,34};
    dry(datamain,31);
    printf("\n");
    average(datamain,31);
    printf("\n");
    averagerain(datamain,31);
    printf("\n");
    minmax(datamain,31);
    printf("\n");
    int hem;
    int i = 0,sum = 0;
    for (i;i < 31;i++)
    {
        sum += datamain[i];
    }
    hem = sum / 31;
    extendedstats(datamain,31,hem);
}