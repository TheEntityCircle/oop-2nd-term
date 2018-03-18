class ClassC;

#include "class_c.hpp"
#include "pure_c_funcs.h"

ClassC::ClassC(int i)
{
    this->value = i;
}

int ClassC::doGreatWork()
{
    int tmp = calc_magic(this->value);
    return tmp * tmp;
}
