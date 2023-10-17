#include <stdio.h>
#include <math.h>
#include <locale.h>
int main()
{
    setlocale(LC_ALL, "Rus");
    int n, i;
    double min_diff = 1.0, current_diff, a;
    double nearest_a = 0;

    printf("Введите натуральное число: ");
    scanf_s("%d", &n);

    for (i = 1; i <= n; i++)
    {
        a = i * sin(1.0 / i);
        current_diff = fabs(round(a) - a);
        if (current_diff < min_diff)
        {
            min_diff = current_diff;
            nearest_a = a;
        }
    }

    printf("Ближайшее значение: %.6f\n", nearest_a);

    return 0;
}
