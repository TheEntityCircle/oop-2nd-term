#ifndef DOG_H
#define DOG_H

#include <iostream>

#include "animal.cpp"

using namespace std;

class Dog: public Animal {
public:
    Dog() {
        cout << "Dog created" << endl;
    }

    void say() {
        cout << "Woof!" << endl;
    }
};

#endif
