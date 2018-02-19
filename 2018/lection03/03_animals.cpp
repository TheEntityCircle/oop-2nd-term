#include <iostream>

using namespace std;

class Animal {
protected:
    bool brain;
public:
    Animal() {
        cout << "Animal created" << endl;
        this->brain = true;
    }

    // Все эти методы будут доступны в дочерних классах
    void say() {
        cout << "(silence)" << endl;
    }
    bool hasBrain() {
        return brain;
    }
};

class Cow: public Animal {
public:
    Cow() {
        cout << "Cow created" << endl;
    };

    void say() {
        cout << "Moo" << endl;
    }
};

class Dog: public Animal {
public:
    Dog() {
        cout << "Dog created" << endl;
    };

    void say() {
        cout << "Woof!" << endl;
    }
};

class CrazyDog: public Dog {
public:
    CrazyDog() {
        this->brain = false;
        cout << "Dog gone crazy" << endl;
    }
};

int main() {
    Cow* c = new Cow();
    cout << "Cow has brain? " << c->hasBrain() << endl;
    cout << "Cow says: ";
    c->say();
    delete c;

    //Dog* d = new Dog();
    //cout << "Dog has brain? " << d->hasBrain() << endl;
    //cout << "Dog says: ";
    //d->say();
    //delete d;

    //CrazyDog* cd = new CrazyDog();
    //cout << "CrazyDog has brain? " << cd->hasBrain() << endl;
    //cout << "CrazyDog says: ";
    //cd->say();
    //delete cd;

    return 0;
}
