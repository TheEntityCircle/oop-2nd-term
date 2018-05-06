#include <iostream>
#include <stdexcept>

using namespace std;

// Так не надо делать
// Ремарка: отдельно стоит посмотреть на это под valgrind-ом

class MyClass
{
protected:
    int* data;
public:
    MyClass()
    {
        cout << "MyClass constructor called" << endl;
        data = new int[1000];
    }

    ~MyClass()
    {
        cout << "MyClass destructor called" << endl;
        delete[] data;
    }

    void doSomeWork()
    {
        cout << "Ooops happened" << endl;
        throw runtime_error("Oops");
    }
};

int main()
{
    MyClass a;
    a.doSomeWork();
    return 0;
}
