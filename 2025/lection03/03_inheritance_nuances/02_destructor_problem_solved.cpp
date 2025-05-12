#include <iostream>
#include <cstdlib>

using namespace std;

// Базовый класс. Допустим, он интерфейс.
class IBase {
public:
    virtual ~IBase() {};
    // Виртуальный метод, будет реализован далее 
    virtual void describe() = 0;
};

// Реализация интерфейса
class TestClass : public IBase {
public:
    TestClass(int n);
    ~TestClass();
    void describe();
private:
    int* ptr;
};

// Конструктор, выделяет память
TestClass::TestClass(int n) {
    cout << "TestClass constructor" << endl;
    ptr = new int[n];
}

// Деструктор, освобождает память
TestClass::~TestClass() {
    cout << "TestClass destructor" << endl;
    delete[] ptr;
}

void TestClass::describe() {
    cout << "I'm TestClass implementation of IBase interface" << endl;
}


int main(int argc, char** argv) {

    // Так всё и было хорошо
    cout << "=== Test 1 ===" << endl;
    TestClass* obj1 = new TestClass(100);
    obj1->describe();
    delete obj1;

    // Теперь деструктор будет вызван и в этом случае тоже, всё стало ок
    cout << "=== Test 2 ===" << endl;
    IBase* obj2 = new TestClass(100);
    obj2->describe();
    delete obj2;

    return 0;
}
