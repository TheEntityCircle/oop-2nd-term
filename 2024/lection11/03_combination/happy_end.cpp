#include <iostream>
#include <memory>
#include <stdexcept>

using namespace std;

// Вот теперь правда хорошее решение.

// Smart pointer-ы появились в C++11.
// Более старые компиляторы это не соберут.

class MyClass
{
protected:
    unique_ptr<int[]> data;
public:
    MyClass()
    {
        cout << "MyClass constructor called" << endl;
        data = unique_ptr<int[]>(new int[1000]);
        throw runtime_error("Oops in constructor");
    }

    ~MyClass()
    {
        cout << "MyClass destructor called" << endl;
        // Этот вызов больше не нужен
        // delete[] data;
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
