#include "massa.h"

int main() {
    Mass mass1(1, 500);
    Mass mass2(2, 300);

    Mass mass3 = mass1 + mass2;
    mass3.print(); // Выведет: 3 кг 800 г

    Mass mass4 = mass1 - mass2;
    mass4.print(); // Выведет: -1 кг 200 г

    std::cout << (mass1 == mass2) << std::endl; // Выведет: false
    std::cout << (mass1 == mass3) << std::endl; // Выведет: false

    return 0;
}
