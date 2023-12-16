#include <stdio.h>
#include <locale.h>
int main()
{
    setlocale(LC_ALL, "Russian");
    int answer;
    int numb;
    char s;
    printf("Введите число от 1 до 1000: ");
    scanf_s("%i", &numb);
    int r, l;
    r = 1000;
    l = 1;
    int k = 0;
    while (1)
    {
        int answer = (l+r)/2;
        printf("Загаданное число %i ?\n", answer);
        printf("Ваше число больше, меньше или равно? (введите <,>,=)\n");
        scanf_s(" %c", &s);
        if (s == '>') 
        {
            l = answer;
            k++;
        }
        else if (s == '<') 
        {
            r = answer;
            k++;
        }
        else if (s == '=') 
        { 
            printf("Угадал\n");
            printf("Количество попыток: ");
            printf("%i", k);
            break;
        }
    }
    return 0;
}
