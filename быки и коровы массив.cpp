
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n,i,s,s1,c,c1,j;
    int bull=0, cow=0;
	int a[100];
    int b[100];

	printf("Vvedite dliny ");
	scanf_s("%i", &n);
    s = 0;
    for (i = 0;i < n;i++)
    {
        s1 = rand();
        a[i] = s1 % 10;
    }
    for (i = 0;i < n;i++)
    {
        printf("%i ", a[i]);
    }

	
    while (bull != n)
    {
        bull = 0, cow = 0;
        printf("vash variant: ");
        scanf_s("%i", &c);
        for (i = 0;i < n;i++)
        {
            c1 = c % 10;
            c = c / 10;
            b[i] = c1;
        }
        /*for (i = 0;i < n;i++)
        {
            printf("%i ", b[i]);
        }*/


        for (i = 0;i < n;i++)
        {
            if (b[i] == a[i])
            {
                bull++;
            }
            else
            {
                for (j = 0;j < n;j++)
                {
                    if (b[i] == a[j])
                    {
                        cow++;
                    }
                }
            }
        }
        printf_s("buki=%i\nkorovu=%i\n", bull, cow);
    }
}



