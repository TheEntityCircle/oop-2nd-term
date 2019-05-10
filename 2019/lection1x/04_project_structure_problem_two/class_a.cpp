#ifndef CLASS_A_H
#define CLASS_A_H

#include "class_b.cpp"

class ClassA
{
public:
//    void doSomething(ClassC* c);
    void doSomething(ClassB* b);
};
/*
void ClassA::doSomething(ClassC* c)
{
    c->doGreatWork();
}
*/
void ClassA::doSomething(ClassB* b)
{
    b->doGreatWork(this);
}

#endif
