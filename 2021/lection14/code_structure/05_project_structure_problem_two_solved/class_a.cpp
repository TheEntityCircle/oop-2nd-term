// Это .cpp - файл реализации. Именно он и только он компилируется.
// Здесь нет условной компиляции, потому что этот файл не include-ится.

// Свой (!) header
#include "class_a.hpp"

// И header-ы того, что будем использовать
#include "class_b.hpp"
#include <iostream>

/* Реализация всего, что объявлено в header-е */

void ClassA::doSomething(ClassB* b) {
    b->describeSelf();
}

void ClassA::describeSelf() {
    std::cout << "I'm class A" << std::endl;
}
