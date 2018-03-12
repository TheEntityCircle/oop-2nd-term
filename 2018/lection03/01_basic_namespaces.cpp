#include <iostream>

// Переменные и функции в глобальном пространстве имён
int x = 1;
int doSomeWork();

namespace A {
    // Переменные и функции в пространстве имён A
    int x = 2;
    int doSomeWork();
}

// Реализация функций
int doSomeWork() {
    return x;
}

int A::doSomeWork() {
    return x;
}

int main() {
    std::cout << "global call: " << doSomeWork() << std::endl;
    std::cout << "namespaced call: " << A::doSomeWork() << std::endl;
    return 0;
}
