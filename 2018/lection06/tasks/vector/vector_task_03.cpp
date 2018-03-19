#include <iostream>

using namespace std;

class Vector2D
{
public:
    Vector2D(int x, int y);
    ~Vector2D();

    bool operator== (const Vector2D& v2);
    bool operator!= (const Vector2D& v2);
    Vector2D operator+ (const Vector2D& v2);
    Vector2D operator* (const int a);
};

Vector2D operator* (int a, const Vector2D& v);

std::ostream& operator<<(std::ostream& os, Vector2D& v);

int main()
{
    Vector2D v1(1, 1);
    Vector2D v2(2, 2);
    Vector2D v3 = v1 * 42;
    cout << v3 << endl;
    Vector2D v4 = 42 * v2;
    cout << v4 << endl;
    return 0;
}
