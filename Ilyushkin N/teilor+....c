<<<<<<< HEAD
#include <stdio.h>
#include <math.h>

double prvarctg(double x)
{
    return x;
}

double sledarctg(double x, int N)
{
    return (-1 * pow(x, 2 * N + 1) / (2 * N + 1));
}

double prvexp(double x)
{
    return 1;
}

double sledexp(double x, int N)
{
    return (x / N);
}

double calculate_arctg(double x, double accuracy, int N)
{
    double elem = prvarctg(x);
    double sum = elem;
    double current = fabs(elem);

    while (current > accuracy && N > 0)
    {
        elem = elem * sledarctg(x, N);
        sum += elem;
        current = fabs(elem);
        N--;
    }

    return sum;
}

double calculate_exp(double x, double accuracy, int N)
{
    double elem = prvexp(x);
    double sum = elem;
    double current = fabs(elem);

    while (current > accuracy && N > 0)
    {
        elem = elem * sledexp(x, N);
        sum += elem;
        current = fabs(elem);
        N--;
    }

    return sum;
}

int main()
{
    double x, accuracy;
    int N, choice;

    printf("Enter x: ");
    scanf("%lf", &x);

    printf("Enter calculation accuracy: ");
    scanf("%lf", &accuracy);

    printf("Enter N: ");
    scanf("%d", &N);

    printf("Choose a function:\n");
    printf("1. arctg(x)\n");
    printf("2. e^x\n");
    scanf("%d", &choice);

    double result;

    switch (choice)
    {
    case 1:
        result = calculate_arctg(x, accuracy, N);
        printf("arctg(%lf) = %.10lf\n", x, result);
        printf("Difference from fundamental value: %.10lf\n", atan(x) - result);
        break;
    case 2:
        result = calculate_exp(x, accuracy, N);
        printf("e^(%lf) = %.10lf\n", x, result);
        printf("Difference from fundamental value: %.10lf\n", exp(x) - result);
        break;
    default:
        printf("Invalid choice!\n");
        break;
    }

    return 0;
=======
#include <stdio.h>
#include <math.h>

double prvarctg(double x)
{
    return x;
}

double sledarctg(double x, int N)
{
    return (-1 * pow(x, 2 * N + 1) / (2 * N + 1));
}

double prvexp(double x)
{
    return 1;
}

double sledexp(double x, int N)
{
    return (x / N);
}

double calculate_arctg(double x, double accuracy, int N)
{
    double elem = prvarctg(x);
    double sum = elem;
    double current = fabs(elem);

    while (current > accuracy && N > 0)
    {
        elem = elem * sledarctg(x, N);
        sum += elem;
        current = fabs(elem);
        N--;
    }

    return sum;
}

double calculate_exp(double x, double accuracy, int N)
{
    double elem = prvexp(x);
    double sum = elem;
    double current = fabs(elem);

    while (current > accuracy && N > 0)
    {
        elem = elem * sledexp(x, N);
        sum += elem;
        current = fabs(elem);
        N--;
    }

    return sum;
}

int main()
{
    double x, accuracy;
    int N, choice;

    printf("Enter x: ");
    scanf("%lf", &x);

    printf("Enter calculation accuracy: ");
    scanf("%lf", &accuracy);

    printf("Enter N: ");
    scanf("%d", &N);

    printf("Choose a function:\n");
    printf("1. arctg(x)\n");
    printf("2. e^x\n");
    scanf("%d", &choice);

    double result;

    switch (choice)
    {
    case 1:
        result = calculate_arctg(x, accuracy, N);
        printf("arctg(%lf) = %.10lf\n", x, result);
        printf("Difference from fundamental value: %.10lf\n", atan(x) - result);
        break;
    case 2:
        result = calculate_exp(x, accuracy, N);
        printf("e^(%lf) = %.10lf\n", x, result);
        printf("Difference from fundamental value: %.10lf\n", exp(x) - result);
        break;
    default:
        printf("Invalid choice!\n");
        break;
    }

    return 0;
>>>>>>> 12a20275fd310e33fd88048f2857584b8b54a5d0
}