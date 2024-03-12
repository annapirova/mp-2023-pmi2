#include "hexs.h"
#include <iostream>

hexs::hexs()
{
    kg=gramm=0;
}
hexs:: hexs(double zxc)
{
    kg=floor(zxc);
    gramm=(zxc-kg)*1000;
}
void hexs:: set (double zxc)
{
    kg=floor(zxc);
    gramm=(zxc-kg)*1000;
}   
void hexs::print_kg ()
{
    std::cout<<"kg: "<<this->kg<<std::endl<<"gramm: "<<this->gramm<<std::endl;
}
void hexs::print_funtik ()
{
    double funt=(1000*kg+gramm)/453.592;
    std::cout<<"Funt: "<<funt<<std::endl;
}
void hexs::print_pudink ()
{
    double pud=(kg+gramm/1000)/16.3807;
    std::cout<<"Pud: "<<pud<<std::endl;
}
hexs hexs::sum(const hexs &a)
{
    hexs zxc;
    zxc.kg=this->kg+a.kg;
    zxc.gramm=this->gramm+a.gramm;
    return zxc;
}
