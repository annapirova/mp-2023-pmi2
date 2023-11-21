#include "stdio.h"
#include "math.h"
#include "stdbool.h"
int main()
{
    int prcodes[10] = {2341,5130,1736,1334,9012,5136,9121,1000,7619,2280};
    double price[10] = {231,351,102,412,90,10,67,190,61,345};
    double discounts[10] = {0.19,0.1,0.06,0.12,0.3,0.32,0.09,0.21,0.1,0.12};
    int productlist[10];
    double pricelist[10];
    int countlist[10];
    double discountlist[10];
    int input = 1;
    int counter = 0;
    int sum = 0;
    printf("If you want to end shopping, please print 0\n");
    while (input != 0)
    {
        int y = 0;
        scanf("%d",&input);
        printf("\n");
        bool hmm = false;
        bool what = true;
        for (int cai = 0;cai < counter;cai++)
        {
            if (productlist[cai] == input)
            {
                y = 1;
                break;
            }
        }
        for (int i = 0;i < 10;i++)
        {
            if ((prcodes[i] == input) && (y == 0))
            {
                printf("scanning...\n");
                productlist[counter] = input;
                pricelist[counter] = price[i];
                countlist[counter] = 1;
                discountlist[counter] = discounts[i];
                printf("You added %d to your cheque. Price: %lf . Discount: %lf per cents. \n",input,price[i],discounts[i]*100);
                hmm = true;
                counter ++;
            }
            else
            {
                if (y == 1)
                {
                    for(int o = 0;o < counter;o++)
                    {
                        if (productlist[o] == input)
                        {
                            printf("scanned. You added another %d.",productlist[o]);
                            countlist[o]++;
                            hmm = true;
                            what = false;
                            break;
                        }
                    }
                }
            }
            if (what == false)
            {break;}
        }
        if (hmm == false)
        {printf("Your product doesnt exist\n");}
    }
    printf("======== YOUR CHEQUE ========\n");
    for (int p = 0;p < counter;p++)
    {
        printf("======\n");
        printf("%d.\nProduct....%d\nOne cost....%lf\nAmount....%d\nAll cost....%lf\n",p+1,productlist[p],round(pricelist[p]*discountlist[p]),countlist[p],round(pricelist[p]*discountlist[p])*countlist[p]);
        printf("======\n");
        sum += round(pricelist[p]*discountlist[p])*countlist[p];
    }
    printf("Conclusive summ: %d\n",sum);
    printf("Thank you for using our virtual shop.");
}
