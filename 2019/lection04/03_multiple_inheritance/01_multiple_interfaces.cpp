#include <iostream>

using namespace std;

// Интерфейс «некий зверь», с которым работает движок
class Animal {
public:
    virtual void move() = 0;
    virtual ~Animal() { }
};

// Интерфейс «некое изображение», с которым работает визуализатор
class Drawing {
public:
    virtual void show() = 0;
    virtual ~Drawing() { }
};

// Реализовать несколько интерфейсов - предельно штатная ситуация.
class Snake : public Animal, public Drawing {
public:
    void move();
    void show();
};

void Snake::move()
{
    cout << "... snake moves ..." << endl;
}

void Snake::show()
{
    cout << "... drawing snake ..." << endl;
}

int main()
{
    // Так со змейкой общается движок
    Animal* a = new Snake();
    a->move();
    delete a;

    // А так - визуализатор
    Drawing* d = new Snake();
    d->show();
    delete d;
    return 0;
}
