#ifndef DOG_H
#define DOG_H

#include <iostream>

#include "animal.cpp"

using namespace std;

class Dog: public Animal { // <-- тут есть отсылка к Animal, давайте попробуем его include-ить
public:
    Dog() {
        cout << "Dog created" << endl;
    }

    void say() {
        cout << "Woof!" << endl;
    }
};

#endif
