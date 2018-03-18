#include "class_a.hpp"

void ClassA::doSomething(ClassC* c)
{
    c->doGreatWork();
}

void ClassA::doSomething(ClassB* b)
{
    b->doGreatWork(this);
}
