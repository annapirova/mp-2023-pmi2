#include <stdio.h>
#include <math.h>

// Ряд Тейлора для sin(x)
double taylorSin(double x, int N) {
    double result = 0;
    for (int i = 0; i < N; i++) {
        int sign = i % 2 == 0 ? 1 : -1; // Чередующийся знак
        int fact = 1;
        for (int j = 1; j <= 2 * i + 1; j++) {
            fact *= j;  // Вычисление факториала
        }
        result += sign * pow(x, 2 * i + 1) / fact;
    }
    return result;
}

int main() {
    double x, precision;
    int N;
    printf("Enter the value of x: ");
    scanf_s("%lf", &x);
    printf("Enter the precision: ");
    scanf_s("%lf", &precision);
    printf("Enter the number of terms in the series (N): ");
    scanf_s("%d", &N);

    double sinValue = sin(x);
    double taylorValue;
    int termsComputed;

    for (int i = 1; i <= N; i++) {
        taylorValue = taylorSin(x, i);
        termsComputed = i;
        if (fabs(taylorValue - sinValue) < precision) {
            break;
        }
    }

    printf("Actual value: %lf\n", sinValue);
    printf("Approximated value: %lf\n", taylorValue);
    printf("Difference: %lf\n", fabs(sinValue - taylorValue));
    printf("Number of terms used:%d\n", termsComputed);

    return 0;
}
