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

// Реализовать несколько интерфейсов 
// - предельно штатная ситуация, не надо этого бояться
class UiSnake : public Animal, public Drawing {
public:
    void move();
    void show();
};

void UiSnake::move()
{
    cout << "Snake moves" << endl;
}

void UiSnake::show()
{
    cout << "Drawing snake" << endl;
}

int main()
{
    UiSnake* s = new UiSnake();
    s->move();
    s->show();
    return 0;
}
