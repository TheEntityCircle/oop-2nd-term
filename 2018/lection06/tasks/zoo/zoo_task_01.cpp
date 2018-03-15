#include <iostream>

using namespace std;

// Базовый класс животного
class Animal {
public:
    virtual string getType() = 0;
    virtual bool isDangerous() = 0;
    virtual ~Animal() {}
};

// Класс обезьяны
class Monkey : public Animal {
public:
    string getType() {
        return "monkey";
    }
    // Считается неопасным зверем
    bool isDangerous() {
        return false;
    }
};

// Лев
class Lion : public Animal {
public:
    string getType() {
        return "lion";
    }
    // Этот явно опасный
    bool isDangerous() {
        return true;
    }
};

// TODO: реализуйте здесь класс ZooKeeper по заданию

int main()
{
    ZooKeeper z;
    Monkey *m = new Monkey();
    z.handleAnimal(m);
    delete m;
    m = new Monkey();
    z.handleAnimal(m);
    delete m;
    Lion *l = new Lion();
    z.handleAnimal(l);
    delete l;
    cout << z.getDangerousCount() << endl;
    return 0;
}
