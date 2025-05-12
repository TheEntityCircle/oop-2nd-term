#include<iostream>

using namespace std;

class Vegetable {
    virtual void grow() {}
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
    Vegetable* v = new Vegetable;
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

    Githyanki *g = new Githyanki;
    Animal* ag = dynamic_cast<Animal *>(g);
    if(ag != nullptr) {
        ag -> speak();
    } else {
        cout << "Cast failed" << endl;
    }

    return 0;
}
