#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int N, i, a;
    int H[MAX_SIZE] = { 0 };
    int Arr_H[MAX_SIZE] = { 0 }; // Массив для проверки появления чисел от 1 до N

    printf("Vvedite dlinu massiva\n");
    scanf_s("%d", &N);

    for (i = 0; i < N; i++) {
        scanf_s("%d", &a);
        if (a >= 1 && a <= N && Arr_H[a - 1] == 0) {
            Arr_H[a - 1] = 1;
            H[i] = a;
        }
        else {
            printf("Massiv ne yavl perestanovkoi\n");
            return 1;
        }
    }
    printf("Massiv yavl perestanovkoi\n");
    return 0;
}