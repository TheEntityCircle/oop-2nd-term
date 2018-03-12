#include <iostream>
#include "cow.hpp"

using std::cout;
using std::endl;

Cow::Cow()
{
    cout << "Cow created" << endl;
}

void Cow::say()
{
    cout << "Moo" << endl;
}
