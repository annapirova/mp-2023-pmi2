#include <stdio.h>
#include <locale.h>
#include <math.h>

void findUniqueAndAverageObjects(int data[5][5]) {
    int uniqueCount = 0;
    int averageCount = 0;

    for (int i = 0; i < 5; i++) {
        int maxVal = data[i][0];
        int minVal = data[i][0];
        int sum = data[i][0];

        for (int j = 1; j < 5; j++) {
            if (data[i][j] > maxVal) {
                maxVal = data[i][j];
            }
            if (data[i][j] < minVal) {
                minVal = data[i][j];
            }
            sum += data[i][j];
        }

        
        int averageVal = sum / 5;
        int closeToAverageCount = 0;

        for (int j = 0; j < 5; j++) {
            if (fabs(data[i][j] - averageVal)<2) {
                closeToAverageCount++;
            }
        }

        
        if (closeToAverageCount == 5) {
            printf("Объект %d является усредненным\n", i + 1);
            averageCount++;
        }
        else if (closeToAverageCount > 2 || (minVal == maxVal && minVal != averageVal)) {
            printf("Объект %d является уникальным\n", i + 1);
            uniqueCount++;
        }
    }

    
    if (uniqueCount == 0) {
        printf("Уникальных объектов не найдено.\n");
    }

    if (averageCount == 0) {
        printf("Усредненных объектов не найдено.\n");
    }
}

int main() {
    setlocale(LC_ALL, "Rus");
    int data[5][5] = {
        {10, 20, 30, 40, 50},
        {50, 40, 30, 20, 10},
        {25, 25, 25, 25, 25},
        {5, 5, 50, 50, 50},
        {15, 15, 15, 15, 15}
    };

    findUniqueAndAverageObjects(data);

    return 0;
}