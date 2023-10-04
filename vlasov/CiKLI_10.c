#include <stdio.h>

int main1()
{
    int n, reverse = 0, temp;

    printf("Vvedite hislo dlya proverki\n");
    scanf_s("%d", &n);

    temp = n;

    while (temp != 0)
    {
        reverse = reverse * 10;
        reverse = reverse + temp % 10;
        temp = temp / 10;
    }

    if (n == reverse)
        printf("%d hislo palindrome .\n", n);
    else
        printf("%d hislo ne palindrome.\n", n);

    return 0;
}