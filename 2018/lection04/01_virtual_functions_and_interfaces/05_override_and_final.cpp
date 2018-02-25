#include <iostream>

using namespace std;

// Абстрактный класс. Он же интерфейс.
class IBase {
public:
    // Виртуальный метод, будет реализован далее 
    virtual void describe() = 0;
    //void describe(); // Заготовка для демо
    // Виртуальный деструктор
    virtual ~IBase();
};

IBase::~IBase() {
}

// Первая реализация интерфейса
class ClassA : public IBase {
public:
    ClassA();
    ~ClassA();
    void describe() override final;
};

ClassA::ClassA() {
    std::cout << "ClassA constructor" << std::endl;
}

ClassA::~ClassA() {
}

void ClassA::describe() {
    std::cout << "I'm ClassA implementation of IBase interface" << std::endl;
}

// Вторая реализация интерфейса
class ClassB final : public IBase {
public:
    ClassB();
    ~ClassB();
    void describe() override;
};

ClassB::ClassB() {
    std::cout << "ClassB constructor" << std::endl;
}

ClassB::~ClassB() {
}

void ClassB::describe() {
    std::cout << "I'm ClassB implementation of IBase interface" << std::endl;
}

// Третья реализация интерфейса, наследуется от первой 
class ClassC : public ClassA {
public:
    //void describe() override; // Попытка перегрузки не пройдёт, так как функция final
};

//void ClassC::describe() {
//    std::cout << "I'm ClassC implementation of IBase interface" << std::endl;
//}

// Четвёртая реализация интерфейса, наследуется от второй (но так нельзя, так как она final)
//class ClassD : public ClassB {
//};


int main(int argc, char** argv) {

    IBase* obj1 = new ClassA();
    IBase* obj2 = new ClassB();
    IBase* obj3 = new ClassC();
    //IBase* obj4 = new ClassD();

    return 0;
}
