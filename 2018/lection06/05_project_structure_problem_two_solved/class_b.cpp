#include <iostream>

class ClassB;

#include "class_b.hpp"

void ClassB::doGreatWork(ClassA* a)
{
    std::cout << a << std::endl;
}
