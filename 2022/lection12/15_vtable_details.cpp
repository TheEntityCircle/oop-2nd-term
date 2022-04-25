// Этот пример стоит собирать с ключом -fdump-class-hierarchy
// И внимательно посмотреть на вывод этой сборки.

#include <iostream>

using namespace std;

typedef struct
{
    int a;
    int b;
    int c;
} test_struct;

class TestClass
{
protected:
    int a;
    int b;
    int c;
public:
    TestClass() { }
    virtual ~TestClass() { }
    virtual int getA() { return a; }
    virtual int getB() { return b; }
    virtual int getC() { return c; }
};

class DerivedClass: protected TestClass
{
protected:
    int d;
    int e;
    int f;
public:
    DerivedClass() { }
    ~DerivedClass() { }
    int getA() { return a; }
    int getD() { return d; }
    int getE() { return e; }
    int getF() { return f; }
};

int main()
{
    cout << "struct: " << sizeof(test_struct) << endl;
    cout << "base class: " << sizeof(TestClass) << endl;
    cout << "derived class: " << sizeof(DerivedClass) << endl;
    return 0;
}
