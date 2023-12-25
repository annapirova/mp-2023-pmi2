#include <stdio.h>
#include <locale.h>
int main()
{
    setlocale(LC_ALL, "Russian");
    int answer;
    int numb;
    char s;
    printf("Vvedite chislo ot 1 do 1000: ");
    scanf_s("%i", &numb);
    int r, l;
    r = 1000;
    l = 1;
    int k = 0;
    do
    {
        int answer = (l+r)/2;
        printf("Zagadannoe chislo %i ?\n", answer);
        printf("Vashe chislo bolshe, menshe ili ravno? (введите <,>,=)\n");
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
            printf("Ugadal\n");
            printf("Popitok: ");
            printf("%i", k);
            break;
        }
    } while (s != '=');
    return 0;
}