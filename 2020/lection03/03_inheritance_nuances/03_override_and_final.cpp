#include <iostream>

using namespace std;

/*
 * Этот пример специфичен для C++11.
 * Относительно старыми компиляторами даже не соберётся.
 * Специфичны только конкретно директивы override и final.
 * Сама иерархия классов без этих директив валидна и в C++98.
 */

// Абстрактный класс. Он же интерфейс.
class IBase {
public:
    // Виртуальный метод, будет реализован далее 
    virtual void describe() = 0;
};

// Первая реализация интерфейса
class ClassA : public IBase {
public:
    void describe() override final;
};

void ClassA::describe() {
    cout << "I'm ClassA implementation of IBase interface" << endl;
}

// Вторая реализация интерфейса
class ClassB final : public IBase {
public:
    void describe() override;
};

void ClassB::describe() {
    cout << "I'm ClassB implementation of IBase interface" << endl;
}

// Третья реализация интерфейса, наследуется от первой 
class ClassC : public ClassA {
public:
//    void describe() override; // Попытка перегрузки не пройдёт, так как функция final
};

//void ClassC::describe() {
//    cout << "I'm ClassC implementation of IBase interface" << endl;
//}

// Четвёртая реализация интерфейса, наследуется от второй (но так нельзя, так как она final)
//class ClassD : public ClassB {
//};


int main() {

    IBase* obj1 = new ClassA();
    IBase* obj2 = new ClassB();
    IBase* obj3 = new ClassC();
    //IBase* obj4 = new ClassD();

    //delete obj4;
    delete obj3;
    delete obj2;
    delete obj1;
    return 0;
}
