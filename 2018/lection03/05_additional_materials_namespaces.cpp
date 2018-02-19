#include <cassert>

int x = 1;

namespace A {
    int x = 2;

    namespace B {
        int x = 3;
        
        // Функции в пространстве имён B
        int getX() { return ::x; };
        int getAX() { return ::A::x; };
        int getBX() { return x; };
    };
    
    // Функции в пространстве имён A
    int getX() { return ::x; };
    int getAX() { return x; };
    int getBX() { return B::x; };
}

// Функции в глобальном пространстве имён
int getX() { return x; };
int getAX() { return A::x; };
int getBX() { return A::B::x; };

int main() {

    // Проверяем, что функции эквивалентны
    assert(getX() == A::getX());
    assert(getX() == A::B::getX());
    
    assert(getAX() == A::getAX());
    assert(getAX() == A::B::getAX());
    
    assert(getBX() == A::getBX());
    assert(getBX() == A::B::getBX());

    return 0;
}
