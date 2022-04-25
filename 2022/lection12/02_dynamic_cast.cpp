#include<iostream>

using namespace std;

class Vegetable {
    virtual void grow() {}
};

class Animal {
    virtual void speak() {}
};

class Human: public Animal {
public:
    void speak() {
        cout << "Bla bla bla" << endl;
    }
};

int main()
{
    Vegetable* v = new Vegetable();
    Animal *a = new Animal;

    Human* z = dynamic_cast<Human *>(v);
    if(z != nullptr) {
        z -> speak();
    } else {
        cout << "Cast failed" << endl;
    }

    Human *h = dynamic_cast<Human *>(a);
    if(h != nullptr) {
        h -> speak();
    } else {
        cout << "Cast failed" << endl;
    }

    return 0;
}
