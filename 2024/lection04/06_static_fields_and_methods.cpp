#include <iostream>

using namespace std;

class A
{
public:
    // Нестатическое поле
    int non_static_int = 0;
    // Статическое поле ("заголовок")
    static int static_int;

    static void static_method()
    {
        static_int++;     // можно
        //non_static_int++; // нельзя
    }
};

// Статическое поле присвоено для класса *вообще*, не для конкретного экземпляра
// Это объявление статической переменной, без него будет ругаться линкер.
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
    cout << "{ " << a1.non_static_int << ", " << a1.static_int << " }" << endl;
    cout << "{ " << a2.non_static_int << ", " << a2.static_int << " }" << endl;

    // Обновляем значение статического поля,
    // обращаясь через один из экземпляров класса
    a1.static_int = 1;
    
    // Выводим на экран содержимое объектов
    cout << "{ " << a1.non_static_int << ", " << a1.static_int << " }" << endl;
    cout << "{ " << a2.non_static_int << ", " << a2.static_int << " }" << endl;

    // Обновляем значение статического поля,
    // обращаясь без использования какого-либо экземпляра класса
    A::static_int = 2;

    // Выводим на экран содержимое объектов
    cout << "{ " << a1.non_static_int << ", " << a1.static_int << " }" << endl;
    cout << "{ " << a2.non_static_int << ", " << a2.static_int << " }" << endl;

    // Вызываем статический метод
    // (а) из экземпляров класса
    a1.static_method();
    a2.static_method();
    // (б) без экземпляра класса
    A::static_method();

    return 0;
}
