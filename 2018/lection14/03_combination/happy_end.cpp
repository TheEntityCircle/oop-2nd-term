#include <iostream>
#include <memory>
#include <stdexcept>

using namespace std;

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
        for(int i = 0; i < 10; i++)
            cout << data[i] << endl;
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
