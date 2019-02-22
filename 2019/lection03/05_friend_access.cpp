#include <iostream>

using namespace std;

class A
{
friend class B;

private:
    int secret;

public:
    A(int i) {
        this->secret = i;
    }

    void describe() {
        cout << "I'm A, my value is: " << secret << endl;
    }
};

class B
{
public:
    B() {
    }

    // Класс B получает указатель на класс A и что-то с ним делает
    void run(A* a) {
        // Работаем с классом A, вызываем его публичные методы - это ок
        cout << "I'm B, I'm going to handle this one: ";
        a->describe();
        // Это не скомпилится, так как secret объявлен в классе A как private
        cout << "Class B is working on value: " << a->secret << endl;
        a->secret = 13;
    }
};

int main()
{
    // Создаём экземпляр класса A, пусть он сделает свою работу
    A a(42);
    a.describe();

    // Создаём экземпляр класса B
    B b;
    // Пробуем передать ему указатель на A для обработки
    b.run(&a);
    // Проверяем, как дела у A после обработки
    a.describe();

    return 0;
}
