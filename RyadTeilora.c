#include <stdio.h>
#include <math.h>
#include <locale.h>
typedef double (*MathFunction)(double, double, int);

double taylor_sin(double x, double tohn, int N);
double taylor_arctan(double x, double tohn, int N);
double next_term(double x, double n, double prev_term, double sign);

int main() {
    setlocale(LC_ALL, "Rus");
    double x, tohn;
    int function_choice, N;

    printf("Выберите функцию:\n");
    printf("1. sin(x)\n");
    printf("2. arctan(x)\n");
    scanf_s("%d", &function_choice);

    printf("Введите значение x: ");
    scanf_s("%lf", &x);

    printf("Введите точность (от 0.000001 и больше): ");
    scanf_s("%lf", &tohn);

    while (tohn < 0.000001) {
        printf("Точность должна быть от 0.000001 и больше. Повторите ввод: ");
        scanf_s("%lf", &tohn);
    }

    printf("Введите число элементов ряда (N - от 1 до 1000): ");
    scanf_s("%d", &N);

    while (N < 1 || N > 1000) {
        printf("Число элементов ряда должно быть от 1 до 1000. Повторите ввод: ");
        scanf_s("%d", &N);
    }

    MathFunction function;

    if (function_choice == 1) {
        function = taylor_sin;
    }
    else if (function_choice == 2) {
        function = taylor_arctan;
    }
    else {
        printf("Неверный выбор функции.\n");
        return 1;
    }

    double calculated_value = function(x, tohn, N);
    double reference_value = (function_choice == 1) ? sin(x) : atan(x);
    int terms_calculated = N;
    double difference = calculated_value - reference_value;

    printf("Эталонное значение: %.6lf\n", reference_value);
    printf("Вычисленное значение: %.6lf\n", calculated_value);
    printf("Разница: %.6lf\n", difference);
    printf("Количество слагаемых: %d\n", terms_calculated);

    return 0;
}

double taylor_sin(double x, double tohn, int N) {
    double result = x;
    double term = x;
    double n = 1.0;
    double sign = -1.0;

    for (int i = 1; i < N; i++) {
        term = next_term(x, n, term, sign);
        result += term;
        sign *= -1.0;
        n++;
        if (fabs(term) < tohn) {
            break;
        }
    }

    return result;
}

double taylor_arctan(double x, double tohn, int N) {
    double result = x;
    double term = x;
    double n = 1.0;
    double sign = -1.0;

    for (int i = 1; i < N; i++) {
        term = next_term(x, n, term, sign);
        result += term;
        sign *= -1.0;
        n++;
        if (fabs(term) < tohn) {
            break;
        }
    }

    return result;
}

double next_term(double x, double n, double prev_term, double sign) {
    double nom = -x * x * prev_term;
    double d = (2.0 * n) * (2.0 * n + 1.0);
    return sign * nom / d;
}




