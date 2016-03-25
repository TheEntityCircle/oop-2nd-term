#include <iostream>

using namespace std;

class Point
{
    private:
        float x;
        float y;

    public:
        // Списковая инициализация
        Point(float x, float y): x(x), y(y)
        {
            // В данном случае инициализация аналогична вот этому:
            // 
            // this->x = x;
            // this->y = y;
        }

        // Конструктор без параметров *делегирует* выполнение конструктору с параметрами
        Point(): Point(0.0, 0.0) {}

        void print()
        {
            cout << "Point(" << x << ", " << y << ")" << endl;
        }
};

int main()
{
    // Используем конструктор без параметров
    Point p1;
    // Используем неявный вызов конструктора с параметрами
    Point p2(1.0, 1.0);
    // Используем явный вызов конструктора с параметрами
    Point p3 = Point(2.0, 2.0);
    // Используем списковую инициализацию
    Point p4 = {3.0, 3.0};

    // Используем списковую инициализацию для массива
    Point pts[] = {{1.0, 1.0}, {2.0, 2.0}, {3.0, 3.0}};

    p1.print();
    p2.print();
    p3.print();
    p4.print();

    cout << endl;

    for (int i = 0; i < 3; i++)
        pts[i].print();

    return 0;
}
