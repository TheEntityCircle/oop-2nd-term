#include <iostream>

using namespace std;

class Point2D
{
private:
	float x;
	float y;

public:
	Point2D() {
		cout << "Constructor called" << endl;
	}

	~Point2D() {
		cout << "Destructor called" << endl;
	}

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

void func()
{
    Point2D p1;
}

int main()
{
    Point2D p;
    cout << "Point: (" << p.getX() << ", " << p.getY() << ")" << endl;
    int x = 1;
    func();
    p.setX(x);
    p.setY(2.5);
    cout << "Point: (" << p.getX() << ", " << p.getY() << ")" << endl;
    return 0;
}
