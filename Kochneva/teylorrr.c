#include <stdio.h>
#include <math.h>

// Функция для вычисления арккотангенса по ряду Тейлора
double arcctg(double x, int n) {
    double result = 0;
    int sign = 1;
    for (int i = 0; i < n; i++) {
        double term = sign * pow(x, 2 * i + 1) / (2 * i + 1);
        result += term;
        sign = -sign;
    }
    return result;
}

int main() {
    double x, precision;
    int n;

    // Запрос пользовательского ввода
    printf("Enter the value for x: ");
    scanf_s("%lf", &x);
    printf("Enter the precision for calculation: ");
    scanf_s("%lf", &precision);
    printf("Enter the number of terms for calculation (N): ");
    scanf_s("%d", &n);

    // Вычисление оценки значения функции арккотангенса
    double approx_result = arcctg(x, n);

    // Получение эталонного значения с использованием встроенной функции языка C
    double actual_result = atan(1 / x);

    // Вывод результатов
    printf("Actual value: %lf\n", actual_result);
    printf("Approximated value: %lf\n", approx_result);
    printf("Difference: %lf\n", fabs(actual_result - approx_result));
    printf("Number of terms used: %d\n", n);

    return 0;
}

