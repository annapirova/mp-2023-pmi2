#include "massa.h"

Mass::Mass(int kilograms, int grams) : kilograms(kilograms), grams(grams) {}

void Mass::print() {
    std::cout << kilograms << " KG " << grams << " G" << std::endl;
}

Mass Mass::operator+(const Mass& m) {
    return Mass(kilograms + m.kilograms, grams + m.grams);
}

Mass Mass::operator-(const Mass& m) {
    return Mass(kilograms - m.kilograms, grams - m.grams);
}

bool Mass::operator==(const Mass& m) {
    return kilograms == m.kilograms && grams == m.grams;
}
