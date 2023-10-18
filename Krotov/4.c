#include <stdio.h>

int main4() {
    int n;
    printf("Dlina chisla (от 2 до 5): \n");
    scanf_s("%d", &n);
    if (n < 2 || n > 5) {
        printf("Error.\n");
        return 0;
    }
    int secretNumber[n];
    int guess[n];
    printf("Chislo c %d ciframi ", n);
    for (int i = 0; i < n; i++) 
    {
        scanf_s("%d", &secretNumber[i]);
    }

    int popitka = 0;
    int bulls = 0;
    int cows = 0;

    while (bulls != n) {
        popitka++;

        printf("popitka %d. vvedi chislo s %d ciframi: ", popitka, n);
        for (int i = 0; i < n; i++) {
            scanf_s("%d", &guess[i]);
        }

        bulls = 0;
        cows = 0;
        for (int i = 0; i < n; i++) {
            if (guess[i] == secretNumber[i]) {
                bulls++;
            }
            else {
                for (int j = 0; j < n; j++) {
                    if (guess[i] == secretNumber[j]) {
                        cows++;
                        break;
                    }
                }
            }
        }
        printf("Result: %d bulls , %d cows.\n\n", bulls, cows);
    }

    printf("You win for %d popitok.\n", popitka);

    return 0;
    }