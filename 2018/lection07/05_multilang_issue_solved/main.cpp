#include <iostream>
#include "class_c.hpp"

using namespace std;

int main()
{
    ClassC c(8);
    cout << "Result = " << c.doGreatWork() << endl;
    return 0;
}
