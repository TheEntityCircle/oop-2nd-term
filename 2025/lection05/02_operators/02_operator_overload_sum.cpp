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

    void talk()
    {
        cout << "(" << x << "; " << y << ")" << endl;
    }
};

int main()
{
    Vector2D v1(1, 1);
    Vector2D v2(2, 1);
    Vector2D v3(1, 1);

    cout << boolalpha;
    cout << "v1 == v2: " << (v1 == v2) << endl;
    cout << "v1 == v3: " << (v1 == v3) << endl;

    Vector2D v4 = v1 + v2;
    v4.talk();

    return 0;
}
