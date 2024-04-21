#include <cassert>
#include <iostream>

using namespace std;

int main()
{
    cout << "starting main" << endl;
    int a = 5, b = 10;
    assert(b / a == 2);
    cout << "passed first assert" << endl;
    assert(a == 6);
    cout << "passed second assert" << endl;
    return 0;
}
