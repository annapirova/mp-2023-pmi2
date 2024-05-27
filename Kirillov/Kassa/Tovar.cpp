#include "Tovar.h"

Tovar::Tovar(std::string n, int q, double p, double d) : name(n), quantity(q), price(p), discount(d) {
    total = q * p * (1 - d / 100);
}