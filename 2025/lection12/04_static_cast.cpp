#include<iostream>

using namespace std;

class Vegetable {
};

class Animal {
public:
    virtual void speak() {
        cout << "bla bla bla" << endl;
    }
};

class Human: public Animal {
public:
    virtual void speak() {
        cout << "Where's the nearest library?" << endl;
    }
};

class Githyanki: public Animal {
public:
    virtual void speak() {
        cout << "Action, not reaction!" << endl;
    }
};

int main()
{
    Vegetable* v = new Vegetable();
    Animal* a = new Animal();
    Human* h = new Human();
    Githyanki*g = new Githyanki();

    // Это штатное использование
    Animal* ah = static_cast<Animal*>(h);
    ah->speak();

    // Это не скомпилируется
    // Human* hv = static_cast<Human *>(v);
    // Human* hg = static_cast<Human *>(g);

    // Это упадёт в segfault
    // Human* ha = static_cast<Human *>(a);
    // ha->speak(); // это упадёт в segfault

    return 0;
}
