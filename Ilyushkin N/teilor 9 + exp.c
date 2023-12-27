#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846
double arctg(double x) {
    return PI / 2 - atan(x);
}

double ex(double x) {
    return exp(x);
}

double arctgteilor(double x, double epsilon, int N) {
    double sum = 0.0;
    double a = x;
    int i = 1;

    while (fabs(a) > epsilon && i <= N) {
        sum += a;
        a = -a * x * x * (2 * i - 1) / (2 * i + 1);
        i++;
    }

    return sum;
}

double e_teilor(double x, double epsilon, int N) {
    double sum = 0.0;
    double a = 1.0;
    int i = 1;

    while (fabs(a) > epsilon && i <= N) {
        sum += a;
        a = a * x / i;
        i++;
    }

    return sum;
}

int main() {
    int choice;
    double x, epsilon;
    int N;

    printf("choose your function:\n");
    printf("1. arcctg(x)\n");
    printf("2. e^x\n");
    scanf_s("%d", &choice);

    printf("write ur x: ");
    scanf_s("%lf", &x);

    printf("write tochnost vichisl: ");
    scanf_s("%lf", &epsilon);

    printf("vvedite chislo el-tov ryada N: ");
    scanf_s("%d", &N);

    switch (choice) {
    case 1: {
        double truee = arctg(x);
        double vich = arctgteilor(x, epsilon, N);
        double difference = fabs(truee - vich);

        printf("Etalonnoe znachenie: %lf\n", truee);
        printf("Vichislennoe: %lf\n", vich);
        printf("Raznitsa: %lf\n", difference);
        printf("Kol-vo slagaemih: %d\n", N);
        break;
    }
    case 2: {
        double truee = ex(x);
        double vich = e_teilor(x, epsilon, N);
        double difference = fabs(truee - vich);

        printf("Etalonnoe znachenie: %lf\n", truee);
        printf("Vichislinnoe: %lf\n", vich);
        printf("Raznitsa: %lf\n", difference);
        printf("Kol-vo slagaemih: %d\n", N);
        break;
    }
    default:
        printf("error!\n");
        break;
    }

    return 0;
}