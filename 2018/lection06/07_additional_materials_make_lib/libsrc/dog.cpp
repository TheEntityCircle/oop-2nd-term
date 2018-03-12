#include <iostream>
#include "dog.hpp"

using std::cout;
using std::endl;

Dog::Dog()
{
    cout << "Dog created" << endl;
}

void Dog::say() {
    cout << "Woof!" << endl;
}
