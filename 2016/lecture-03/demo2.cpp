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
}

Tester::~Tester() {
    std::cout << "Tester destructor" << std::endl;
}

void Tester::describe() {
    std::cout << "I'm Tester [" << this->num << "]" << std::endl;
}


int main(int argc, char** argv) {

    std::cout << std::endl << "Tester Testing..." << std::endl;
    Tester * obj1 = new Tester(1);
    obj1->describe();
    delete obj1;

    std::cout << std::endl << "IBase Testing..." << std::endl;
    IBase * obj2 = new Tester(2);
    obj2->describe();
    delete obj2;

    return 0;
}
