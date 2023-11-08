#include <stdio.h>
#include <stdbool.h>
#include <math.h>
int main() {
    int N;
    printf("Select n:  ");
    scanf_s("%d", &N);
    int maxSum = 0;
    for (int i = 2; i < sqrt(N); i++) {
        if ((N % i == 0) && (maxSum < (i + (N / i)))) { maxSum = i + N / i; }
    }
        printf("Maxsum:%d", maxSum);
        return 0;
    }