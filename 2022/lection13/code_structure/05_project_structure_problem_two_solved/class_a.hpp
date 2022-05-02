#ifndef CLASS_A_H
#define CLASS_A_H

/* Это header для ClassA - здесь только объявление методов, но не реализация */

// Наш ClassA захочет работать с ClassB

// Можно попробовать вот так (и это не сработает, но посмотреть на это стоит)
//#include "class_b.hpp"

// А можно просто сказать, что ClassB будет предъявлен потом.
// Так можно, потому что здесь, в header-е, мы не пробуем ничего вызывать из ClassB.
class ClassB;

class ClassA
{
public:
    // Получаем ClassB, хотим с ним что-то сделать
    void doSomething(ClassB* b);

    // А это просто метод у нашего ClassA
    void describeSelf();
};

#endif
