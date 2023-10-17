#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Rus");

    int num, c1, min1, max1, min2, max2, c_num, c, temp;
    scanf_s("%d", &num);
    c_num = num;
    c = 0;
    while (c_num > 0)
    {
        c_num = c_num / 10;
        c++;
    }
    min1 = 9;
    max1 = 0;
    c1 = 0;
    while (num > 0)
    {
        temp = num % 10;
        c1++;
        if (temp <= min1)
        {
            min1 = temp;
            min2 = c1;
        }
        if (temp >= max1)
        {
            max1 = temp;
            max2 = c1;
        }
        num /= 10;
    }
    printf("Максимальная цифра = % d, порядковый номер справа = % d, слева = % d\n", max1, max2, c - max2 + 1);
    printf("Минимальная цифра = %d, порядковый номер справа = %d, слева = %d\n", min1, min2, c - min2 + 1);
    return 0;
}
