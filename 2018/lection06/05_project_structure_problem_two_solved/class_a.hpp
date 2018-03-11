#ifndef CLASS_A_H
#define CLASS_A_H

class ClassA;

#include "class_b.hpp"
#include "class_c.hpp"

class ClassA
{
public:
    void doSomething(ClassC* c);
    void doSomething(ClassB* b);
};

#endif
