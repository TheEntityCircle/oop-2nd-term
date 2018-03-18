#ifndef CLASS_B_H
#define CLASS_B_H

#include <iostream>

#include "class_a.cpp"

class ClassB
{
public:
    void doGreatWork(ClassA* a);
};

void ClassB::doGreatWork(ClassA* a)
{
    std::cout << a << std::endl;
}

#endif
