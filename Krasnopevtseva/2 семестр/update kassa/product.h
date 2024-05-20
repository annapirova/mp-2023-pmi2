#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
#include <string>
#include <vector>
#include <locale.h>
#include <sstream>
#include <algorithm>
using namespace std;
enum class category { pastries, tea, coffee, desserts, not_vailable };
class Product {
    int code, kol;
    double cost, discount;
    string name;
    category w;
public:
    Product(string s, int sh, double c, double d, int k, category x) : name(s), code(sh), cost(c), discount(d), kol(k), w(x) {};
    bool operator == (const Product& B) const
    {
        return code == B.code;
    }
    double finalcost() const
    {
        return (cost * kol / discount);
    }
    bool operator < (const Product& B)
    {
        return finalcost() < B.finalcost();
    }
    friend ostream& operator<<(ostream& os, const Product& item)
    {
        std::cout <<"Name: "<< item.name <<", Cost: "<< item.cost <<", Discount: "<< item.discount <<", Quantity: "<< item.kol <<", Barcode: "<< item.code;
        return os;
    }
    friend class Shop;
    friend class Check;
};

class Shop {
    std::vector <Product> sklad;
public:
    Shop() {
        sklad = {
        Product("crumpet", 1551, 49.99, 1.1, 10, category::pastries),
        Product("cheesecake", 3781, 199.99, 1.3, 2, category::desserts),
        Product("latte", 4001, 159.99, 1.15, 4, category::coffee),
        Product("oolong", 9808, 79.99, 1.00, 6, category::tea),
        };
    }
    void AddTovar(string s, int sh, double c, double d, int k, category x)
    {
        Product p(s, sh, c, d, k, x);
        sklad.push_back(p);
    }
    void ShowSklad() const {
        std::cout << "The range of products" << std::endl;
        for (const auto& item : sklad) {
            cout << item << "\n";
        }
    }
    Product FindTovar(string s)
    {
        auto it = std::find_if(sklad.begin(), sklad.end(), [&](const Product& item) {
            return item.name == s;
            });
        if (it != sklad.end()) {
            return (*it);
        }
        return Product("The product was not found", 0000, 0.0, 0.0, 0, category::not_vailable);
    }
    bool DeleteTovar(string s, int k)
    {
        for (auto& item : sklad) {
            if (item.name == s) {
                int howmuch = item.kol;
                item.kol -= k;
                if (item.kol < 0)
                {
                    item.kol = howmuch;
                    return 0;
                }
                else
                    return 1;
            }
        }
    }
    friend class Product;
};

class Check {
    std::vector <Product> finish;
    std::vector <Product> error;
public:
    void AddTovar(string s, int k, Shop* m)
    {
        auto it = std::find_if(finish.begin(), finish.end(), [&](const Product& item) {
            return item.name == s;
            });
        if (it != finish.end()) {
            (*it).kol += k;
        }
        else
        {
            Product t = m->FindTovar(s);
            bool x;
            t.kol = k;
            x = m->DeleteTovar(s, k);
            if (x)
                finish.push_back(t);
            else
                error.push_back(t);
        }
    }
    void GetOrder(Shop* m,string order)
    {
        std::string w;
        std::istringstream iss(order);
        std::vector <string> p, names;
        std::vector <int> kols;
        while (iss >> w)
        {
            std::cout << w << std::endl;
            if ((isalpha(w[0])))
            {
                Product t = m->FindTovar(w);
                if (t.name != "The product was not found")
                    names.push_back(w);
            }
            if ((isdigit(w[0])))
            {
                int k = stoi(w);
                if (k != 0)
                    kols.push_back(k);
            }
        }
        for (int i = 0; i < names.size(); i++)
        {
            this->AddTovar(names[i], kols[i], m);
        }
    }
    void SortCheck()
    {
        std::sort(finish.begin(), finish.end());
    }
    void ShowCheck() const
    {
        double summa = 0.0;
        double cost = 0.0;
        std::cout << "Scanned products:" << std::endl;
        for (const auto& item : finish) 
        {
            cost = item.finalcost();
            std::cout << item << ", Final cost: " << cost << std::endl;
            summa += cost;
        }
        if (error.size() != 0)
        {
            std::cout << "Failed to purchase items:" << endl;
            for (const auto& item : error) {

                std::cout << item << std::endl;
            }
        }
            std::cout << "Total: " << summa << std::endl;
    }
    friend class Product;
    friend class Shop;
};
#endif // PRODUCT_H
