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
        throw runtime_error("Oops in constructor");
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
    try {
        MyClass a;
        a.doSomeWork();
    } catch (const exception& e) {
        cerr << "We failed!" << endl; 
        cerr << "Failure reason: " << e.what() << endl;
        return -1;
    }
    return 0;
}
