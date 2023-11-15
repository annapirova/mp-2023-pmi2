#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main()
{
    setlocale(LC_ALL, "Rus");
    int low = 1, high = 1000;
    int attempts = 0;
    int successfulRead;

    printf("Зайгадайте число от 1 до 1000.\n");

    while (1)
    {
        int guess = (low + high) / 2;
        attempts++;

        printf("Ваше число: %d\n", guess);
        printf("Введите '<' если число меньше, '>' если больше, или '=' если угадано: ");

        char response;
        successfulRead = scanf_s(" %c", &response, 1);

        if (successfulRead != 1)
        {
             break;
        }

        if (response == '<')
            high = guess - 1;
        else if (response == '>')
            low = guess + 1;
        else if (response == '=')
        {
            printf("Игра пройдена!\n");
            break;
        }
    }

    printf("Количество попыток: %d\n", attempts);
    return 0;
}