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

    printf("�������� �������:\n");
    printf("1. sin(x)\n");
    printf("2. arctg(x)\n");
    scanf_s("%d", &function_choice);

    printf("������� �������� x: ");
    scanf_s("%lf", &x);

    printf("������� �����������: ");
    scanf_s("%lf", &tolerance);

    printf("������� ����� ��������� ���� (N): ");
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

    printf("��������� ��������: %lf\n", reference_value);
    printf("����������� ��������: %lf\n", calculated_value);
    printf("�������: %lf\n", difference);
    printf("���������� ���������: %d\n", n);
}

void serial_experiment() {
    int function_choice, n_max;
    double x;

    printf("�������� �������:\n");
    printf("1. sin(x)\n");
    printf("2. arctg(x)\n");
    scanf_s("%d", &function_choice);

    printf("������� �������� x: ");
    scanf_s("%lf", &x);

    printf("������� ������������ ����� ������������� (NMax): ");
    scanf_s("%d", &n_max);

    double reference_value;
    if (function_choice == 1) {
        reference_value = sin(x);
    }
    else if (function_choice == 2) {
        reference_value = atan(x);
    }

    printf("��������� ��������: %lf\n", reference_value);
    printf("������� �����������:\n");
    printf("���������� ���������\t������ ��������\t�������\n");

    int i;

    // ��������� ������ ��� ������� ����������� ��������
    double* calculated_values = malloc(n_max * sizeof(double));
    // �������� ���������� ��������� ������
    if (!calculated_values) {
        printf("������ ��������� ������\n");
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

        // ���������� ������� ������������ ����������
        calculated_values[i - 1] = calculated_value;

        printf("%d\t\t\t%lf\t\t%lf\n", i, calculated_values[i - 1], difference);
    }

    // ������������ ������, ������� ��������
    free(calculated_values);
}

int main() {
    setlocale(LC_ALL, "Rus");
    int mode_choice;

    printf("�������� ����� ������:\n");
    printf("1. ����������� ������ ������� � �������� �����\n");
    printf("2. �������� �����������\n");
    scanf_s("%d", &mode_choice);

    if (mode_choice == 1) {
        single_calculation();
    }
    else if (mode_choice == 2) {
        serial_experiment();
    }

    return 0;
}
