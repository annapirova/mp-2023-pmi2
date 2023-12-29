#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int proverka(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return 0; 
        }
    }
    return 1; 
}
//functia zameni znach peremennih dryg na druga isp dlya bubble, piramidnoi sortirovkah.:
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
// otvehaet za sliianie dvyh massivov dlia sort slianiem:
void slianie(int arr[], int l, int m, int r, int* comparisons, int* swaps) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        (*comparisons)++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            (*swaps)++;
            i++;
        }
        else {
            arr[k] = R[j];
            (*swaps)++;
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        (*swaps)++;
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        (*swaps)++;
        j++;
        k++;
    }

    free(L);
    free(R);
}
//sama sortirovka slianiem:
void sliianiesort(int arr[], int l, int r, int* comparisons, int* swaps) {
    if (l < r) {
        int m = l + (r - l) / 2;

        sliianiesort(arr, l, m, comparisons, swaps);
        sliianiesort(arr, m + 1, r, comparisons, swaps);

        slianie(arr, l, m, r, comparisons, swaps);
    }
}
//functiia dla pechati massiva(t.k. mnogo gde ispolzyetsa)
void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
//sortirovka bubbles:
void bubbleSort(int arr[], int n, int* comparisons, int* swaps) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        int flag = 0;
        for (j = 0; j < n - i - 1; j++) {
            (*comparisons)++;
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                (*swaps)++;
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
}
//sortirovka vstavkami:
void vstavkisort(int arr[], int n, int* comparisons, int* swaps) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            (*comparisons)++;
            arr[j + 1] = arr[j];
            (*swaps)++;
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}



//dlia piramidnoi sortirovki sozdaet i obnovlaet piramidy:
void piramida(int arr[], int n, int i, int* comparisons, int* swaps) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest]) {
        (*comparisons)++;
        largest = l;
    }

    if (r < n && arr[r] > arr[largest]) {
        (*comparisons)++;
        largest = r;
    }

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        (*swaps)++;

        piramida(arr, n, largest, comparisons, swaps);
    }
}
//piraminaia sortirovka:
void piramidnaiasort(int arr[], int n, int* comparisons, int* swaps) {
    int i;
    for (i = n / 2 - 1; i >= 0; i--) {
        piramida(arr, n, i, comparisons, swaps);
    }

    for (i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        (*swaps)++;

        piramida(arr, i, 0, comparisons, swaps);
    }
}


//lineini poisk:
int linearSearch(int arr[], int n, int key, int* comparisons) {
    int i;
    for (i = 0; i < n; i++) {
        (*comparisons)++;
        if (arr[i] == key)
            return i;
    }
    return -1;
}
//binarni:
int binarySearch(int arr[], int left, int right, int key, int* comparisons) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            (*comparisons)++;
            return mid;
        }

        if (arr[mid] > key) {
            (*comparisons)++;
            return binarySearch(arr, left, mid - 1, key, comparisons);
        }

        (*comparisons)++;
        return binarySearch(arr, mid + 1, right, key, comparisons);
    }

    return -1;
}

int main() {
    int arr[10000], add[10000];
    int n, i, da, ff;
    int comparisons = 0, swaps = 0;
    int key, searchIndex;
    int choice;
    ff = 0;

    printf("vvedite kol-vo el-tov in array(max 10000): ");
    scanf_s("%d", &n);

    if (n <= 0 || n > 10000) {
        printf("nepravilnoe znach\n");
        return 0;
    }

    printf("viberite sposob vvoda massiva:\n");
    printf("1. Ruchkami\n");
    printf("2. Random\n");
    scanf_s("%d", &choice);

    switch (choice) {
    case 1:
        for (i = 0; i < n; i++)
        {
            printf("vedite %d el-t array", i);
            scanf_s("%d", &arr[i]);
        }
        break;
    case 2:
        printf("vedite max and min znach array: ");
        int lower, upper;
        scanf_s("%d%d", &lower, &upper);
        srand(time(0));
        for (i = 0; i < n; i++)
        {
            arr[i] = (rand() % (upper - lower + 1)) + lower;
        }
        break;
    default:
        printf("nekkoretnie znachenia!\n");
        return 0;
    }

    printf("\nyour array: ");
    printArray(arr, n);

    comparisons = 0;
    swaps = 0;
    do {
        if (ff == 0)
        {
            for (i = 0; i < n; i++)
            {
                arr[i] = add[i];
           }
            ff++;
        }
        else
        {
            for (int i = 0; i < n; i++) {
                add[i] = arr[i];
            }
        }
        printf("\nchoose your metod sortirovka:\n");
        printf("0. dosrochnoe zavershenie programmi\n");
        printf("1. by bubbles\n");
        printf("2. by vstavki\n");
        printf("3. by slianie\n");
        printf("4. piramidnaia\n");
        scanf_s("%d", &choice);

        switch (choice) {
        case 0:
            printf("Программа завершена.\n");
            return 0;
        case 1:
            bubbleSort(arr, n, &comparisons, &swaps);
            printf("\nby bubbles:\n");
            break;
        case 2:
            vstavkisort(arr, n, &comparisons, &swaps);
            printf("\nby vstavki:\n");
            break;
        case 3:
            sliianiesort(arr, 0, n - 1, &comparisons, &swaps);
            printf("\nby slianie:\n");
            break;
        case 4:
            piramidnaiasort(arr, n, &comparisons, &swaps);
            printf("\npiramidnaia:\n");
            break;
        default:
            printf("error!\n");
            break;
        }

        printf("sorted array: ");
        printArray(arr, n);
        printf("kol-vo perestanovok: %d\n", swaps);
        printf("kol-vo sravneni: %d\n", comparisons);
        printf("work time: %lf\n", (double)clock() / CLOCKS_PER_SEC);

        if (choice != 0) {
            printf("\nchoose your search metod:\n");
            printf("0. dosrochnoe zavershenie programmi\n");
            printf("1. lineini poisk\n");
            printf("2. binarni poisk\n");
            scanf_s("%d", &choice);

            switch (choice) {
            case 0:
                printf("dosrochnoe zavershenie\n");
                return 0;
            case 1:
                printf("\nlineini poisk:\n");
                printf("choose el-t for searching: ");
                scanf_s("%d", &key);
                comparisons = 0;
                searchIndex = linearSearch(arr, n, key, &comparisons);
                if (searchIndex == -1)
                    printf("el-t %d not found!\n", key);
                else  printf("el-t %d fonded on the position %d.\n", key, searchIndex);
                printf("kol-vo sravneni: %d\n", comparisons);
                break;
            case 2:
                printf("\nbinarni poisk:\n");
                printf("choose el-t for searching: ");
                scanf_s("%d", &key);
                comparisons = 0;
                searchIndex = binarySearch(arr, 0, n - 1, key, &comparisons);
                if (searchIndex == -1)
                    printf("el-t %d not found!\n", key);
                else
                      printf("el-t %d fonded on the position %d.\n", key, searchIndex);
                      printf("kol-vo sravneni: %d\n", comparisons);
                break;
            default:
                printf("error!\n");
                break;
            }
        }
        if (choice != 0) {
            printf("\nchoose proverka da ili net:\n");
            printf("0. dosrochnoe zavershenie programmi\n");
            printf("1. go proverka\n");
            scanf_s("%d", &choice);

            switch (choice) {

            case 0:
                printf("dosrochnoe zavershenie\n");
                return 0;
            case 1:
                printf("\nPROVERKA\n");
                da = proverka(arr, n);
                if (da = 1)
                {
                    printf("\nPROVERKA proshla yspeshno\n");
                }
                else
                {
                    printf("\nPROVERKA ne proshla. Chto-to poshlo ne tak:(\n");
                }
                break;
            default:
                printf("error!\n");
                break;
            }
        }
    } while (choice != 0);

    return 0;
}