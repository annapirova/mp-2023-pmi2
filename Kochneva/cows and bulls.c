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

    for (int i = 0; i < n; i++) {
        while (1) {
            int digit = rand() % 10;
            if (!digits[digit]) {
                digits[digit] = 1;
                number[i] = '0' + digit;
                break;
            }
        }
    }
    number[n] = '\0';
    printf("I got a number, try to guess it.\n");

    while (1) {
        printf("Enter your guess: ");
        scanf_s("%5s", guess, sizeof(guess));

        int cows = 0;
        int bulls = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
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
            break;
        }
    }

    return 0;
}
