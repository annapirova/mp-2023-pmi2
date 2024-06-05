#include "item.h"
Item::Item(const std::string& name, int price, int quantity) : m_name(name),
m_price(price),
m_quantity(quantity),
m_barcode(getHash(m_name))
{
};

Item::~Item() {}

int Item::getHash(const std::string& s) {
    int value = 0;
    for (auto x : s) {
        value = ((value + x) * 29791) % (1000000007);
    }
    return value;
}

int Item::getValue() const {
    return m_price * m_quantity;
}

void Item::add(int qty) {
    m_quantity += qty;
}

bool Item::operator== (const Item& Other) const
{
    if (m_barcode == Other.barcode()) {
        return true;
    }
    else {
        return false;
    }
}

bool Item::operator< (const Item& Other) const {
    return (getValue() < (Other.getValue()));
}

std::ostream& operator<<(std::ostream& os, const Item& A) {
    os << "name: " << A.m_name << "\n"
        << "barcode: " << A.m_barcode << "\n"
        << "quantity:" << A.m_quantity << "\n"
        << "value = " << A.getValue() << "\n";
    return os;
}
