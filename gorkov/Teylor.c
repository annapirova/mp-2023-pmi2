#include "stdio.h"
#include "math.h"
#include "stdbool.h"
#define PI 3.141592

double FirstSin(double x)
{

    return (x);
}

double NextSin(double x, int n)
{

    return (-x * x / (2 * n) / (2 * n + 1));
}

typedef double(*FirstT)(double);
typedef double(*NextT)(double, int);

double CtgFirst(double x)
{
    return (x);
}

double CtgNext(double x, int n)
{
    return ((-x * x / (2 * n - 1) / (2 * n))/ (-x * x / (2 * n) / (2 * n + 1)));
}

double Teylor(double x, FirstT first, NextT next, double acc, double corr, int N_MAX)
{
    double sum, sl, r, last;
    int k = 1;
    sum = first(x);
    last = sum;

    r = fabs(sum - corr);
    while ((r > acc) && (k < N_MAX))
    {
        sl = last * next(x, k);
        sum += sl;
        last = sl;
        r = fabs(sum - corr);
        k++;
    }
    return sum;
}

double CorrInt(double a) 
{
    while ((a>2*PI)||(a < 0))
    {
        if (a > 2 * PI)
        {
            a -= 2 * PI;
        }
        if (a < 0)
        {
            a += 2 * PI;
        }
    }
    return a;
}


int main()
{
    double a, b, acc, t, l;
    int N_MAX;
    printf("Enter number\n");
    scanf_s("%lf", &t);
    l= CorrInt(t);
    printf("%lf\n", l);
    printf("Enter accur\n");
    scanf_s("%lf", &acc);

    printf("Enter count of numbers\n");
    scanf_s("%d", &N_MAX);
    printf("0-end 1-sin 2-ctg");
    int choise;
    bool run = true;
    while (run)
    {
        scanf_s("%d", &choise);
        switch (choise)
        {
        case 1:
         a = Teylor(l, FirstSin, NextSin, acc, sin(l), N_MAX);

        printf("Sin Tey = %lf\n", a);
        printf("Corr sin = %lf\n", sin(l));
        printf("diff- %lf\n", fabs(a - sin(l)));
        break;
        case 2:
            b = Teylor(l, CtgFirst, CtgNext, acc, 1/tan(l), N_MAX);
            printf("Ctg Tey= %lf\n", b);

            printf("Corr ctg= %lf\n", 1/tan(l));
            printf("diff- %lf\n", fabs(b - 1/tan(l)));
            break;
        case 0:
            run = false;
            break;

        default: 
            printf("wrong operation");
            break;
        }
    }
    return 0;
}