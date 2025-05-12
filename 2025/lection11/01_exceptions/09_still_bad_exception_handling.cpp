#include <iostream>
#include <stdexcept>

using namespace std;

// Так уже лучше. 
// Но проблемы ещё есть, см. следующий пример.

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

void imposter()
{
    MyClass a;
    a.doSomeWork();
}

int main()
{
    try {
        imposter();
    } catch (const exception& e) {
        cerr << "We failed!" << endl; 
        cerr << "Failure reason: " << e.what() << endl;
        return -1;
    }
    return 0;
}
