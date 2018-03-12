#include <iostream>

using namespace std;

class Point2D
{
private:
	float x;
	float y;

public:
	Point2D() {
		this->x = 0;
		this->y = 0;
	}

	Point2D(float x, float y) {
		this->x = x;
		this->y = y;
	}

	Point2D(int x, int y) {
		this->x = x;
		this->y = y;
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
	Point2D p;
	cout << "Point: (" << p.getX() << ", " << p.getY() << ")" << endl;

	float x_f = 1.5;
	float y_f = 2.5;
	Point2D p1(x_f, y_f);
	cout << "Point: (" << p1.getX() << ", " << p1.getY() << ")" << endl;

	int x_i = 4;
	int y_i = 8;
	Point2D p2(x_i, y_i);
	cout << "Point: (" << p2.getX() << ", " << p2.getY() << ")" << endl;
	return 0;
}
