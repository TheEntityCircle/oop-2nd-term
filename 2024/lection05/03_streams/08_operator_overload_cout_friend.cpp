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
    friend std::ostream& operator<<(std::ostream&, Vector2D&);
};

// Перегруженный оператор, вывод вектора в формате (1; 1)
std::ostream& operator<<(std::ostream& os, Vector2D& v) {
    cout << "(" << v.x << "; " << v.y << ")";
    return os;
}

int main()
{
    Vector2D v1(1, 1);
    Vector2D v2(2, 1);
    Vector2D v3(1, 1);

    cout << boolalpha;
    cout << v1 << endl;
    cout << v2 << endl;
    cout << v3 << endl;
    cout << "v1 == v2: " << (v1 == v2) << endl;
    cout << "v1 == v3: " << (v1 == v3) << endl;
    return 0;
}
