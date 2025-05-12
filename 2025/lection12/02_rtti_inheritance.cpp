#include <iostream>
#include <typeinfo> // Для использования typeid

#include <cstdlib> // Для рандома из С
#include <ctime>

using namespace std;

class A {
public:
    int a, b, c, d;
    A(int a, int b, int c, int d): a(a), b(b), c(c), d(d) {}
    virtual void f() { cout << "f from A" << endl; }
};

class B : public A {
public:
    int e, g;
    B(int a, int b, int c, int d, int e, int g): A(a, b, c, d), e(e), g(g) {}
    virtual void f() override { cout << "f from B" << endl;} 
};

int main()
{
    A a(1, 2, 3, 4);
    B b(5, 6, 7, 8, 9, 0);
    cout << "a is "<< sizeof(a) << " bytes" << endl;
    cout << "b is "<< sizeof(b) << " bytes" << endl;
    cout << "type of a:   " << typeid(a).name() << endl;
    cout << "type of b:   " << typeid(b).name() << endl;

    printf("a contains:   ");
    for (int i = 0; i < sizeof(a) / 4; i++)
    {
        printf("%x ", *((uint32_t*)(&a) + i));
    }
    printf("\n");

    // Это можно раскомментировать, чтобы посмотреть
    // на этот загадочный адрес у разных переменных
    // одного типа
    /*
    A a(11, 22, 33, 44), aaa(111, 222, 333, 444)
    printf("aa contains:  ");
    for (int i = 0; i < sizeof(aa) / 4; i++)
    {
        printf("%x ", *((uint32_t*)(&aa) + i));
    }
    printf("\n");
    printf("aaa contains: ");
    for (int i = 0; i < sizeof(aaa) / 4; i++)
    {
        printf("%x ", *((uint32_t*)(&aaa) + i));
    }
    printf("\n");
    */

    printf("b contains:   ");
    for (int i = 0; i < sizeof(b) / 4; i++)
    {
        printf("%x ", *((uint32_t*)(&b) + i));
    }
    printf("\n");

    // Кладем в pa адрес либо а, либо b
    srand(time(NULL));
    A *pa = rand() % 2 ? &a : &b; 
    
    pa->f();
    cout << "type of *pa: " << typeid(*pa).name() << endl;
    return 0;
}
