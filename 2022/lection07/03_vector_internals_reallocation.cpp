#include <iostream>
#include <vector>

using namespace std;

class A
{
public:
    // Вставляем печать в вызовы:
    // - конструктора по умолчанию
    A() { cout << "Constructor" << endl; }
    // - деструктора
    ~A() { cout << "Destructor" << endl; }
    // - конструктора копирования
    A(const A& a) { cout << "Copy" << endl; }
};

int main()
{
    // Создаём объект
    cout << "== Create A ===" << endl;
    A a;
    // Создаём вектор
    cout << "=== Create V ===" << endl;
    vector<A> v;

    cout << "=== Using V ===" << endl;
    // Добавляем объекты в вектор,
    // смотрим за срабатыванием конструкторов
    cout << "Capacity: " << v.capacity() << endl;
    cout << "v.pushback()" << endl;
    v.push_back(a);
    A& ref = v[0];
    cout << "Capacity: " << v.capacity() << endl;
    cout << "v.pushback()" << endl;
    v.push_back(a);
    cout << "Capacity: " << v.capacity() << endl;

    // Смотрим на адреса
    cout << &ref << " vs. " << &v[0] << endl;

    return 0;
}
