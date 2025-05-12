#include <iostream>
#include <typeinfo> // Для использования typeid

using namespace std;

class A {
public:
    int a, b, c, d;
    A(int a, int b, int c, int d): a(a), b(b), c(c), d(d) {}
    // Раскомментируйте функцию и посмотрите, что станет с размером
    // virtual void f() {}
};

int main()
{
    A a(1, 2, 3, 4);
    cout << "a is "<< sizeof(a) << " bytes" << endl;
    cout << "type of a: " << typeid(a).name() << endl;

    for (int i = 0; i < sizeof(a) / 4; i++)
    {
        printf("%x ", *((uint32_t*)(&a) + i));
    }
    printf("\n");

    A *pa = &a;

    cout << "type of *pa: " << typeid(*pa).name() << endl;
    return 0;
}
