#include <stdio.h>
#include <locale.h>
int main()
{
    setlocale(LC_ALL, "Russian");
    int a[5], i, j, k, flag = 0, duplicates_found = 0;

    for (i = 0; i < 5; i++)
    {
        scanf_s("%d", &a[i]);
    }

    for (i = 0; i < 5; i++)
    {
        flag = 0;
        for (j = i + 1; j < 5; j++)
        {
            if (a[i] == a[j])
            {
                flag = 1;
            }
        }
        if (flag == 1)
        {
            for (k = 0; k < i; k++)
            {
                if (a[i] == a[k])
                    flag = 0;
            }
            if (flag == 1)
            {
                printf("Обнаружены одинаковые элементы. Повторяющееся значение: %d\n", a[i]);
                duplicates_found = 1;
            }
        }
    }
    if (duplicates_found == 0)
        printf("Одинаковых элементов не обнаружено");

    return 0;
}
