#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMS 5

int countMonotonicIntervals(int a[], int n)
{
    int k = 0;

    for (int i = 1; i < n - 1; i++)
    {
        if ((a[i] > a[i - 1] && a[i] > a[i + 1]) || (a[i] < a[i - 1] && a[i] < a[i + 1]))
        {
            k++;
        }
    }

    return k;
}

int main()
{
    srand(time(0));

    int a[MAX_NUMS];
    int n = MAX_NUMS;

    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 10;
    }

    printf("Generated array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    int k = countMonotonicIntervals(a, n);

    printf("\nNumber of monotonic intervals: %d\n", k);

    return 0;
}