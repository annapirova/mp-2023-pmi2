#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

#define MAX_SIZE 10000

// ������� ��� ��������� ���������� ����� � �������� ���������
int generateRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}

// ������� ��� ���������� ������� ���������� �������
void fillArrayRandomly(int array[], int size, int min, int max) {
    for (int i = 0; i < size; i++) {
        array[i] = generateRandomNumber(min, max);
    }
}

// ������� ��� ������ �������
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// ������� ��� ������ ��������� �������
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// ������� ����������

// ���������� ���������
void bubbleSort(int array[], int size, int* comparisons, int* swaps) {
    clock_t start_time, end_time;
    double cpu_time_used;

    start_time = clock();

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            (*comparisons)++;
            if (array[j] > array[j + 1]) {
                (*swaps)++;
                swap(&array[j], &array[j + 1]);
            }
        }
    }

    end_time = clock();
    cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("����� ���������� ���������� ���������: %f ������\n", cpu_time_used);
}

// ���������� ���������
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

    printf("����� ���������� ���������� ���������: %f ������\n", cpu_time_used);
}

// ���������� �������
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

    printf("����� ���������� ���������� �������: %f ������\n", cpu_time_used);
}

// ���������� ��������
void merge(int array[], int left, int mid, int right, int* comparisons, int* swaps) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    if (L == NULL || R == NULL) {
        // ��������� ������ ��������� ������
        fprintf(stderr, "������ ��������� ������\n");
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
        fprintf(stderr, "������ ��������� ������\n");
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

    printf("����� ���������� ���������� ���������: %f ������\n", cpu_time_used);
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

// �����

// �������� �����
int linearSearch(int array[], int size, int key, int* comparisons) {
    for (int i = 0; i < size; i++) {
        (*comparisons)++;
        if (array[i] == key) {
            return i;
        }
    }
    return -1; // ������� �� ������
}

// �������� �����
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
    return -1; // ������� �� ������
} 
void fillArrayManually(int array[], int size) {
    wprintf(L"������� %d ��������� �������:\n", size);
    for (int i = 0; i < size; i++) {
        if (scanf_s("%d", &array[i]) != 1) {
            wprintf(L"������ �����. ��������� ����.\n");
            i--; // ��������� ���� ��� ���� �� ��������
        }
    }
}

int main() {
    setlocale(LC_ALL, "RUS");

    int array[MAX_SIZE];
    int key, comparisons, swaps;
    srand(time(NULL));

    int choice;
    do {
        wprintf(L"\n�������� ������ ����� �������:\n");
        wprintf(L"1. ��������� ������ ���������� �������\n");
        wprintf(L"2. ������ ������ �������\n");
        wprintf(L"0. �����\n");

        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            fillArrayRandomly(array, MAX_SIZE, 1, 100);
            wprintf(L"\n������ �������� ���������� �������:\n");
            printArray(array, MAX_SIZE);
            break;

        case 2:
            fillArrayManually(array, MAX_SIZE);
            wprintf(L"\n��������� ������� ������:\n");
            printArray(array, MAX_SIZE);
            break;

        case 0:
            wprintf(L"��������� ���������.\n");
            break;

        default:
            wprintf(L"������������ ����. ���������� ��� ���.\n");
        }

        if (choice != 0) {
            do {
                wprintf(L"\n�������� ��������:\n");
                wprintf(L"1. ���������� ���������\n");
                wprintf(L"2. ���������� ���������\n");
                wprintf(L"3. ���������� �������\n");
                wprintf(L"4. ���������� ��������\n");
                wprintf(L"5. ���������� ���������\n");
                wprintf(L"6. ���������� �������\n");
                wprintf(L"7. �������� �����\n");  
                wprintf(L"8. �������� �����\n");
                wprintf(L"0. �����\n");

                scanf_s("%d", &choice);

                switch (choice) {
                case 1:
                    comparisons = swaps = 0;
                    bubbleSort(array, MAX_SIZE, &comparisons, &swaps);
                    wprintf(L"\n���������� ���������:\n");
                    wprintf(L"������������: %d\n", swaps);
                    wprintf(L"���������: %d\n", comparisons);
                    printArray(array, MAX_SIZE);
                    break;

                case 2:
                    comparisons = swaps = 0;
                    insertionSort(array, MAX_SIZE, &comparisons, &swaps);
                    wprintf(L"\n���������� ���������:\n");
                    wprintf(L"������������: %d\n", swaps);
                    wprintf(L"���������: %d\n", comparisons);
                    printArray(array, MAX_SIZE);
                    break;

                case 3:
                    comparisons = swaps = 0;
                    selectionSort(array, MAX_SIZE, &comparisons, &swaps);
                    wprintf(L"\n���������� �������:\n");
                    wprintf(L"������������: %d\n", swaps);
                    wprintf(L"���������: %d\n", comparisons);
                    printArray(array, MAX_SIZE);
                    break;

                case 4:
                    comparisons = swaps = 0;
                    mergeSort(array, 0, MAX_SIZE - 1, &comparisons, &swaps);
                    wprintf(L"\n���������� ��������:\n");
                    wprintf(L"������������: %d\n", swaps);
                    wprintf(L"���������: %d\n", comparisons);
                    printArray(array, MAX_SIZE);
                    break;

                case 5:
                    comparisons = swaps = 0;
                    countingSort(array, MAX_SIZE, &comparisons, &swaps);
                    wprintf(L"\n���������� ���������:\n");
                    wprintf(L"������������: %d\n", swaps);
                    wprintf(L"���������: %d\n", comparisons);
                    printArray(array, MAX_SIZE);
                    break;

                case 6:
                    comparisons = swaps = 0;
                    quickSort(array, 0, MAX_SIZE - 1, &comparisons, &swaps);
                    wprintf(L"\n������� ����������:\n");
                    wprintf(L"������������: %d\n", swaps);
                    wprintf(L"���������: %d\n", comparisons);
                    printArray(array, MAX_SIZE);
                    break;

                case 7:
                    wprintf(L"\n������� ������� ��� ��������� ������: ");
                    scanf_s("%d", &key);
                    comparisons = 0;
                    int linearResult = linearSearch(array, MAX_SIZE, key, &comparisons);
                    if (linearResult != -1) {
                        wprintf(L"������� %d ������ �� ������� %d\n", key, linearResult + 1);
                    }
                    else {
                        wprintf(L"������� %d �� ������\n", key);
                    }
                    wprintf(L"���������: %d\n", comparisons);
                    break;

                case 8:
                    wprintf(L"\n������� ������� ��� ��������� ������: ");
                    scanf_s("%d", &key);
                    comparisons = 0;
                    int binaryResult = binarySearch(array, 0, MAX_SIZE - 1, key, &comparisons);
                    if (binaryResult != -1) {
                        wprintf(L"������� %d ������ �� ������� %d\n", key, binaryResult + 1);
                    }
                    else {
                        wprintf(L"������� %d �� ������\n", key);
                    }
                    wprintf(L"���������: %d\n", comparisons);
                    break;

                case 0:
                    wprintf(L"��������� ���������.\n");
                    break;

                default:
                    wprintf(L"������������ ����. ���������� ��� ���.\n");
                }

            } while (choice != 0);
        }

    } while (choice != 0);

    return 0;
}