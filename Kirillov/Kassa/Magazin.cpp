#include "Magazin.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

Magazin::Magazin() {}

void Magazin::AddTovar(const Tovar& t) {
    sklad.push_back(t);
}

Tovar* Magazin::FindTovar(const std::string& name) {
    for (Tovar& t : sklad) {
        if (t.name == name) {
            return &t;
        }
    }
    return nullptr;
}

void Magazin::PrintSklad() {
    for (const Tovar& t : sklad) {
        cout << "Name: " << t.name << ", Quantity: " << t.quantity << ", Price: " << t.price << ", Discount: " << t.discount << "%, Total: " << t.total << endl;
    }
}

void Magazin::LoadFromFile(const std::string& filename) {
    ifstream file(filename);
    string line;

    // ѕропуск первой строки с заголовком
    if (getline(file, line)) {
        if (line[0] == '#') {
            // ѕечатаем заголовок дл€ понимани€ пользователем, что загружаетс€ из файла
            cout << "Loading data with header: " << line << endl;
        }
    }

    while (getline(file, line)) {
        istringstream iss(line);
        string name;
        int quantity;
        double price;
        double discount;
        if (!(iss >> name >> quantity >> price >> discount)) { break; }
        AddTovar(Tovar(name, quantity, price, discount));
    }
}