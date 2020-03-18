#include<iostream>

using namespace std;

class Vegetable {
};

class Animal {
};

class Human: public Animal {
public:
    virtual void speak() {
        cout << "Bla bla bla" << endl;
    }
};

int main()
{
    Vegetable* v = new Vegetable();
    Animal* a = new Animal();

    // Это не скомпилируется
    Human* z = static_cast<Human *>(v);

    Human* h = static_cast<Human *>(a);
    h -> speak(); // это упадёт в segfault

    return 0;
}
