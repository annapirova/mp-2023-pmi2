#include <stdio.h>
#include <stdbool.h>






bool isPrime(int number) {
    if (number <= 1) {
        return false;
    }
    for (int k = 2; k * k <= number; k++) {
        if (number % k == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int N;
    printf("Select n:  ");
    scanf_s("%d", &N);

    int result = 0;
    int maxSum = 0;
    int temp = 0;
    for (int i = 2; i <= N; i++) {
        temp = i;
        int sum = 1;
        int counter = 2;

        while (temp != counter) {
            if (isPrime(counter) && (temp % counter) == 0)
            {
                sum += counter;
                temp = temp / counter;
            }
            else
            {
                counter++;
            }
        }
        sum += counter;
        if (sum > maxSum) {
            maxSum = sum;
            result = i;
        }

    }
    printf("Summ: %d\n", maxSum);
    printf("Result: %d\n", result);

    return 0;
}