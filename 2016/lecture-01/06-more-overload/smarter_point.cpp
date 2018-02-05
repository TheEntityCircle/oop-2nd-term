#include <iostream>
using namespace std;

class Point2D
{
private:
	float x;
	float y;
public:
	Point2D() { };
	Point2D(float x, float y) {
		this->x = x;
		this->y = y;
	}
	Point2D(int x, int y) {
		this->x = x;
		this->y = y;
	}

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

	bool operator== (const Point2D& p) {
		return ((x == p.x) && (y == p.y));
	}
};

int main()
{
	float x_f = 1.5;
	float y_f = 2.5;
	Point2D p(x_f, y_f);
	cout << "Point: (" << p.getX() << ", " << p.getY() << ")" << endl;

	int x_i = 4;
	int y_i = 8;
	Point2D p2(x_i, y_i);
	cout << "Point: (" << p2.getX() << ", " << p2.getY() << ")" << endl;

	Point2D p3(4, 8);

	if(p == p3)
		cout << "Points are equal" << endl;
	else
		cout << "Points are not equal" << endl;

	if(p2 == p3)
		cout << "Points are equal" << endl;
	else
		cout << "Points are not equal" << endl;

	return 0;
}
