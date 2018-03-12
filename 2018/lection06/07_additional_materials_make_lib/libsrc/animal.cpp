#include <iostream>
#include "animal.hpp"

using std::cout;
using std::endl;

Animal::Animal()
{
    cout << "Animal created" << endl;
    this->brain = true;
}

bool Animal::hasBrain() {
    return brain;
}
