#ifndef CLASS_A_H
#define CLASS_A_H

// Наш ClassA захочет работать с ClassB, придётся его include-ить
#include "class_b.cpp"

class ClassA
{
public:
    // Получаем ClassB, хотим с ним что-то сделать
    void doSomething(ClassB* b) {
        b->describeSelf();
    }

    // А это просто метод у нашего ClassA
    void describeSelf() { }
};

#endif
