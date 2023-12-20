#include <stdio.h>
#include <math.h>
#include <locale.h>

typedef double (*MathFunction)(double, double, int);
double taylor_series(double x, double tohn, int N, MathFunction term_generator);

double taylor_sin_term(double x, double n, double prev_term, double sign);
double taylor_arctan_term(double x, double n, double prev_term, double sign);

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

    MathFunction term_generator;

    if (function_choice == 1) {
        term_generator = taylor_sin_term;
    } else if (function_choice == 2) {
        term_generator = taylor_arctan_term;
    } else {
        printf("Неверный выбор функции.\n");
        return 1;
    }

    double calculated_value = taylor_series(x, tohn, N, term_generator);
    double reference_value = (function_choice == 1) ? sin(x) : atan(x);
    int terms_calculated = N;
    double difference = calculated_value - reference_value;

    printf("Эталонное значение: %.6lf\n", reference_value);
    printf("Вычисленное значение: %.6lf\n", calculated_value);
    printf("Разница: %.6lf\n", difference);
    printf("Количество слагаемых: %d\n", terms_calculated);

    return 0;
}

double taylor_series(double x, double tohn, int N, MathFunction term_generator) {
    double result = x;
    double term = x;
    double n = 1.0;
    double sign = -1.0;

    for (int i = 1; i < N; i++) {
        term = term_generator(x, n, term, sign);
        result += term;
        sign *= -1.0;
        n++;
        if (fabs(term) < tohn) {
            break;
        }
    }

    return result;
}

double taylor_sin_term(double x, double n, double prev_term, double sign) {
    double nom = -x * x * prev_term;
    double d = (2.0 * n) * (2.0 * n + 1.0);
    return sign * nom / d;
}

double taylor_arctan_term(double x, double n, double prev_term, double sign) {
    double nom = -x * x * prev_term;
    double d = (2.0 * n + 1.0);
    return sign * nom / d;
}




