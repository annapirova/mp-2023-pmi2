#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h> 
#include <stdbool.h>
#include <memory.h>
typedef double(*nextT)(double, int);
typedef double(*firstT)(double);
double convertToInterval(double x) {
    const double PI = 3.1415;
    while ((x < 0) || (x > 2 * PI))
    {
        if (x < 0)
        {
            x += 2 * PI;
        }
        if (x > 2 * PI)
        {
            x -= 2 * PI;
        }
    }
    return x;
}
double FirstSin(double x)
{
    return (x);
}
double NextSin(double x, int n)
{
    return (-x * x / (2 * n) / (2 * n + 1));
}
double FirstSh(double x)
{
    return (x);
}
double NextSh(double x, int n)
{
    return (x * x / (2 * n) / (2 * n + 1));
}
double Teylor(double x, firstT first, nextT f, double acc, double corr, int N_MAX)
{
    double sum, prev, next,diff;
    int kol=1;
    sum = first(x);
    prev = sum;
    diff = fabs(sum - corr);
    while ((diff > acc) && (kol < N_MAX))
    {
        next = prev * f(x, kol);
        sum += next;
        prev = next;
        diff = fabs(sum - corr);
        kol++;
    }
    return sum;
}
int main()
{
    setlocale(LC_CTYPE, "Russian");
    int choice;
    double acc,y,yy,z,x;
    int N_MAX;
    bool run = true;
    printf("Привет, я рассчитаю тебе синус и гиперболический синус по формуле Тейлора!\n");
    printf("Задай точку, в которой необходимо вычислить значение:\n");
    scanf_s("%lf", &z);
    x = convertToInterval(z);
    printf("Данная точка от 0 до 2 пи: %lf\n",x);
    printf("Задай точность вычисления:\n");
    scanf_s("%lf", &acc);
    printf("Задай число элементов ряда для выполнения расчёта:\n");
    scanf_s("%d", &N_MAX);
    printf("Что будем считать?");
    printf("Введи 1 - если sin(), введи 2 - если sh(), введи 0 - для выхода\n");
    while (run)
    {
        scanf_s("%d", &choice);
        switch (choice)
        {
        case 1:
        {   y = Teylor(x, FirstSin, NextSin, acc, sin(x), N_MAX);
        printf("По ряду Тейлора sin(x) = %lf\n", y);
        printf("Корректное значение sin(x) = %lf\n", sin(x));
        printf("Разница: %lf\n", fabs(y - sin(x)));
            break;
        }
        case 2:
        {
            yy = Teylor(x, FirstSh, NextSh, acc, sinh(x), N_MAX);
        printf("По ряду Тейлора sh(x) = %lf\n", yy);
        printf("Корректное значение sh(x) = %lf\n", sinh(x));
        printf("Разница: %lf\n", fabs(yy - sinh(x)));
            break;
        }
        case 0:
        {   run = false;
            break;
        }
        default: printf("Нет такой команды :(\n");
        }
    }
    return 0;
}