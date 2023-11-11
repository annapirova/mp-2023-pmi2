#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));

    int numberLength;
    printf("Enter the length of the secret number (2 to 5): ");
    scanf_s("%d", &numberLength);

    if (numberLength < 2 || numberLength > 5) {
        printf("Please enter a valid number length (2 to 5).\n");
        return 1;
    }

    int secretNumber[5];
    for (int i = 0; i < numberLength; i++) {
        int digit;
        int isUnique = 0;
        do {
            digit = rand() % 10;
            isUnique = 1;
            for (int j = 0; j < i; j++) {
                if (secretNumber[j] == digit) {
                    isUnique = 0;
                    break;
                }
            }
            if (isUnique) {
                secretNumber[i] = digit;
            }
        } while (!isUnique);
    }

    printf("Try to guess a %d-digit number (digits are not repeated).\n", numberLength);

    int attempts = 0;
    int gameFinished = 0;

    while (!gameFinished) {
        int guess[5];
        printf("Enter your guess: ");

        int validInput = 1;
        for (int i = 0; i < numberLength; i++) {
            if (scanf_s("%1d", &guess[i]) != 1) {
                printf("Please enter %d digits.\n", numberLength);
                validInput = 0;
            }
        }

        if (!validInput) {
            while (getchar() != '\n');
            continue;
        }

        int bulls = 0, cows = 0;
        for (int i = 0; i < numberLength; i++) {
            if (guess[i] == secretNumber[i]) {
                bulls++;
            }
            else {
                for (int j = 0; j < numberLength; j++) {
                    if (guess[i] == secretNumber[j]) {
                        cows++;
                        break;
                    }
                }
            }
        }

        printf("bulls: %d, cows: %d\n", bulls, cows);

        attempts++;
        if (bulls == numberLength) {
            printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
            gameFinished = 1;
        }
    }

    return 0;
}
