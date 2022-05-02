// Это .cpp - файл реализации. Именно он и только он компилируется.
// Здесь нет условной компиляции, потому что этот файл не include-ится.

// Свой (!) header
#include "class_b.hpp"

// И header-ы того, что будем использовать
#include "class_a.hpp"
#include <iostream>

/* Реализация всего, что объявлено в header-е */

void ClassB::doSomething(ClassA* a) {
    a->describeSelf();
}

void ClassB::describeSelf() {
    std::cout << "I'm class B" << std::endl;
}
