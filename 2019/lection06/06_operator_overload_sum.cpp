#include <iostream>
  
using namespace std;

class Vector2D
{
protected:
    int x;
    int y;
public:
    // Конструктор, сразу указываем x и y
    Vector2D(int _x, int _y) : x(_x), y(_y) {
    }

    // Деструктор (пустой)
    ~Vector2D() {
    }

    // Получение координат
    int getX() const {
        return x;
    }
    int getY() const {
        return y;
    }

    // Перегруженный оператор - сравнение двух векторов на равенство
    bool operator== (const Vector2D& v2) const {
        return x == v2.x && y == v2.y;
    }

    // Сумма двух векторов, исходные вектора не меняются, возвращается новый вектор
    Vector2D operator+ (const Vector2D& v2) const {
        return Vector2D(x + v2.x, y + v2.y);
        // Полностью аналогичная по сути, но более многословная запись
        //int newX = this->x + v2.x;
        //int newY = this->y + v2.y;
        //Vector2D vec(newX, newY);
        //return vec;
    }
};

// Перегруженный оператор, вывод вектора в формате (1; 1)
std::ostream& operator<<(std::ostream& os, const Vector2D& v) {
    os << "(" << v.getX() << "; " << v.getY() << ")";
    return os;
}

int main()
{
    Vector2D v1(1, 1);
    Vector2D v2(2, 1);
    Vector2D v3(1, 1);

    cout << boolalpha;
    cout << "v1: " << v1 << endl;
    cout << "v2: " << v2 << endl;
    cout << "v3: " << v3 << endl;
    cout << "v1 == v2: " << (v1 == v2) << endl;
    cout << "v1 == v3: " << (v1 == v3) << endl;

    Vector2D v4 = v1 + v2;
    cout << "v4: " << v4 << endl;

    return 0;
}
