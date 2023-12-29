#include "stdio.h"
#include "math.h"
#include "time.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"
void BubbleSort(int a[],int c)
{
    double time = 0.0;
    clock_t begin = clock();
    for (int m = 0; m < c; m++)
    {
        int iter=0, mrg = 0;
        for (int i = 0;i < c - 1 - m;i++)
        {
            if (a[i+1] < a[i])
            {
                int tmp = a[i+1];
                a[i+1] = a[i];
                a[i] = tmp;
            }
            else
            {iter++;}
        }
        if (iter == c - 2)
        {break;}
        for (int i = c - 1 - m; i > m;i --)
        {
            if (a[i] < a[i - 1])
            {
                int tmp = a[i-1];
                a[i-1] = a[i];
                a[i] = tmp;
            }
            else
            {mrg++;}
        }
        if (mrg == c - 2)
        {break;}
    }
    clock_t end = clock();
    time += (double)(end - begin) / CLOCKS_PER_SEC;
    bool flac = true;
    for (int m = 0;m<c - 1;m++)
    {
        if (a[m + 1] - a[m] < 0)
        {
            flac = false;
            break;
        }
    }
    if (flac == false)
    {
        for (int o = 0; o < c;o++)
        {
            printf("%d ",a[o]);
        }
        printf("Sort failed");
    }
    else
    {
        printf("Sorted: ");
        for (int o = 0; o < c;o++)
        {
            printf("%d ",a[o]);
        }
        printf("\n");
        printf("Time elapsed: %.15f\n",time);
        printf("Successfuly sorted\n");
    }
}
void Insertsort(int a[], int c)
{
    double time = 0.0;
    clock_t begin = clock();
    for (int i = 1;i < c;i++)
    {
        int r = i - 1;
        int acu;
        while(r >= 0)
        {
            if (a[r] < a[i])
            {
                acu = r + 1;
                break;
            }
            r = r - 1;
        }
        int tmp = a[i];
        for (int y = i;y > acu;y--)
        {
            a[y] = a[y-1];
        }
        a[acu] = tmp;
    }
    clock_t end = clock();
    time += (double)(end - begin) / CLOCKS_PER_SEC;
    bool flac = true;
    for (int m = 0;m<c - 1;m++)
    {
        if (a[m + 1] - a[m] < 0)
        {
            flac = false;
            break;
        }
    }
    if (flac == false)
    {
        for (int o = 0; o < c;o++)
        {
            printf("%d ",a[o]);
        }
        printf("Sort failed");
    }
    else
    {
        printf("Sorted: ");
        for (int o = 0; o < c;o++)
        {
            printf("%d ",a[o]);
        }
        printf("\n");
        printf("Time elapsed: %.15f\n",time);
        printf("Successfuly sorted\n");
    }
}

void choicesort(int a[], int c)
{
    double time = 0.0;
    clock_t begin = clock();
    for (int m = 0;m < c - 1; m++)
    {
        int r = m;
        for (int g = m + 1;g < c; g++)
        {
            if (a[g] < a[r])
            {
                r = g;
            }
        }
        if (r != m)
        {
            int tmp = a[r];
            a[r] = a[m];
            a[m] = tmp;
        }
    }
    clock_t end = clock();
    time += (double)(end - begin) / CLOCKS_PER_SEC;
    bool flac = true;
    for (int m = 0;m<c - 1;m++)
    {
        if (a[m + 1] - a[m] < 0)
        {
            flac = false;
            break;
        }
    }
    if (flac == false)
    {
        for (int o = 0; o < c;o++)
        {
            printf("%d ",a[o]);
        }
        printf("Sort failed");
    }
    else
    {
        printf("Sorted: ");
        for (int o = 0; o < c;o++)
        {
            printf("%d ",a[o]);
        }
        printf("\n");
        printf("Time elapsed: %.15f\n",time);
        printf("Successfuly sorted\n");;
    }
}
void Sbc(int a[],int c)
{
    double time = 0.0;
    clock_t begin = clock();
    int *l; int *p;
    int min = __INT32_MAX__;
    int max = - (__INT32_MAX__);
    for (int i = 0;i<c;i++)
    {
        if (max < a[i])
        {
            max = a[i];
        }
        if (min > a[i])
        {
            min = a[i];
        }
    }
    l = (int*)malloc((max - min)*sizeof(int));
    p = (int*)malloc(c*sizeof(int));
    memset(l,0,(max - min)*sizeof(int));
    for (int h = 0;h < c;h++)
    {
        l[a[h] - min] += 1;
    }
    int ts = 0;
    for (int h = 0;h <(max - min);h++)
    {
        if (l[h] == 1)
        {
            p[ts] = h + min;
            ts++;
        }
        if (l[h] > 1)
        {
            for (int u = l[h];u > 0;u--)
            {
                p[ts] = h + min;
                ts++;
                h++;
            }
        }
    }
    clock_t end = clock();
    time += (double)(end - begin) / CLOCKS_PER_SEC;
    bool flac = true;
    for (int m = 0;m<c - 1;m++)
    {
        if (a[m + 1] - a[m] < 0)
        {
            flac = false;
            break;
        }
    }
    if (flac == false)
    {
        for (int o = 0; o < c;o++)
        {
            printf("%d ",p[o]);
        }
        printf("Sort failed");
    }
    else
    {
        printf("Sorted: ");
        for (int o = 0; o < c;o++)
        {
            printf("%d ",p[o]);
        }
        printf("\n");
        printf("Time elapsed: %.15f\n",time);
        printf("Successfuly sorted\n");
    }
}
void ShellSort(int a[],int c)
{
    double time = 0.0;
    clock_t begin = clock();
    for (int i = c / 2;i > 0;i = i / 2)
    {
        for (int k = i;k < c; ++k) 
        {
            for (int j = k - i; (j >= 0) && (a[j] > a[j + i]); j -= i) 
            {
                int tmp = a[j];
                a[j] = a[j + i];
                a[j + i] = tmp;
            }
        }
    }
    clock_t end = clock();
    time += (double)(end - begin) / CLOCKS_PER_SEC;
     bool flac = true;
    for (int m = 0;m<c - 1;m++)
    {
        if (a[m + 1] - a[m] < 0)
        {
            flac = false;
            break;
        }
    }
    if (flac == false)
    {
        for (int o = 0; o < c;o++)
        {
            printf("%d ",a[o]);
        }
        printf("Sort failed");
    }
    else
    {
        printf("Sorted: ");
        for (int o = 0; o < c;o++)
        {
            printf("%d ",a[o]);
        }
        printf("\n");
        printf("Time elapsed: %.15f\n",time);
        printf("Successfuly sorted\n");
    }
}
int main()
{
    int *a; int *g; int c;
    printf("Enter array length:\n");
    scanf("%d", &c);
    printf("\n");
    a = (int*)malloc(c*sizeof(int));
    g = (int*)malloc(c*sizeof(int));
    printf("Filling...\n");
    for (int q = 0;q<c;q++)
    {
        a[q] =rand()%100000;
    }
    memcpy(g,a,c*sizeof(int));
    int your_choice;
    printf("Enter ypur choice:\n1.BubbleSort\n2.Insertion Sort\n3.Choice Sort\n4.Counting Sort\n5.Shell Sort\n");
    scanf("%d",&your_choice);
    printf("\n");
    while (your_choice != 0)
    {
        switch (your_choice)
        {
            case(1):BubbleSort(g,c);break;
            case(2):Insertsort(g,c);break;
            case(3):choicesort(g,c);break;
            case(4):Sbc(g,c);break; // sort by counting
            case(5):ShellSort(g,c);
            default: printf("No sort available on this number");
        }
        printf("\n");
        scanf("%d",&your_choice);
    }
    free(a);
    free(g);
}