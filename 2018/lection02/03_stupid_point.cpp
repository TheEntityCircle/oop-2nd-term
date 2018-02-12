#include <iostream>

using namespace std;

class Point2D
{
private:
	float x;
	float y;

public:
	Point2D() { };

	~Point2D() { };

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
	Point2D p;
	cout << "Point: (" << p.getX() << ", " << p.getY() << ")" << endl;
	int x = 1;
	p.setX(x);
	p.setY(2.5);
	cout << "Point: (" << p.getX() << ", " << p.getY() << ")" << endl;
	return 0;
}
