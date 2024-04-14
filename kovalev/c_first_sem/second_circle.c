#include "stdio.h"
#include "math.h"
#include "locale.h"

int main() {
    setlocale(LC_CTYPE, "Russian");
    double x, y, r1, r2;
    int count = 0;
    printf("Введите координаты центра (x, y): ");
    scanf("%lf %lf", &x, &y);
    printf("Введите радиусы r1 и r2: ");
    scanf("%lf %lf", &r1, &r2);
    for (int i =(int)(x - r2); i <= x + r2; i++) {
        for (int j =(int)(y - r2); j <= y + r2; j++) {
            double distance = sqrt(pow(i - x, 2) + pow(j - y, 2));
            if (distance >= r1 && distance <= r2) {
                count++;
            }
        }
    }
    printf("Количество точек внутри кольца: %d\n", count);

    return 0;
}