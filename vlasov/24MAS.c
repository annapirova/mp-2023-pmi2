#include <stdio.h>

#define MAX_SIZE 100

int hasDuplicates(int a[], int size) {
    // ƒл€ хранени€ информации о встреченных элементах используем массив счетчиков
    int mass[MAX_SIZE] = { 0 };

    // ѕеребираем все элементы массива и увеличиваем ye;ysq счетчик
    for (int i = 0; i < size; i++) {
        mass[a[i]]++;
    }

    // ѕровер€ем, если какой-либо счетчик больше 1, то имеютс€ повтор€ющиес€ элементы
    for (int i = 0; i < MAX_SIZE; i++) {
        if (mass[i] > 1) {
            return 1; // есть повтор€ющиес€ элементы
        }
    }

    return 0; // нет повтор€ющихс€ элементов
}

int main() {
    int size;
    printf("vvedite razmer massiva: ");
    scanf_s("%d", &size);

    int a[MAX_SIZE];
    printf("vvedite elementi massiva: ");
    for (int i = 0; i < size; i++) {
        scanf_s("%d", &a[i]);
    }

    if (hasDuplicates(a, size)) {
        printf("V massive ect' povtoryauhiecya elementi.\n");
    }
    else {
        printf("V massive net povtoryauhixcya elementov.\n");
    }

    return 0;
}