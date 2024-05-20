#pragma once
#include <string>

class Tovar {
public:
    std::string name;
    int quantity;
    double price;
    double total;
    double discount;

    Tovar(std::string n, int q, double p, double d = 0.0);
};