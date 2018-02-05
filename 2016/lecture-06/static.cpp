#include <iostream>

using namespace std;

class A
{
    public:
        // Нестатическое поле
        int non_static_int = 0;
        // Статическое поле
        static int static_int;

        static int static_method()
        {
            return static_int;
            // Ошибка: статический метод может использовать только статические поля класса!
            // return non_static_int;
        }
};

int A::static_int = 0;

ostream& operator<<(ostream& os, const A& a )
{
    os << "{ " << a.non_static_int << ", " << a.static_int << " }";
    return os;
}

int main()
{
    // Один экземпляр
    A a1;
    // Второй экземпляр
    A a2;

    // Обновляем значение нестатических полей
    a1.non_static_int = 1;
    a2.non_static_int = 2;

    // Выводим на экран содержимое объектов
    cout << a1 << endl;
    cout << a2 << endl;

    // Обновляем значение статического поля
    a1.static_int = 1;
    
    // Выводим на экран содержимое объектов
    cout << a1 << endl;
    cout << a2 << endl;

    // Обновляем значение статического поля
    A::static_int = 2;

    // Выводим на экран содержимое объектов
    cout << a1 << endl;
    cout << a2 << endl;

    // Вызываем статический метод
    cout << a1.static_method() << endl;
    cout << a2.static_method() << endl;
    cout << A::static_method() << endl;

    return 0;
}
