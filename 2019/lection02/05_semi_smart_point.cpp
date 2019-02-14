#include <iostream>

using namespace std;

class Point2D
{
private:
    float x;
    float y;

public:
    // У точки стало нексолько конструкторов с разными наборами параметров.
    // Не то чтобы она стала от этого умной по сути,
    // но технически это заявка на некое умное поведение класса.

    Point2D() {
        this->x = 0;
        this->y = 0;
    }

    Point2D(float x, float y) {
        this->x = x;
        this->y = y;
    }

    Point2D(float a) {
        this->x = a;
        this->y = a;
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
};

int main()
{
    // Конструктор по умолчанию - без параметров
    Point2D p0;
    cout << "Point: (" << p0.getX() << ", " << p0.getY() << ")" << endl;

    // Второй конструктор
    float x_f = 1.5;
    float y_f = 2.5;
    Point2D p1(x_f, y_f);
    cout << "Point: (" << p1.getX() << ", " << p1.getY() << ")" << endl;

    // Третий конструктор
    int a = 4;
    Point2D p2(a);
    cout << "Point: (" << p2.getX() << ", " << p2.getY() << ")" << endl;

    return 0;
}
