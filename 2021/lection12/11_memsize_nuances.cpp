#include <iostream>

using namespace std;

typedef struct
{
    char a;
    char a2;
    int b;
    int c;
} test_struct;

class TestClass
{
protected:
    char a;
    char a2;
    int b;
    int c;
public:
    TestClass() { }
    ~TestClass() { }
    char getA() { return a; }
    int getB() { return b; }
    int getC() { return c; }
};

class DerivedClass: protected TestClass
{
protected:
    static int d;
public:
    int getD() { return d; }
};

int main()
{
    cout << "struct: " << sizeof(test_struct) << endl;
    cout << "base class: " << sizeof(TestClass) << endl;
    cout << "derived class: " << sizeof(DerivedClass) << endl;
    return 0;
}
