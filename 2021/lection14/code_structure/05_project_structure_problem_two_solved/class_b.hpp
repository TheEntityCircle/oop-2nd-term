#ifndef CLASS_B_H
#define CLASS_B_H

/* Это header для ClassB - здесь только объявление методов, но не реализация */

// Наш ClassB захочет работать с ClassA

// Можно попробовать вот так (и это не сработает, но посмотреть на это стоит)
//#include "class_a.hpp"

// А можно просто сказать, что ClassA будет предъявлен потом.
// Так можно, потому что здесь, в header-е, мы не пробуем ничего вызывать из ClassA.
class ClassA;

class ClassB
{
public:
    // Получаем ClassA, хотим с ним что-то сделать
    void doSomething(ClassA* a);

    // А это просто метод у нашего ClassB
    void describeSelf();
};

#endif
