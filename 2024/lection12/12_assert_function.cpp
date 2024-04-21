#include <cassert>
#include <iostream>

using namespace std;

void h()
{
    assert(false);
}

void g()
{
    h();
}

void f()
{
    g();
}

int main()
{
    cout << "starting main" << endl;
    int a = 5, b = 10;
    assert(b / a == 2);
    cout << "passed first assert" << endl;
    f(); 
    cout << "passed second assert" << endl;
    return 0;
}
