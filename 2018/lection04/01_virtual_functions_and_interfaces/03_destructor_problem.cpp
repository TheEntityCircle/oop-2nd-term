#include <iostream>
#include <cstdlib>

using namespace std;

// Абстрактный класс. Он же интерфейс.
class IBase {
public:
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
    std::cout << "TestClass constructor" << std::endl;
    this->ptr = (int*)malloc(sizeof(int)*n); // не C++-ный дизайн, но оставим пока так
}

// Деструктор, освобождает память
TestClass::~TestClass() {
    std::cout << "TestClass destructor" << std::endl;
    free(this->ptr);
}

void TestClass::describe() {
    std::cout << "I'm TestClass implementation of IBase interface" << std::endl;
}


int main(int argc, char** argv) {

    // Так всё хорошо
    cout << "=== Test 1 ===" << endl;
    TestClass* obj1 = new TestClass(100);
    obj1->describe();
    delete obj1;

    // А вот так не будет вызван деструктор, что очень грустно
    cout << "=== Test 2 ===" << endl;
    IBase* obj2 = new TestClass(100);
    obj2->describe();
    delete obj2;

    return 0;
}
