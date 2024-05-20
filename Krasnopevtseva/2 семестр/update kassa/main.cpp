#include <iostream>
#include <locale.h>
#include "product.h"
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

int main()
{
    setlocale(LC_CTYPE, "Russian");
    Shop Super;
    Check ch1;
    Super.AddTovar("Donut", 1632, 29.99, 1.00, 5, category::pastries);
    std::cout << "Welcome to our cafe! <3 " << std::endl;
    Super.ShowSklad();
    std::cout << "Enter your order:" << std::endl;
    const char* filename = "Order.txt";
    std::ifstream file;
    file.open(filename);
    std::string tmp;
    while(getline(file,tmp))
    ch1.GetOrder(&Super,tmp);
    file.close();
    ch1.SortCheck();
    ch1.ShowCheck();
    return 0;
}