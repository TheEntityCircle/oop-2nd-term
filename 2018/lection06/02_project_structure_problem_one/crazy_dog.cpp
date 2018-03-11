#include <iostream>

#include "dog.cpp"

using namespace std;

class CrazyDog: public Dog {
public:
    CrazyDog() {
        this->brain = false;
        cout << "Dog gone crazy" << endl;
    }

    void say() {
        cout << "Woof! Woof! Woof! Woof! Woof!" << endl;
    }
};
