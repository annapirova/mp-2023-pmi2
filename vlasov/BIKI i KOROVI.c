#include <stdio.h>


int main() {
    int N = 4132; 
    int dogadka;
    int bulls = 0;
    int cows = 0; 

    printf("Igra 'biki i korovi'\n");
    printf("Komputer zagadal 4-xznahnoe hislo .\n");

    while (bulls != 4) {
        printf("vvedite vahu popitky (4-xznahnoe hislo): ");
        scanf_s("%d", &dogadka);

        if (dogadka < 1000 || dogadka > 9999) {
            printf("nekkorektni vvod. poprobuite eshe raz.\n");
            continue;
        }

        int secret_cifra[4] = { N / 1000 % 10, N / 100 % 10,
                            N / 10 % 10, N % 10 };
        int vvedennay_cifra[4] = { dogadka / 1000 % 10, dogadka / 100 % 10,
                             dogadka / 10 % 10, dogadka % 10 };

        bulls = 0;
        cows = 0;

        for (int i = 0; i < 4; i++) {
            if (vvedennay_cifra[i] == secret_cifra[i]) {
                bulls++;
            }
            else {
                for (int j = 0; j < 4; j++) {
                    if (vvedennay_cifra[i] == secret_cifra[j]) {
                        cows++;
                    }
                }
            }
        }

        printf("%d korovi, %d ,bika\n", cows, bulls);
    }

    printf("pozdravlyau! vi ygadali chislo %d!\n", N);
    return 0;
}