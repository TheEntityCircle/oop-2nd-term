#include <stdio.h>

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
    int getA() { return a; }
    int getB() { return b; }
    int getC() { return c; }
};

class DerivedClass: protected TestClass
{
protected:
    int d;
    int e;
    int f;
public:
    int getD() { return d; }
    int getE() { return e; }
    int getF() { return f; }
};

int main()
{
    printf("struct: %d\n", sizeof(test_struct));
    printf("base class: %d\n", sizeof(TestClass));
    printf("derived class: %d\n", sizeof(DerivedClass));
    return 0;
}
