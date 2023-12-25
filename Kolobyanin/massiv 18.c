#include <stdio.h>
#include<locale.h>

int main()
{
    setlocale(LC_ALL, "Russian");
    int a[10];
    int i;
    int m = 999999;
    printf("Vvedite massiv iz 10 elementov\n");
    for (i = 0;i < 10; i++)
    {
        scanf_s("%i", &a[i]);
    }
    for (i = 1;i < 9;i++)
    {
        if (a[i] < a[i - 1] && a[i] < a[i + 1])
        {
            if (a[i] < m)
            {
                m = a[i];
            }
        }
    }
    printf("%i", m);
}
    