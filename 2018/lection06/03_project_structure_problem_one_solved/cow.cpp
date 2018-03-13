#ifndef COW_H
#define COW_H

#include <iostream>

#include "animal.cpp"

using namespace std;

class Cow: public Animal { // <-- но тут есть отсылка к Animal, давайте попробуем его include-ить
public:
    Cow() {
        cout << "Cow created" << endl;
    }

    void say() {
        cout << "Moo" << endl;
    }
};

#endif
