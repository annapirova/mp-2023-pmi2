#include <stdio.h>
#include <math.h>
#include <locale.h>
double taylor_sin(double x, int n);
double taylor_arctan(double x, int n);
double factorial(int n);

double taylor_sin(double x, int n) {
    double result = 0.0;
    int i;
    for (i = 0; i < n; i++) {
        int sign = (i % 2 == 0) ? 1 : -1;
        double term = pow(x, 2 * i + 1) / factorial(2 * i + 1);
        result += sign * term;
    }
    return result;
}

double taylor_arctan(double x, int n) {
    double result = 0.0;
    int i;
    for (i = 0; i < n; i++) {
        int sign = (i % 2 == 0) ? 1 : -1;
        double term = pow(x, 2 * i + 1) / (double)(2 * i + 1);
        result += sign * term;
    }
    return result;
}

double factorial(int n) {
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

void single_calculation() {
    int function_choice, n;
    double x, tolerance;

    printf("Выберите функцию:\n");
    printf("1. sin(x)\n");
    printf("2. arctg(x)\n");
    scanf_s("%d", &function_choice);

    printf("Введите значение x: ");
    scanf_s("%lf", &x);

    printf("Введите погрешность: ");
    scanf_s("%lf", &tolerance);

    printf("Введите число элементов ряда (N): ");
    scanf_s("%d", &n);

    double calculated_value, reference_value, difference;
    if (function_choice == 1) {
        reference_value = sin(x);
        calculated_value = taylor_sin(x, n);
    }
    else if (function_choice == 2) {
        reference_value = atan(x);
        calculated_value = taylor_arctan(x, n);
    }

    difference = calculated_value - reference_value;

    printf("Эталонное значение: %lf\n", reference_value);
    printf("Вычисленное значение: %lf\n", calculated_value);
    printf("Разница: %lf\n", difference);
    printf("Количество слагаемых: %d\n", n);
}

void serial_experiment() {
    int function_choice, n_max;
    double x;

    printf("Выберите функцию:\n");
    printf("1. sin(x)\n");
    printf("2. arctg(x)\n");
    scanf_s("%d", &function_choice);

    printf("Введите значение x: ");
    scanf_s("%lf", &x);

    printf("Введите максимальное число экспериментов (NMax): ");
    scanf_s("%d", &n_max);

    double reference_value;
    if (function_choice == 1) {
        reference_value = sin(x);
    }
    else if (function_choice == 2) {
        reference_value = atan(x);
    }

    printf("Эталонное значение: %lf\n", reference_value);
    printf("Таблица результатов:\n");
    printf("Количество слагаемых\tОценка значения\tРазница\n");

    int i;

    // выделение памяти для массива вычисленных значений
    double* calculated_values = malloc(n_max * sizeof(double));
    // проверка успешности выделения памяти
    if (!calculated_values) {
        printf("Ошибка выделения памяти\n");
        return;
    }

    for (i = 1; i <= n_max; i++) {
        double calculated_value;
        if (function_choice == 1) {
            calculated_value = taylor_sin(x, i);
        }
        else if (function_choice == 2) {
            calculated_value = taylor_arctan(x, i);
        }

        double difference = calculated_value - reference_value;

        // заполнение массива вычисленными значениями
        calculated_values[i - 1] = calculated_value;

        printf("%d\t\t\t%lf\t\t%lf\n", i, calculated_values[i - 1], difference);
    }

    // освобождение памяти, занятой массивом
    free(calculated_values);
}

int main() {
    setlocale(LC_ALL, "Rus");
    int mode_choice;

    printf("Выберите режим работы:\n");
    printf("1. Однократный расчет функции в заданной точке\n");
    printf("2. Серийный эксперимент\n");
    scanf_s("%d", &mode_choice);

    if (mode_choice == 1) {
        single_calculation();
    }
    else if (mode_choice == 2) {
        serial_experiment();
    }

    return 0;
}
