#include <iostream>
using namespace std;

class Point2D
{
private:
    float x;
    float y;

public:
    Point2D() {
        this->x = 0;
        this->y = 0;
    }

    Point2D(float x, float y) {
        this->x = x;
        this->y = y;
    }

    ~Point2D() { }

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

    // Перегруженный оператор сравнения двух точек.
    // Теперь логика 'что такое равные точки' будет упакована внутрь точки.
    // Это и есть инкапсуляция.

    // Синтаксис с const и & придётся пока принять на веру. Детали разберём дальше.
    bool operator== (const Point2D& p) {
        // Сравнивать float-ы на точное равенство - идея не очень. Но оставим так.
        return ((x == p.x) && (y == p.y));
    }
};

// Перегруженный оператор вывода (можно на экран, но не обязательно)
// Теперь логика 'как корректно напечатать точку' тоже будет упакована внутрь точки.
// Это продолжение инкапсуляции.

// Мы 'научили' cout 'понимать' наш класс точки.
// Синтаксис опять придётся пока что принять на веру.
// TODO: вообще-то нужно, чтобы точка p была const. Это тоже разберём дальше.
std::ostream& operator<<(std::ostream& os, Point2D& p)
{
      os << "(" << p.getX() << ", " << p.getY() << ")";
      return os;
}

int main()
{
    float x_f = 1.5;
    float y_f = 2.5;
    Point2D p1(x_f, y_f);
    cout << "p1: " << p1 << endl;

    Point2D p2(1.5, 2.5);
    cout << "p2: " << p2 << endl;

    if(p1 == p2) {
        cout << "Points are equal" << endl;
    } else {
        cout << "Points are not equal" << endl;
    }

    return 0;
}
