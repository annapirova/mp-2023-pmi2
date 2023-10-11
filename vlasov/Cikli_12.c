#include <stdio.h>
#include <math.h>

int main() {
    int x, y;
    int r1, r2;
    int count = 0;

    printf(" (x, y): ");
    scanf_s("%d%d", &x, &y);

    printf(" r1 and r2: ");
    scanf_s("%d%d", &r1, &r2);
    int minX = x - r2;
    int maxX = x + r2;
    int minY = y - r2;
    int maxY = y + r2;

    for (int i = minX; i <= maxX; i++) {
        for (int j = minY; j <= maxY; j++) {
            double distance = sqrt(pow(x - i, 2) + pow(y - j, 2));
            if (distance >= r1 && distance <= r2) {
                count++;
            }
        }
    }

    printf("Count : %d\n", count);

    return 0;
}