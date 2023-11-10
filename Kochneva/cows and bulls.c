#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int n;
    printf("Enter a number from 2 to 5: ");
    scanf_s("%d", &n, sizeof(n));
    char number[6];
    char guess[6];
    int digits[10] = { 0 };
    int digit, i, j;

    for (i = 0; i < n; i++) {
        for (digit = rand() % 10; digits[digit]; digit = rand() % 10);
        digits[digit] = 1;
        number[i] = '0' + digit;
    }
    number[n] = '\0';
    printf("I got a number, try to guess it.\n");

    int bulls = 0;
    for (; bulls != n;) {
        printf("Enter your guess: ");
        scanf_s("%5s", guess, sizeof(guess));

        int cows = 0;
        bulls = 0;

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (number[i] == guess[j]) {
                    if (i == j) {
                        bulls++;
                    }
                    else {
                        cows++;
                    }
                }
            }
        }

        printf("Cows: %d, Bulls: %d\n", cows, bulls);

        if (bulls == n) {
            printf("You guessed it! The number was %s\n", number);
        }
    }

    return 0;
}
