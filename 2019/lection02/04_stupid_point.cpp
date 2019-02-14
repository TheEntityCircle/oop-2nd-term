#include <iostream>

using namespace std;

// Класс точки в 2D, ничего особо умного класс пока не умеет
class Point2D
{
// Поля класса private - к ним нельзя обратиться извне
private:
    float x;
    float y;

public:
    // Конструктор класса, инициализирует его при создании
    Point2D() {
        cout << "Constructor called" << endl;
        this->x = 0;
        this->y = 0;
    }

    // Деструктор класса, в данном случае по факту пустой
    ~Point2D() {
        cout << "Destructor called" << endl;
    }

    // Класс может предоставить public методы
    // для работы со своими private полями

    void setX(float x) {
        this->x = x;
    }

    void setY(float y) {
        this->y = y;
    }

    float getX() {
        return x;
    }

    float getY() {
        return y;
    }
};

// Функция, в которой появляется и тут же уничтожается экземпляр класса
void func()
{
    Point2D p1;
}

int main()
{
    // Вызовем функцию, в которой существует экземпляр класса
    func();

    // Создадим ещё один экземпляр класса, теперь уже в main
    int x = 1;
    Point2D p;
    cout << "Point: (" << p.getX() << ", " << p.getY() << ")" << endl;
    p.setX(x);
    p.setY(2.5);
    cout << "Point: (" << p.getX() << ", " << p.getY() << ")" << endl;

    return 0;
}
