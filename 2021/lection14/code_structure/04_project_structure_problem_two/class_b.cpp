#ifndef CLASS_B_H
#define CLASS_B_H

// Наш ClassB захочет работать с ClassA, придётся его include-ить
#include "class_a.cpp"

class ClassB
{
public:
    // Получаем ClassA, хотим с ним что-то сделать
    void doSomething(ClassA* a) {
        a->describeSelf();
    }

    // А это просто метод у нашего ClassB
    void describeSelf() { }
};

#endif
