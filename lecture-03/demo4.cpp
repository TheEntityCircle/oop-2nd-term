#include <iostream>

using namespace std;

class Animal {
public:
    virtual void move() = 0;
};

class Drawing {
public:
    virtual void show() = 0;
};

class UiSnake : public Animal, public Drawing {
public:
    void move();
    void show();
};

void UiSnake::move()
{
}

void UiSnake::show()
{
}

int main()
{
    UiSnake* s = new UiSnake();
    return 0;
}
