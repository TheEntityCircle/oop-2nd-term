#include <iostream>

using namespace std;

class Vector2D
{
public:
    Vector2D(int x, int y);
    ~Vector2D();
    int getX();
    int getY();
    bool operator== (const Vector2D& v2);
};

std::ostream& operator<<(std::ostream& os, Vector2D& v);

int main()
{
    Vector2D v1(1, 1);
    Vector2D v2(2, 2);
    Vector2D v3(1, 1);
    cout << v1 << endl;
    cout << (v1 == v2) << endl;
    cout << (v1 == v3) << endl;
    return 0;
}
