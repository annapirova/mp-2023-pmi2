#ifndef CHECK_H
#define CHECK_H
#include <vector>
#include "item.h"
class Check
{
private:
    std::vector<Item> goods;
public:
    void add(const std::string& name, const int& qty);
    void remove(const std::string& name);
    void print() const;
    Check();
    ~Check();
};
#endif // CHECK_H
