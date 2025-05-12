#include <iostream>
using namespace std;


// Вспомогательная структура для точки.
struct Point {
    int x, y;
};

// Класс для вектора из одной точки в другую.
class Vector {
private:
    Point from, to;
public:
    // Первый конструктор - по начальной точке и конечной.
    Vector(Point from, Point to);
    // Второй конструктор - начальная точка и относительное смещение конечной.
    Vector(Point from, int dx, int dy);
    // Третий конструктор - задается только конечная точка, начальная в нуле.
    Vector(Point to);
  
    void print();
};

Vector::Vector(Point from, Point to)
{
    this->from = from;
    this->to = to;
}

Vector::Vector(Point from, int dx, int dy)
{
    this->from = from;
    this->to.x = from.x + dx;
    this->to.y = from.y + dy;
}

Vector::Vector(Point to)
{
    this->from = {0, 0};
    this->to = to;
}

void Vector::print()
{
    cout << "from: " << from.x << " " << from.y << "  to: " << to.x << " " << to.y << endl;
}

int main()
{
    // Можете написать удобные конструкторы и для точек.
    Point first = {1, 1}, second = {2, 2}, third = {3, 3};

    // Для векторов теперь можно так:
    Vector a(first, second);
    Vector b(third, 5, -5);
    Vector c({7, 7}); // здесь создается временная точка, используется для инициализации и удаляется

    a.print();
    b.print();
    c.print();
    return 0;
}
