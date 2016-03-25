#include <iostream>

using namespace std;

class IBase {
public:
    virtual void describe() = 0; // pure virtual method
    virtual ~IBase();
};

IBase::~IBase() {}

class Tester : public IBase {
public:
    Tester(int n);
    ~Tester();
    void describe();
private:
    int num;
};

Tester::Tester(int n) {
    std::cout << "Tester constructor" << std::endl;
    this->num = n;
};

Tester::~Tester() {
    std::cout << "Tester destructor" << std::endl;
};

void Tester::describe() {
    std::cout << "I'm Tester [" << this->num << "]" << std::endl;
};


class Child : public Tester {
public:
    Child();
    ~Child();
    void describe();
};

Child::Child() : Tester::Tester(-1)
{
    std::cout << "Child constructor" << std::endl;
};

Child::~Child()
{
    std::cout << "Child destructor" << std::endl;
};

void Child::describe()
{
    std::cout << "I'm child" << std::endl;
    std::cout << "My parent thinks: " << std::endl;
    Tester::describe();
};

int main(int argc, char** argv) {

    std::cout << std::endl << "Tester Testing..." << std::endl;
    Tester * obj1 = new Tester(1);
    obj1->describe();
    delete obj1;

    std::cout << std::endl << "IBase Testing..." << std::endl;
    IBase * obj2 = new Tester(2);
    obj2->describe();
    delete obj2;

    std::cout << std::endl << "Child testing..." << std::endl;
    IBase * obj3 = new Child();
    obj3->describe();
    delete obj3;

    return 0;
}
