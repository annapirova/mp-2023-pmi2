#include<stdio.h>
#include<locale.h>

int main()
{
	setlocale(LC_ALL, "Russian");
    int a[10];
	int i, j;
	int k = 0;
    int f = 0;
    printf("Введите массив из 10 элементов\n");
    for (i = 0;i < 10; i++)
    {
        scanf_s("%i", &a[i]);
    }
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (i != j && a[i] == a[j])
            {
                f++;
            }
        }
    }
    if (f != 0)
    {
        printf("В массиве есть повторяющиеся элементы");
    }
    else
    {
        printf("Повторяющихся элементов нет");
    }
}
