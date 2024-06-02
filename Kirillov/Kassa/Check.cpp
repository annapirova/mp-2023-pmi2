#include "Check.h"
#include <iostream>
#include <fstream>

using namespace std;

void Check::AddTovar(const std::string& name, Magazin* m, int quantity) {
    Tovar* t = m->FindTovar(name);
    if (t != nullptr && t->quantity >= quantity) {
        int index = FindCheckTovar(name);
        if (index == -1) {
            p.push_back(Tovar(t->name, quantity, t->price, t->discount));
            t->quantity -= quantity;
        }
        else {
            p[index].quantity += quantity;
            t->quantity -= quantity;
        }
    }
    else {
        cout << "Item not found or insufficient quantity in stock" << endl;
    }
}

int Check::FindCheckTovar(const std::string& name) {
    for (int i = 0; i < p.size(); i++) {
        if (p[i].name == name) {
            return i;
        }
    }
    return -1; // возвращаем -1, если товар не найден
}
void Check::PrintCheck() {
    double totalAmount = 0.0;
    for (const Tovar& t : p) {
        cout << "Name: " << t.name << ", Quantity: " << t.quantity << ", Price: " << t.price << ", Discount: " << t.discount << "%, Total: " << t.total << endl;
        totalAmount += t.total;
    }
    cout << "Total Amount: " << totalAmount << endl;
}

void Check::SaveToFile(const std::string& filename) {
    ofstream file(filename);
    double totalAmount = 0.0;
    for (const Tovar& t : p) {
        file << "Name: " << t.name << ", Quantity: " << t.quantity << ", Price: " << t.price << ", Discount: " << t.discount << "%, Total: " << t.total << endl;
        totalAmount += t.total;
    }
    file << "Total Amount: " << totalAmount << endl;
}