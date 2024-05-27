#pragma once
#include <vector>
#include "Tovar.h"
#include "Magazin.h"

class Check {
private:
    std::vector<Tovar> p;
public:
    void AddTovar(const std::string& name, Magazin* m, int quantity);
    void PrintCheck();
    void SaveToFile(const std::string& filename);
};