#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <iostream>

class Item
{
private:
    std::string m_name;
    int m_price;
    int m_barcode;
    int m_quantity;
    static int getHash(const std::string& s);
public:
    Item(const std::string& name, int price, int quantity);
    inline int barcode() const { return m_barcode; }
    inline std::string getName() const { return m_name; }
    int getBarcode() const { return m_barcode; }
    int getValue() const;
    void add(int qty);
    ~Item();
    bool operator== (const Item& Other) const;
    bool operator< (const Item& Other) const;
    friend std::ostream& operator<< (std::ostream& os, const Item& A);
};
#endif // ITEM_H
