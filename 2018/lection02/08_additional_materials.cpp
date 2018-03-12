#include <iostream>
#include <vector>

using namespace std;

class TestClassA
{
public:
    TestClassA() {
        cout << "ClassA simple constructor called" << endl;
    }

    TestClassA(int n) {
        cout << "ClassA complex constructor called" << endl;
        for(int i = 0; i < n; i++)
        {
            TestClassA tmp;
        }
    }

    ~TestClassA() {
        cout << "ClassA destructor called" << endl;
    }
};


class TestClassB
{
private:
    vector<TestClassB*> children;
public:
    TestClassB() {
        cout << "ClassB simple constructor called" << endl;
    }

    TestClassB(int n) {
        cout << "ClassB complex constructor called" << endl;
        for(int i = 0; i < n; i++)
        {
            children.push_back(new TestClassB());
        }
    }

    ~TestClassB() {
        cout << "ClassB destructor called" << endl;
        for(unsigned int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};

int main()
{
    //TestClassA pa(2);
    //TestClassB pb(2);
    return 0;
}
