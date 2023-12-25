#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h> 
#include <stdbool.h>
#include <memory.h>

double FirstSin(double x)
{
    return (x);
}

double NextSin(double x, int n)
{
    return (-x * x / (2 * n) / (2 * n + 1));
}

double Firstarcsin(double x)
{
    return (x);
}

double Nextarcsin(double x, int n)
{
    return (x * x * (2 * n - 1) / (2 * n) / (2 * n + 1) * (2 * (n - 1) + 1));
}

double promezhutok(double x)
{
    const double PI = 3.1415;
    int k = x / (2 * PI);
    return x - k * 2 * PI;
}

typedef double(*nextT)(double, int);
typedef double(*firstT)(double);

double Teylor(double x, firstT first, nextT f, double a, double b, int N_MAX)
{
    double sum, aa, bb, cc;
    int n = 1;
    sum = first(x);
    a = sum;
    cc = fabs(sum - b);
    while ((cc > a) && (n < N_MAX))
    {
        b = a * f(x, n);
        sum += b;
        a = b;
        cc = fabs(sum - b);
        n++;
    }
    return sum;
}

int main()
{
    int k;
    double a, y, y2, b, x;
    int N_MAX;
    printf("V kakoy tochke vicislit:\n");
    scanf_s("%lf", &b);
    x = promezhutok(b);
    printf("S kakoy tocnostu:\n");
    scanf_s("%lf", &a);
    printf("Kolichestvo elementov:\n");
    scanf_s("%d", &N_MAX);
    printf("1) sin() \n2) arcsin()\n");
    do
    {
        scanf_s("%d", &k);
        switch (k)
        {
        case 1:
        {   y = Teylor(x, FirstSin, NextSin, a, sin(x), N_MAX);
        printf("Teylor sin(x) = %lf\n", y);
        printf("Correctnoe znachenie sin(x) = %lf\n", sin(x));
        printf("Pogreshnost: %lf\n", fabs(y - sin(x)));
        break;
        }
        case 2:
        {
            y2 = Teylor(x, Firstarcsin, Nextarcsin, a, asin(x), N_MAX);
            printf("Teylor arcsin(x) = %lf\n", y2);
            printf("Correctnoe znachenie arcsin(x) = %lf\n", asin(x));
            printf("Pogreshnost: %lf\n", fabs(y2 - asin(x)));
            break;
        }
        default: printf("ERROR\n");
        }
    } while (k != 3);
    return 0;
}