#include <cassert>
#include <iostream>

using namespace std;

int main()
{
    cout << "starting main" << endl;
    int a = 5, b = 10;
    static_assert(2 == 2);
    cout << "passed first assert" << endl;
    static_assert(5 == 6);
    cout << "passed second assert" << endl;
    return 0;
}
