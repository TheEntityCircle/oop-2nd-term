#include <iostream>
#include "crazy_dog.hpp"

using std::cout;
using std::endl;

CrazyDog::CrazyDog()
{
    this->brain = false;
    cout << "Dog gone crazy" << endl;
}

void CrazyDog::say() {
    cout << "Woof! Woof! Woof! Woof! Woof!" << endl;
}
