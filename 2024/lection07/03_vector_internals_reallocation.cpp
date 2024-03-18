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
    // Создаём вектор
    cout << "=== Create V ===" << endl;
    vector<A> v(10);
    // resize создает новые элементы
    // v.resize(20);
    // reserve меняет capacity (с переездом)
    // v.reserve(20);

    cout << "=== Using V ===" << endl;
    // Сохранили ссылку на нулевой элемент.
    A& ref = v[0];
    // Добавляем объекты в вектор,
    // смотрим за срабатыванием конструкторов
    cout << "Capacity: " << v.capacity() << endl;
    cout << "v.pushback()" << endl;
    v.push_back(A());
    cout << "Capacity: " << v.capacity() << endl;
    cout << "v.pushback()" << endl;
    v.push_back(A());
    cout << "Capacity: " << v.capacity() << endl;

    // Смотрим на адреса
    cout << &ref << " vs. " << &v[0] << endl;

    return 0;
}
