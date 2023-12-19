#include <stdio.h>
#include <math.h>

// Функция для вычисления гиперболического тангенса по ряду Тейлора
double hyperbolic_tan(double x, int n) {
    double result = 0;
    for (int i = 1; i <= n; i++) {
        double term = 1.0;
        for (int j = 0; j < 2 * i; j++) {
            term *= x / (2.0 * i);
        }
        result += term;
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

    // Вычисление оценки значения функции гиперболического тангенса
    double approx_result = hyperbolic_tan(x, n);

    // Получение эталонного значения с использованием встроенной функции языка C
    double actual_result = tanh(x);

    // Вывод результатов
    printf("Actual value: %lf\n", actual_result);
    printf("Approximated value: %lf\n", approx_result);
    printf("Difference: %lf\n", fabs(actual_result - approx_result));
    printf("Number of terms used: %d\n", n);

    return 0;
}
