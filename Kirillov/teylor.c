#include <stdio.h>
#include <locale.h>
double sin_rec(double x, int i, double* sum) {
    if (i == 0) {
        *sum = x;
        return x;
    }
    else {
        double qi = (-x * x) / ((2 * i) * (2 * i + 1));
        double ai = (sin_rec(x, i - 1, sum) * qi);
        *sum += ai;
        return ai;
    }
}

double exp_rec(double x, int i, double* sum) {
    if (i == 0) {
        *sum = 1;
        return 1;
    }
    else {
        double ai = (exp_rec(x, i - 1, sum) * (x / i));
        *sum += ai;
        return ai;
    }
}

int main() {
    int n;
    double x;
    printf("Print x : ");
    scanf_s("%lf", &x);
    double sin_sum, cos_sum, exp_sum;
    printf("Print n : ");
    scanf_s("%d", &n);

    sin_rec(x, n, &sin_sum);
    printf("sin(%f) = %f\n", x, sin_sum);

    exp_rec(x, n, &exp_sum);
    printf("exp(%f) = %f\n", x, exp_sum);

    return 0;
}
