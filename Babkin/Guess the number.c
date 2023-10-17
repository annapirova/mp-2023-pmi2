#include "stdio.h"
#include "math.h"
#include "stdlib.h"
int main()
{
    int gen,usr,count;
    count = 1;
    gen = (rand() % 1000);
    scanf("%d\n",&usr);
    while (usr != gen)
    {
        if (usr > gen)
        {
            printf("My number is lower,try again\n");
            count += 1;
            scanf("%d\n",&usr);
        }
        if (usr < gen)
        {
            printf("My number is bigger,try again\n");
            count += 1;
            scanf("%d\n",&usr);
        }
    }
    if (usr == gen)
    {
        printf("You won!It took you this count of attempts -> %d\n",count);
    }
    return 0;
}