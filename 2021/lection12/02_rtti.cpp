#include <iostream>
#include <typeinfo> // Для использования typeid

using namespace std;

int main()
{
    // Объявляем переменные с автоматическим выведением типа
    auto i1 = 1;
    auto i2 = 1l;
    auto i3 = 1ll;
    auto _c = 'a';
    auto f1 = 1.0;
    auto f2 = 1.0l;
    auto f3 = 1.0f;
    auto s1 = "AZAZA";

    // Выводим тип переменных
    // Часть компиляторов выдаёт сразу читаемые типы
    // Для остальных можно сделать c++filt -t <нечитаемое_имя>
    cout << "type of i1: " << typeid(i1).name() << endl;
    cout << "type of i2: " << typeid(i2).name() << endl;
    cout << "type of i3: " << typeid(i3).name() << endl;
    
    cout << "type of _c: " << typeid(_c).name() << endl;
    
    cout << "type of f1: " << typeid(f1).name() << endl;
    cout << "type of f2: " << typeid(f2).name() << endl;
    cout << "type of f3: " << typeid(f3).name() << endl;

    cout << "type of s1: " << typeid(s1).name() << endl;

    return 0;
}
