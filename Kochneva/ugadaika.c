#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Rus");
    system("chcp 1251");
    srand(time(NULL));

    int wish_n = rand() % 1000 + 1;
    int think_n;
    int i = 0;

    printf("Привет! Котёнок, попробуй угадать число от 1 до 1000:\n");

    do {
        scanf_s("%d", &think_n);
        i++;

        if (think_n > wish_n) {
            printf("Загаданное число меньше\n");
        }
        else if (think_n < wish_n) {
            printf("Загаданное число больше\n");
        }
        else {
            printf("Ты угадал! Умница! :3\n");
        }
    } while (think_n != wish_n);

    printf("Число твоих попыток: %d\n", i);

    return 0;
}