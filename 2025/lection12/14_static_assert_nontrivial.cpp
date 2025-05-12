#include <cassert>
#include <iostream>

using namespace std;

class A {
public:
    virtual void f() = 0;
};

class B {
public:
    // Если раскомментировать, то упадет на третьем static_assert
    // int a;
    void print() {cout << "brrrr" << endl;}
};

int main()
{
    cout << "starting main" << endl;
    int a = 5, b = 10;
    static_assert(is_signed<int>());
    static_assert(is_abstract<A>());
    static_assert(is_empty<B>());
    return 0;
}
