#include <iostream>
#include <typeinfo>

using namespace std;

int main()
{
    auto s = string("AZAZA");

    cout << "type of s: " << typeid(s).name() << endl;

    return 0;
}
