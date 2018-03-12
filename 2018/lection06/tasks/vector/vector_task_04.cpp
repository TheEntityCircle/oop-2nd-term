#include <iostream>

using namespace std;

class Vector2D
{
public:
    Vector2D();
    Vector2D(int x, int y);
    ~Vector2D();

    bool operator== (const Vector2D& v2);
    bool operator!= (const Vector2D& v2);
    Vector2D operator+ (const Vector2D& v2);
    Vector2D operator* (const int a);
};

Vector2D operator* (int a, const Vector2D& v);
std::ostream& operator<<(std::ostream& os, Vector2D& v);
std::istream& operator>>(std::istream &is, Vector2D &v);

int main()
{
    Vector2D v;
    cin >> v;
    cout << v << endl;
    return 0;
}
