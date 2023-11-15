#include "stdio.h"
#include "math.h"
#include "stdbool.h"
int main()
{
    int strhcodes[10] = {9241,4124,3313,8236,9102,6022,7247,4576,1000,6123};
    double cost[10] = {25,19,61,24,90,123,119,51,33,516};
    double discounts[10] = {0.23,0.45,0.15,0.20,0.09,0.1,0.08,0.05,0.07,0.25};
    double costnew[10] = {0,0,0,0,0,0,0,0,0,0};
    double discountsnew[10] = {0,0,0,0,0,0,0,0,0,0};
    int chequelist[1000];
    int chequelistcount[10];
    int chequelistcorrect[10];
    int a;
    int alsum = 0;
    int count = 0;
    int count1 = 0;
    int count2 = 0;
    printf_s("Print 0 in codespace to finish. Remember, your bill cannot be empty.\nEnter the product code: ");
    scanf_s("%d\n",&a); //По какой то неизвестной причине выходные значения терминала смещаются. Из-за чего возникают визуальные ошибки. Я не знаю как это править
    while (a != 0)
    {
        bool k9 = false;
        for (int i = 0;i < 10;i++)
        {
            if (a == strhcodes[i])
            {
                printf_s("About: \n");
                printf_s("Strhcode: %d    Cost: %lf    Discount: %lf(in per cents)\n",strhcodes[i],cost[i],discounts[i]*100);
                k9 = true;
                chequelist[count] = strhcodes[i];
                printf_s("Your cheque has been updated\n");
            }
        }
        if (k9 == false)
        {
            printf("This product doesnt exist\n");
        }
        count += 1;
        printf_s("Enter the product code: ");
        scanf_s("%d\n",&a);
    }
    for (int p = 0;p < 1000;p++)
    {
        for (int g = 0;g < 10;g++)
        {
            if (chequelist[p] == strhcodes[g])
            {
                for (int search = p + 1;search < 1000;search++)
                {
                    if (chequelist[search] == chequelist[p])
                    {
                        chequelistcount[count1] += 1;
                        chequelist[search] = 0;
                    }
                }
                count1 += 1;
            }
        }
    }
    for (int t = 0;t < 1000;t++)
    {
        if (chequelist[t] != 0)
        {
            chequelistcorrect[count2] = chequelist[t];
            count2 += 1;
        }
    }
    for (int gh = 0;gh < 10;gh ++)
    {
        for (int sh = 0;sh < 10;sh ++)
        {
            if (chequelistcorrect[gh] == strhcodes[sh])
            {
                costnew[gh] = cost[sh];
                discountsnew[gh] = discounts[sh];
            }
        }
    }
    printf_s("======== CHEQUE PRINTING ========\n");
    printf_s("=== TO BE PAID ===\n");
    for (int y = 0;y < count1;y++)
    {
        int kmit = y + 1;
        printf_s("%d. %d. Cost for one: %d. Amount: %d. Cost for all %d\n",kmit,chequelistcorrect[y],round(costnew[y]*discountsnew[y]),chequelistcount[y],round(costnew[y]*discountsnew[y])*chequelistcount[y]);
        alsum += round(costnew[y]*discountsnew[y])*chequelistcount[y];
    }
    printf_s("=======+ Total cost: %d +=======");
    printf_s("Thank you for purchasing");
    return 0;
}