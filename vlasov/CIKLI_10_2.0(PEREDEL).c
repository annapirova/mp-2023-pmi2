#include <stdio.h>

int main()
{
    int a_copy, a, k, b = 0;

    printf("Vvedite chislo dlya proverki\n");
    scanf_s("%d", &a);

    a_copy = a;

    while (a > 0)
    {
        k = a % 10;
        a /= 10;
        b = b * 10 + k;
    }

    if (a_copy == b)
        printf("%d - chislo palindrome.\n", a_copy);
    else
        printf("%d - chislo ne palindrome.\n", a_copy);

    return 0;
}