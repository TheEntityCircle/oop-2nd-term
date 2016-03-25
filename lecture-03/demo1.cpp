#include <iostream>

using namespace std;

class IBase {
public:
    virtual void run() = 0;
};

class ClassA : public IBase {
public:
    ClassA();
    ~ClassA();
    void run();
private:
};

ClassA::ClassA()
{
}

void ClassA::run()
{
    std::cout << "I'm class A" << std::endl;
}

class ClassB : public IBase {
public:
    ClassB();
    ~ClassB();
    void run();
private:
};

ClassB::ClassB()
{
}

void ClassB::run()
{
//    std::cout << "I'm class B" << std::endl;
}

int main()
{
    IBase* a[2];
    a[0] = new ClassA();
    a[1] = new ClassB();

    for(int i = 0; i < 2; i++)
        a[i]->run();
    return 0;
}
