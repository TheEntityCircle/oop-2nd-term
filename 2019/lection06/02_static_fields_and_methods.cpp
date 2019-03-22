#include <iostream>

using namespace std;

class A
{
public:
    // Нестатическое поле
    int non_static_int = 0;
    // Статическое поле
    static int static_int;

    // Вывод объекта в некоторый поток
    void print(ostream& os) {
        os << "{ " << non_static_int << ", " << static_int << " }" << endl;
    }

    static int static_method()
    {
        return static_int;
        // Ошибка: статический метод может использовать только статические поля класса!
        // return non_static_int;
    }
};

// Статическое поле присвоено для класса *вообще*, не для конкретного экземпляра
int A::static_int = 0;


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
    a1.print(cout);
    a2.print(cout);

    // Обновляем значение статического поля,
    // обращаясь через один из экземпляров класса
    a1.static_int = 1;
    
    // Выводим на экран содержимое объектов
    a1.print(cout);
    a2.print(cout);

    // Обновляем значение статического поля,
    // обращаясь без использования какого-либо экземпляра класса
    A::static_int = 2;

    // Выводим на экран содержимое объектов
    a1.print(cout);
    a2.print(cout);

    // Вызываем статический метод
    // (а) из экземпляров класса
    cout << a1.static_method() << endl;
    cout << a2.static_method() << endl;
    // (б) без экземпляра класса
    cout << A::static_method() << endl;

    return 0;
}
