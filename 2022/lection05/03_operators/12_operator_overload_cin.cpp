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

    // Пустой конструктор, теперь он нужен
    // (иначе как будет создан вектор, пока он не считан с cin?)
    Vector2D() : Vector2D(0, 0) {
    }

    // Получение координат
    int getX() const {
        return x;
    }
    int getY() const {
        return y;
    }

    // Задание координат, нужно для оператора >>
    // (Ну или оператор должен стать friend-ом)
    void setX(int x) {
        this->x = x;
    }
    void setY(int y) {
        this->y = y;
    }

    // Перегруженный оператор - сравнение двух векторов на равенство
    bool operator== (const Vector2D& v2) const {
        return x == v2.x && y == v2.y;
    }

    // Сумма двух векторов, исходные вектора не меняются, возвращается новый вектор
    Vector2D operator+ (const Vector2D& v2) const {
        return Vector2D(x + v2.x, y + v2.y);
    }
};

// Перегруженный оператор, вывод вектора в формате (1; 1)
std::ostream& operator<<(std::ostream& os, const Vector2D& v) {
    os << "(" << v.getX() << "; " << v.getY() << ")";
    return os;
}

// Чтение вектора, пусть будет просто две координаты без хитростей
std::istream& operator>>(std::istream &is, Vector2D &v) {
    int x, y;
    is >> x >> y;
    v.setX(x);
    v.setY(y);
    return is;
}

int main()
{
    Vector2D v;
    cin >> v;
    cout << "Read vector: " << v << endl;
    
    return 0;
}
