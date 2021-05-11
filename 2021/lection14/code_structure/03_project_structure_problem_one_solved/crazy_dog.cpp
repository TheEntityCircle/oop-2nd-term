#ifndef CRAZY_DOG_H
#define CRAZY_DOG_H

#include <iostream>

#include "dog.cpp"

using namespace std;

class CrazyDog: public Dog {  // <-- а тут отсылка к Dog, давайте include-ить уже его
public:
    CrazyDog() {
        this->brain = false;
        cout << "Dog gone crazy" << endl;
    }

    void say() {
        cout << "Woof! Woof! Woof! Woof! Woof!" << endl;
    }
};

#endif
