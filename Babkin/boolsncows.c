#include "stdio.h"
#include "math.h"
#include "stdlib.h"
int main()
{
    int n,l,your_num,a,m,b,sum;
    scanf("%d",&n);
    int k[n],z[n];
    for (l = 0;l < n;l += 1)
    {
        k[l] = 1 + rand()%9;
    }
    printf("Enter your number \n");
    scanf("%d",&your_num);
    for (a = n;a > 0; a -= 1)
    {
        z[a] = your_num % 10;
        your_num = your_num / 10;
    }
    sum = 0;
    for (m = 0;m < n;m += 1)
    {
        for (b = 0;b < n;b += 1)
        {
            if (k[m] == z[b])
            {
                if (m == b)
                {
                    printf("1");
                    sum += 1;
                    break;
                }
                if (m != b)
                {
                    printf("2");
                    break;
                }
            }
        }
    }
    if (sum == n)
    {
        printf("First attempt,GG!");
    }
    else
    {
        printf("Try again! \n");
        while (sum != n)
        {
            printf("Enter your number \n");
            scanf("%d",&your_num);
            for (a = n;a > 0; a -= 1)
            {
                z[a] = your_num % 10;
                your_num = your_num / 10;
            }
            for (m = 0;m < n;m += 1)
            {
                for (b = 0;b < n;b += 1)
                {
                    if (k[m] == z[b])
                    {
                        if (m == b)
                        {
                            sum += 1;
                            printf("1");
                            break;
                        }
                        else
                        {
                            printf("2");
                            break;
                        }
                    }
                }
            }
            if (sum == n)
            {
                printf("You did it! You win a game!");
            }
            else
            {
                printf("You did it...wrong. Try again!\n");
            }
        }
    }
    return 0;
}