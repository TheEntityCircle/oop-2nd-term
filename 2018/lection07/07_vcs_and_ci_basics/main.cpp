#include <iostream>
#include "dice.hpp"

using std::cout;
using std::endl;

int main()
{
    Dice d2(2);
    Dice d6(6);
    cout << d2.roll() << endl;
    cout << d6.roll() << endl;
    return 0;
}
