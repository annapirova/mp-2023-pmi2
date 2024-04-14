#ifndef HEXS_H
#define HEXS_H

class hexs
{   private:
    double kg;
    double gramm;
    public:
    hexs();
    hexs(double zxc);
    void set(double zxc);
    void print_kg();
    void print_funtik();
    void print_pudink();
    hexs sum(const hexs &a);
};
#endif