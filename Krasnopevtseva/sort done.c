#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h> 
#include <stdbool.h>
#include <memory.h>
#include <windows.h>
#include <time.h>
void Check(int a[], int n)
{
    int i, pr = 0;
    for (i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1]) pr = 1;
    }
    if (pr == 0) printf("ќтсортировано!\n");
    else printf("—ортировка пошла не так...\n");
}
void printsort(int a[], int n) //печать сортированного массива
{
    printf("ќтсортированный массив:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}
void SortVctavka(int B[], int n) //сортировка вставками
{
    int x, pos;
    for (int i = 1; i < n; i++)
    {
        x = B[i];
        pos = i - 1;
        while ((pos >= 0) && (B[pos] > x))
        {
            B[pos + 1] = B[pos];
            pos = pos - 1;
        }
        B[pos + 1] = x;
    }
}
void SortVibor(int a[], int n)
{
    int minPosition, tmp;
    for (int i = 0; i < n; i++)
    {
        minPosition = i;
        for (int j = i + 1; j < n; j++)
            if (a[minPosition] > a[j])
                minPosition = j;
        tmp = a[minPosition];
        a[minPosition] = a[i];
        a[i] = tmp;
    }
}
void SortBubble(int a[], int n) //сортировка пузырьком
{
    int l = 1;
    int r = n - 1;
    int tmp;
    while (l <= r)
    {
        for (int i = r; i >= l; i--)
            if (a[i - 1] > a[i])
            {
                tmp = a[i];
                a[i] = a[i - 1];
                a[i - 1] = tmp;
            }
        l++;
        for (int i = l; i <= r; i++)
            if (a[i - 1] > a[i])
            {
                tmp = a[i];
                a[i] = a[i - 1];
                a[i - 1] = tmp;
            }
        r--;
    }
}
void SortPodchet(int a[], int b[], int n)
{
    int k;
    for (int i = 0; i < n; i++)
    {
        k = 0;
        for (int j = 0; j < n; j++)
        {
            if (b[i] > b[j])
                k++;
        }
        a[k] = b[i];
    }
}
void QuickSort(int a[], int n, int first, int last)
{
    int i = first, j = last, x = a[(first + last) / 2], tmp;
    do {
        while (a[i] < x) i++;
        while (a[j] > x) j--;

        if (i <= j) {
            if (a[i] > a[j])
            {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
            i++;
            j--;
        }
    } while (i <= j);

    if (i < last)
        QuickSort(a, n, i, last);
    if (first < j)
        QuickSort(a, n, first, j);
}
void MergeSort(int i, int j, int a[]) {
    if (j <= i) {
        return;    
    }
    int mid = (i + j) / 2;
    int *aux;
    aux = (int*)malloc(sizeof(int) * (j+1));
    MergeSort(i, mid, a, aux);    
    MergeSort(mid + 1, j, a, aux);     
    int pointer_left = i;     
    int pointer_right = mid + 1;        
    int k;      
    for (k = i; k <= j; k++) {
        if (pointer_left == mid + 1) {      
            aux[k] = a[pointer_right];
            pointer_right++;
        }
        else if (pointer_right == j + 1) {        
            aux[k] = a[pointer_left];
            pointer_left++;
        }
        else if (a[pointer_left] < a[pointer_right]) {       
            aux[k] = a[pointer_left];
            pointer_left++;
        }
        else {        
            aux[k] = a[pointer_right];
            pointer_right++;
        }
    }
    for (k = i; k <= j; k++) {      
        a[k] = aux[k];
    }
}
void commands()
{
    printf("1 - ввести массив\n");
    printf("2 - сгенерировать массив\n");
    printf("3 - сортировка вставками\n");
    printf("4 - сортировка пузырьком\n");
    printf("5 - сортировка сли¤нием\n");
    printf("6 - сортировка подсчетом\n");
    printf("7 - быстра¤ сортировка\n");
    printf("8 - сортировка выбором\n");
    printf("9 - выход\n");
    printf("\n");
}

int main()
{
    setlocale(LC_CTYPE, "Russian");
    int choice;
    int n;
    int* A;
    int* B;
    int flag = 0;
    A = (int*)malloc(1000000 * sizeof(int));
    B = (int*)malloc(1000000 * sizeof(int));
    bool run = true;
    srand(time(NULL));
    LARGE_INTEGER freq, start, finish;
    double timeee;
    QueryPerformanceFrequency(&freq);
    printf("ѕриветик, ¤ программа, котора¤ сортирует массивы!\n");
    printf("¬от мои команды:\n");
    commands();
    printf("¬веди команду)\n");
    while (run)
    {
        scanf_s("%d", &choice);
        switch (choice)
        {
        case 1: {
            if (flag == 1)
            {
                free(A);
                free(B);
            }
            do {
                printf("¬ведите длину массива\n");
                scanf_s("%d", &n);
                if (n < 1) printf("ƒанные некорректны, введите натуральное n\n");
            } while (n < 1);
            A = (int*)malloc(sizeof(int) * (n));
            B = (int*)malloc(sizeof(int) * (n));
            printf("¬ведите массив\n");
            for (int i = 0; i < n; i++)
            {
                scanf_s("%d", &A[i]);
            }
            memcpy(B, A, sizeof(int) * n);
            flag = 1;
            printf("\n");
            printf("¬веди новую команду)\n"); break; }
        case 2: {
            if (flag == 1)
            {
                free(A);
                free(B);
            }
            printf("¬ведите длину массива\n");
            scanf_s("%d", &n);
            A = (int*)malloc(sizeof(int) * n);
            B = (int*)malloc(sizeof(int) * n);
            for (int i = 0; i < n; i++)
            {
                A[i] = -100 + rand() % 200;
            }
            memcpy(B, A, sizeof(int) * n);
            flag = 1;
            printf("Cгенерированный массив:\n");
            for (int i = 0; i < n; i++)
            {
                printf("%d ", A[i]);
            }
            printf("¬веди новую команду)\n");
            break;
        }
        case 3: {   if (flag == 1)
        {
            QueryPerformanceCounter(&start);
            SortVctavka(B, n);
            QueryPerformanceCounter(&finish);
            timeee = (double)(finish.QuadPart - start.QuadPart);
            printsort(B, n);
            Check(B, n);
            printf("¬рем¤ - %lf\n", timeee);
            memcpy(B, A, sizeof(int) * n);
        }
              else
            printf("—начала введите массив в команде 1\n");
            printf("¬веди новую команду)\n");
            break; }
        case 4: {   if (flag == 1)
        {
            QueryPerformanceCounter(&start);
            SortBubble(B, n);
            QueryPerformanceCounter(&finish);
            timeee = (double)(finish.QuadPart - start.QuadPart);
            printsort(B, n);
            Check(B, n);
            printf("¬рем¤ - %lf\n", timeee);
            memcpy(B, A, sizeof(int) * n);
        }
              else
            printf("—начала введите массив в команде 1\n");
            printf("¬веди новую команду)\n");
            break; }
        case 5: {   if (flag == 1)
        {
            QueryPerformanceCounter(&start);
            MergeSort(0, n - 1, B);
            QueryPerformanceCounter(&finish);
            timeee = (double)(finish.QuadPart - start.QuadPart);
            printsort(B, n);
            Check(B, n);
            printf("¬рем¤ - %lf\n", timeee);
            memcpy(B, A, sizeof(int) * n);
        }

              else
            printf("—начала введите массив в команде 1\n");
            printf("¬веди новую команду)\n");
            break; }
        case 6: {   if (flag == 1)
        {
            QueryPerformanceCounter(&start);
            SortPodchet(B, A, n);
            QueryPerformanceCounter(&finish);
            timeee = (double)(finish.QuadPart - start.QuadPart);
            printsort(B, n);
            Check(B, n);
            printf("¬рем¤ - %lf\n", timeee);
            memcpy(B, A, sizeof(int) * n);
        }
              else
            printf("—начала введите массив в команде 1\n");
            printf("¬веди новую команду)\n");
            break; }
        case 7: {   if (flag == 1)
        {
            QueryPerformanceCounter(&start);
            QuickSort(B, n, 0, n - 1);
            QueryPerformanceCounter(&finish);
            timeee = (double)(finish.QuadPart - start.QuadPart);
            printsort(B, n);
            Check(B, n);
            printf("¬рем¤ - %lf\n", timeee);
            memcpy(B, A, sizeof(int) * n);
        }
              else
            printf("—начала введите массив в команде 1\n");
            printf("¬веди новую команду)\n");
            break; }
        case 8: {   if (flag == 1)
        {
            QueryPerformanceCounter(&start);
            SortVibor(B, n);
            QueryPerformanceCounter(&finish);
            timeee = (double)(finish.QuadPart - start.QuadPart);
            printsort(B, n);
            Check(B, n);
            printf("¬рем¤ - %lf\n", timeee);
            memcpy(B, A, sizeof(int) * n);
        }
              else
            printf("—начала введите массив в команде 1\n");
            printf("¬веди новую команду)\n");
            break; }
        case 9: {
            printf("”же уходите? ’орошего дн¤!!\n");
            run = 0;
            break; }
        default: { printf("Ќет такой комманды, у мен¤ их 9 :(\n"); break; }
        }
    }
    free(A);
    free(B);
    return 0;
}
