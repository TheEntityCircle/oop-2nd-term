#include <iostream>
#include <vector>

using namespace std;

class A
{
    public:
        A() { cout << "Constructor" << endl; };
        ~A() { cout << "Destructor" << endl; };
        A(const A& a) { cout << "Copy" << endl; };
};

int main()
{
    // Создаём объект
    cout << "Create A" << endl;
    A a;
    // Создаём вектор
    cout << "Create V" << endl;
    vector<A> v;

    // Добавляем объекты в вектор
    cout << "Capacity: " << v.capacity() << endl;
    cout << "v.pushback()" << endl;
    v.push_back(a);
    A& ref = v[0];
    cout << "Capacity: " << v.capacity() << endl;
    cout << "v.pushback()" << endl;
    v.push_back(a);
    cout << "Capacity: " << v.capacity() << endl;

    cout << &ref << " vs. " << &v[0] << endl;

    return 0;
}
