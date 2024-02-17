#include <iostream>

// Явное включение только std::cout и std::endl в глобальное пространство имён
using std::cout;
using std::endl;

// При желании можно построить иерархию из вложенных пространств имён
namespace A {
    void hello() { cout << "A::Hello" << endl; }

    namespace B {
        void hello() { cout << "A::B::Hello" << endl; }
    }
}

namespace C {
    void hello() { cout << "C::Hello" << endl; }
}

// Включение всего пространства имён A в глобальное пространство имён
//using namespace A;

int main() {
    // Вызов функций с явным указанием полного пути по пространствам имён
    A::hello();
    A::B::hello();
    C::hello();

    // Это можно использовать после включения A в глобальное пространство имён
    //hello();
    //B::hello();

    return 0;
}
