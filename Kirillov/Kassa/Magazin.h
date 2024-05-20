#pragma once
#include <vector>
#include "Tovar.h"

class Magazin {
private:
    std::vector<Tovar> sklad;
public:
    Magazin();
    void AddTovar(const Tovar& t);
    Tovar* FindTovar(const std::string& name);
    void PrintSklad();
    void LoadFromFile(const std::string& filename);
};