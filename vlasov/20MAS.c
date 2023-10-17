#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void findClosestSum(int a[], int n, int t) { // n - размер массива
    int left = 0, right = n - 1;
    int N = INT_MAX;
    int res_l, res_r; //указатели(один в начале массива, другой в конце)

    while (left < right) {
        int sum = a[left] + a[right];

        if (abs(sum - t) < abs(N - t)) {
            N = sum;
            res_l = left;
            res_r = right;
        }

        if (sum < t)
            left++;
        else
            right--;
    }

    printf("Summa elementov %d I %d naibolee blizka k %d.\n", a[res_l], a[res_r], t);
}

int main() {
    int a[] = { -10, -3, 0, 5, 9 }; // элементы массива
    int t = 1; // заданное число
    int n = sizeof(a) / sizeof(a[0]);

    findClosestSum(a, n, t);

    return 0;
}