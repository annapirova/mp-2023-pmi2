#include <iostream>
#include <fstream>
#include <sstream>
#include "Magazin.h"
#include "Check.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    Magazin magnit;
    magnit.LoadFromFile("sklad.txt");

    cout << "Stock of goods:" << endl;
    magnit.PrintSklad();

    Check check;
    ifstream requests("requests.txt");
    string line;
    while (getline(requests, line)) {
        istringstream iss(line);
        string name;
        int quantity;
        if (!(iss >> name >> quantity)) { break; }
        check.AddTovar(name, &magnit, quantity);
    }

    cout << "Receipt:" << endl;
    check.PrintCheck();
    check.SaveToFile("check.txt");

    cout << "Stock of goods after purchase:" << endl;
    magnit.PrintSklad();

    return 0;
}