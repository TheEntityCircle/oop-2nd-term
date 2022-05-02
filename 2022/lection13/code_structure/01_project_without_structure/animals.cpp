#include <iostream>
#include <iomanip>

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
    virtual void say() = 0; // Виртуальный метод, реализация будет в дочерних классах
    bool hasBrain() {
        return brain;
    }
};

class Cow: public Animal {
public:
    Cow() {
        cout << "Cow created" << endl;
    }

    void say() {
        cout << "Moo" << endl;
    }
};

class Dog: public Animal {
public:
    Dog() {
        cout << "Dog created" << endl;
    }

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

    void say() {
        cout << "Woof! Woof! Woof! Woof! Woof!" << endl;
    }
};

int main() {
    Animal* animals[3];
    animals[0] = new Cow();
    animals[1] = new Dog();
    animals[2] = new CrazyDog();

    cout << boolalpha;
    for(int i = 0; i < 3; i++) {
        cout << "Animal[" << i << "] has brain? " << animals[i]->hasBrain() << endl;
        cout << "Animal[" << i << "] says: ";
        animals[i]->say();
        delete animals[i];
    }

    return 0;
}
