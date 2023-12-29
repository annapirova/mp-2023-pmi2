#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h>



void menu() {
    setlocale(LC_ALL, "ru_RU. UTF-8");
    printf("1 - scan your tovar\n");  
    printf("2 - information o tovari\n");  
    printf("3 - polychit chek\n"); 
    printf("4 - exit:)\n");  
}


void scanirovat(int* chet, int codipr[], int chetchik[]) {
    setlocale(LC_ALL, "ru_RU. UTF-8");
    printf("nomera produktov dostypnie v nashem shope\n 1111\n 2222\n 3333\n 4444\n 5555\n ");
    printf("print your product number here\n");  
    scanf_s("%d", chet);

    int ol, f = 0;
    for (ol = 0; ol < 5; ol++) {
        if (codipr[ol] == *chet) {
            chetchik[ol]++;
            f = 1;
        }
    }

    if (f == 0) {
        printf("takogo produkta ne syshestvyet\n");  
    }
}


void infaoprodukte(int* product, int codipr[], int cenitovara[], double skidki[]) {
    setlocale(LC_ALL, "ru_RU. UTF-8");
    int i;
    if (*product == -1) {
        printf("prodyktov v korzine ne obnaryzheno\n");  
        return;
    }

    
    for (i = 0; i < 5; i++) {
        if (codipr[i] == *product) {
            printf("nomer tovara - %d\n", codipr[i]);  
            printf("price without discount - %d\n", cenitovara[i]);  
            printf("skidka na tovar - %.2lf\n", skidki[i]);  
            printf("cena so skidkoi - %.2lf\n", (double)cenitovara[i] * (1 - skidki[i]));  
        }
    }
}


void chek(int chetchik[], int codipr[],
    double skidki[], int cenitovara[],char names[][20], double* symma) {
    setlocale(LC_ALL, "ru_RU. UTF-8");
    printf("chek:\n");  
    printf("Product code  kol-vo  skidka  price\n");  

    for (int i = 0; i < 5; i++) {
        if (chetchik[i] != 0) {
            
            double final_price = (double)cenitovara[i] * (1 - skidki[i]) * chetchik[i];
            printf("%s  %d  %d  %.2lf  %.2lf\n", names[i], codipr[i], chetchik[i], skidki[i], final_price);
            *symma = *symma +final_price;  
        }
    }

    printf("\nITOGO K oplate %.2lf\n", *symma);
}


double randomskidka(double min, double max) {
    double random = ((double)rand()) / (double)RAND_MAX;
    return min + (random * (max - min));
}

int main() {
    setlocale(LC_ALL, "ru_RU. UTF-8");
    int i, day;
    double max, min;
    int codipr[5] = { 1111, 2222, 3333, 4444, 5555 };
    int cenitovara[5] = { 15000, 23, 132, 210, 5435 };
    double skidki[5];
    int chetchik[5] = { 0 };
    int chet = -1;

    char names[5][20] = {
        "door\0",
        "pencil\0",
        "tomato\0",
        "gel for shower\0",
        "chocolate\0"
    };
    srand(time(NULL)); 
    printf("Hello\n Welcome to the secret shop!\n Po vihodnim y nas skidki\n");
    printf("vvedite please den' nedeli cifroi\n");
    scanf_s("%d", &day);
    if (day == 5 || day == 6 || day == 7)
    {
        printf("success vi popali na rasprodashy\n");
        max = 0.8;
        min = 0.2;
    }
    else
    {
        max = 0.4;
        min = 0;
    }

    for (i = 0; i < 5; i++)
    {
        skidki[i] = randomskidka(min, max);
  }
    
    menu();

    int gh;
    double symma = 0;

    do {
        scanf_s("%d", &gh);
        switch (gh) {
        case 1:
            scanirovat(&chet, codipr, chetchik);
            if (chet != -1) {
                for (int i = 0; i < 5; i++) {
                    if (codipr[i] == chet) {
                        printf("Scanned product: %s\n", names[i]);
                    }
                }
            }
            break;
        case 2:
            infaoprodukte(&chet, codipr, cenitovara, skidki);
            break;
        case 3:
            chek(chetchik, codipr, skidki, cenitovara, names, &symma);
            break;
        case 4:
            printf("spasibo za pokypki!\n Have a nice day!!!\n"); 
            break;
        default:
            printf("takoi comandi ne syshectvyet:(\n");
            break;
        }
    } while (gh != 4);

    return 0;
}
