#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_SIZE 10

//Function Proverki mass na sortirovkiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii
bool isSorted(int array[], int size) {
    for (int i = 1; i < size; ++i) {
        if (array[i - 1] > array[i]) {
            return false;  // Массив не отсортирован
        }
    }
    return true;  // Массив отсортирован
}

void copyMass(int dest[], const int source[], int size) {
    for (int i = 0; i < size; i++) {
        dest[i] = source[i];
    }
}
// Функция для генерации случайного числа в заданном диапазоне
int generateRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Функция для заполнения массива случайными числами
void fillArrayRandomly(int array[], int size, int min, int max) {
    for (int i = 0; i < size; i++) {
        array[i] = generateRandomNumber(min, max);
    }
}

// Функция для вывода массива
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Функция для обмена элементов массива
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Простые сортировки

// Сортировка пузырьком(двунаправленным)
void bubbleSort(int array[], int size, int* comparisons, int* swaps) {
    clock_t start_time, end_time;
    double cpu_time_used;

    start_time = clock();

    int left = 0;
    int right = size - 1;
    int swapped = 1;

    while (left < right&& swapped) {
        swapped = 0;

        // Проход слева направо
        for (int i = left; i < right; i++) {
            (*comparisons)++;
            if (array[i] > array[i + 1]) {
                (*swaps)++;
                swap(&array[i], &array[i + 1]);
                swapped = 1;
            }
        }
        right--;

        // Проход справа налево
        for (int i = right; i > left; i--) {
            (*comparisons)++;
            if (array[i - 1] > array[i]) {
                (*swaps)++;
                swap(&array[i - 1], &array[i]);
                swapped = 1;
            }
        }
        left++;
    }

    end_time = clock();
    cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Время выполнения двунаправленной сортировки пузырьком: %f секунд\n", cpu_time_used);
}

// Сортировка вставками
void insertionSort(int array[], int size, int* comparisons, int* swaps) {
    clock_t start_time, end_time;
    double cpu_time_used;

    start_time = clock();
 {
        for (int i = 1; i < size; i++) {
        int key = array[i];
        int j = i - 1;
        (*comparisons)++;
        while (j >= 0 && array[j] > key) {
            (*swaps)++;
            array[j + 1] = array[j];
            j = j - 1;
         }
        array[j + 1] = key;
        }
    }

    end_time = clock();
    cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Время выполнения сортировки вставками: %f секунд\n", cpu_time_used);
}

// Сортировка выбором
void selectionSort(int array[], int size, int* comparisons, int* swaps) {
    clock_t start_time, end_time;
    double cpu_time_used;

    start_time = clock();

    {
        for (int i = 0; i < size - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < size; j++) {
                (*comparisons)++;
                if (array[j] < array[minIndex]) {
                    minIndex = j;
                }
            }
            (*swaps)++;
            swap(&array[i], &array[minIndex]);
        }
    }

    end_time = clock();
    cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Время выполнения сортировки выбором: %f секунд\n", cpu_time_used);
}

// Сортировка слиянием
void merge(int array[], int left, int mid, int right, int* comparisons, int* swaps) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    if (L == NULL || R == NULL) {
        // Обработка ошибки выделения памяти
        fprintf(stderr, "Ошибка выделения памяти\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n1; i++) {
        L[i] = array[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = array[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        (*comparisons)++;
        if (L[i] <= R[j]) {
            (*swaps)++;
            array[k] = L[i];
            i++;
        }
        else {
            (*swaps)++;
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        (*swaps)++;
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        (*swaps)++;
        array[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(int array[], int left, int right, int* comparisons, int* swaps) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(array, left, mid, comparisons, swaps);
        mergeSort(array, mid + 1, right, comparisons, swaps);

        merge(array, left, mid, right, comparisons, swaps);
    }
}
void countingSort(int array[], int size, int* comparisons, int* swaps) {
    clock_t start_time, end_time;
    double cpu_time_used;

    start_time = clock();
    
        int max = array[0];
        for (int i = 1; i < size; i++) {
            (*comparisons)++;
            if (array[i] > max) {
                max = array[i];
            }
        }
    
    int* count = (int*)malloc((max + 1) * sizeof(int));
    int* output = (int*)malloc(size * sizeof(int));

    if (count == NULL || output == NULL) {
        fprintf(stderr, "Ошибка выделения памяти\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        count[array[i]]++;
    }

    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        (*swaps)++;
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    for (int i = 0; i < size; i++) {
        array[i] = output[i];
    }

    free(count);
    free(output);
    end_time = clock();
    cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Время выполнения сортировки подсчетом: %f секунд\n", cpu_time_used);
}

// Quick Sort
int partition(int array[], int low, int high, int* comparisons, int* swaps) {
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        (*comparisons)++;
        if (array[j] < pivot) {
            i++;
            (*swaps)++;
            swap(&array[i], &array[j]);
        }
    }

    (*swaps)++;
    swap(&array[i + 1], &array[high]);
    return i + 1;
}

void quickSort(int array[], int low, int high, int* comparisons, int* swaps) {
    if (low < high) {
        int pi = partition(array, low, high, comparisons, swaps);

        quickSort(array, low, pi - 1, comparisons, swaps);
        quickSort(array, pi + 1, high, comparisons, swaps);
    }
}

// Поиск

// Линейный поиск
int linearSearch(int array[], int size, int key, int* comparisons) {
    for (int i = 0; i < size; i++) {
        (*comparisons)++;
        if (array[i] == key) {
            return i;
        }
    }
    return -1; // Элемент не найден
}

// Бинарный поиск
int binarySearch(int array[], int left, int right, int key, int* comparisons) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        (*comparisons)++;
        if (array[mid] == key) {
            return mid;
        }
        (*comparisons)++;
        if (array[mid] < key) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1; // Элемент не найден
} 
void fillArrayManually(int array[], int size) {
    wprintf(L"Введите %d элементов массива:\n", size);
    for (int i = 0; i < size; i++) {
        if (scanf_s("%d", &array[i]) != 1) {
            wprintf(L"Ошибка ввода. Повторите ввод.\n");
            i--; // Повторить ввод для того же элемента
        }
    }
}

int main() {
    setlocale(LC_ALL, "RUS");
    int arr[4] = { 89, 10, 67, 7 };
    int len = *(&arr + 1) - arr;
    int arrCopy[10];

    copyMass(arrCopy, arr, len);

    // Code from the second snippet
    int array[MAX_SIZE];
    int key, comparisons, swaps;
    srand(time(NULL));

    int choice;
    do {
        wprintf(L"\nВыберите способ ввода массива:\n");
        wprintf(L"1. Заполнить массив случайными числами\n");
        wprintf(L"2. Ввести массив вручную\n");
        wprintf(L"0. Выход\n");

        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            fillArrayRandomly(array, MAX_SIZE, 1, 100);
            wprintf(L"\nМассив заполнен случайными числами:\n");
            printArray(array, MAX_SIZE);
            break;

        case 2:
            fillArrayManually(array, MAX_SIZE);
            wprintf(L"\nВведенный вручную массив:\n");
            printArray(array, MAX_SIZE);
            break;

        case 0:
            wprintf(L"Программа завершена.\n");
            break;

        default:
            wprintf(L"Некорректный ввод. Попробуйте еще раз.\n");
        }

        if (choice != 0) {
            do {
                wprintf(L"\nВыберите операцию:\n");
                wprintf(L"1. Сортировка пузырьком\n");
                wprintf(L"2. Сортировка вставками\n");
                wprintf(L"3. Сортировка выбором\n");
                wprintf(L"4. Сортировка слиянием\n");
                wprintf(L"5. сортировка подсчетом\n");
                wprintf(L"6. Сортировка быстрая\n");
                wprintf(L"7. Линейный поиск\n");  
                wprintf(L"8. Бинарный поиск\n");
                wprintf(L"0. Выход\n");

                scanf_s("%d", &choice);

                switch (choice) {

                case 1:
                    comparisons = swaps = 0;
                    bubbleSort(array, MAX_SIZE, &comparisons, &swaps);
                    wprintf(L"\nСортировка пузырьком:\n");
                    wprintf(L"Перестановок: %d\n", swaps);
                    wprintf(L"Сравнений: %d\n", comparisons);
                    printArray(array, MAX_SIZE);
                    if (isSorted(array, MAX_SIZE)) {
                        wprintf(L"Массив отсортирован.\n");
                    }
                    else {
                        wprintf(L"Ошибка сортировки!\n");
                    }
                    break;

                case 2:
                    // Ваш код для сортировки вставками
                    comparisons = swaps = 0;
                    insertionSort(array, MAX_SIZE, &comparisons, &swaps);
                    wprintf(L"\nСортировка вставками:\n");
                    wprintf(L"Перестановок: %d\n", swaps);
                    wprintf(L"Сравнений: %d\n", comparisons);
                    printArray(array, MAX_SIZE);
                    if (isSorted(array, MAX_SIZE)) {
                        wprintf(L"Массив отсортирован.\n");
                    }
                    else {
                        wprintf(L"Ошибка сортировки!\n");
                    }
                    break;

                case 3:
                    // Ваш код для сортировки выбором
                    comparisons = swaps = 0;
                    selectionSort(array, MAX_SIZE, &comparisons, &swaps);
                    wprintf(L"\nСортировка выбором:\n");
                    wprintf(L"Перестановок: %d\n", swaps);
                    wprintf(L"Сравнений: %d\n", comparisons);
                    printArray(array, MAX_SIZE);
                    if (isSorted(array, MAX_SIZE)) {
                        wprintf(L"Массив отсортирован.\n");
                    }
                    else {
                        wprintf(L"Ошибка сортировки!\n");
                    }
                    break;

                case 4:
                    comparisons = swaps = 0;
                    mergeSort(arrCopy, 0, len - 1, &comparisons, &swaps);
                    wprintf(L"\nСортировка слиянием:\n");
                    wprintf(L"Перестановок: %d\n", swaps);
                    wprintf(L"Сравнений: %d\n", comparisons);
                    printArray(arrCopy, len);
                    if (isSorted(arrCopy, len)) {
                        wprintf(L"Массив отсортирован.\n");
                    }
                    else {
                        wprintf(L"Ошибка сортировки!\n");
                    }
                    break;
                case 5:
                    comparisons = swaps = 0;
                    countingSort(array, MAX_SIZE, &comparisons, &swaps);
                    wprintf(L"\nСортировка подсчетом:\n");
                    wprintf(L"Перестановок: %d\n", swaps);
                    wprintf(L"Сравнений: %d\n", comparisons);
                    printArray(array, MAX_SIZE);
                    if (isSorted(array, MAX_SIZE)) {
                        wprintf(L"Массив отсортирован.\n");
                    }
                    else {
                        wprintf(L"Ошибка сортировки!\n");
                    }
                    break;


                case 6:
                    comparisons = swaps = 0;
                    quickSort(array, 0, MAX_SIZE - 1, &comparisons, &swaps);
                    wprintf(L"\nБыстрая сортировка:\n");
                    wprintf(L"Перестановок: %d\n", swaps);
                    wprintf(L"Сравнений: %d\n", comparisons);
                    printArray(array, MAX_SIZE);
                    if (isSorted(array, MAX_SIZE)) {
                        wprintf(L"Массив отсортирован.\n");
                    }
                    else {
                        wprintf(L"Ошибка сортировки!\n");
                    }
                    break;

                case 7:
                    wprintf(L"\nВведите элемент для линейного поиска: ");
                    scanf_s("%d", &key);
                    comparisons = 0;
                    int linearResult = linearSearch(array, MAX_SIZE, key, &comparisons);
                    if (linearResult != -1) {
                        wprintf(L"Элемент %d найден на позиции %d\n", key, linearResult + 1);
                    }
                    else {
                        wprintf(L"Элемент %d не найден\n", key);
                    }
                    wprintf(L"Сравнений: %d\n", comparisons);
                    break;

                case 8:
                    wprintf(L"\nВведите элемент для бинарного поиска: ");
                    scanf_s("%d", &key);
                    comparisons = 0;
                    int binaryResult = binarySearch(array, 0, MAX_SIZE - 1, key, &comparisons);
                    if (binaryResult != -1) {
                        wprintf(L"Элемент %d найден на позиции %d\n", key, binaryResult + 1);
                    }
                    else {
                        wprintf(L"Элемент %d не найден\n", key);
                    }
                    wprintf(L"Сравнений: %d\n", comparisons);
                    break;

                case 0:
                    wprintf(L"Программа завершена.\n");
                    break;

                default:
                    wprintf(L"Некорректный ввод. Попробуйте еще раз.\n");
                }

            } while (choice != 0);
        }

    } while (choice != 0);

    return 0;
}