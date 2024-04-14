#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h> 
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

typedef  struct
{
    char name[15];
    int code;
    float price;
    int disc;
}Product;

int main()
{
    setlocale(LC_CTYPE, "Russian");
    char input[100];
    Product* P;
    int k = 10;
    int kol = 0;
    P = (Product*)malloc(sizeof(Product) * k);
    FILE* file = fopen("products.txt", "r");

    printf("Выполнятся чтение из файла\n ");
    if (file != NULL) {
        while (!feof(file)) {
            fgets(input, 50, file);
            if (input[0] == '\n') {
                printf("Чтение закончено\n");
                exit;
            }
            printf("Считано: %s\n", input);
            kol++;
            char* s = strtok(input, " ");
            while (s != NULL)
            {

                if (strstr(s, "%") != NULL)
                    P[kol - 1].disc = atoi(s);
                else if ((strlen(s) == 4) && (isdigit(s[0]) != 0))
                    P[kol - 1].code = atoi(s);
                else if (strchr(s, '.') != NULL)
                    P[kol - 1].price = atof(s);
                else if ((isdigit(s[0])) == 0)
                    strcpy(P[kol - 1].name, s);
                s = strtok(NULL, " ");
            }
        }
    }
    fclose(file);
    FILE* f = fopen("products.txt", "a");
    fprintf(f,"\nResults:\n");
    for (int i = 0; i < kol-1; i++) {
        fprintf(f, "%s ""%.2f ""%d ""%d%% \n", P[i].name, P[i].price, P[i].code, P[i].disc);
    }
    fclose(f);
    bool run = true;
    int choice;
    printf("Введите запрос: \n");
    printf("1 - товары со скидкой более 50%\n");
    printf("2 - товары дороже 100 рублей\n");
    printf("0 - выход\n");
    while (run)
    {
        scanf_s("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            printf("Товары со скидкой более 50% :\n");
            for (int n = 0; n < kol; n++)
            {
                if (P[n].disc > 50)
                    printf(" %s"" %d%%\n", P[n].name, P[n].disc);
            }
            break;
        }
        case 2:
        {
            printf("Товары дороже 100 рублей :\n");
            for (int n = 0; n < kol; n++)
            {
                if (P[n].price > 50)
                    printf(" %s"" %.2f\n", P[n].name, P[n].price);
            }
            break;
        }
        case 0:
        {
            printf("До встречи)\n");
            run = false;
            break;
        }
        default:
        {
            printf("Солнце, нет такой команды :(\n");
            printf("Попробуй другую!\n");
            break;
        }
        }
    }
    free(P);
   
    return 0;
}