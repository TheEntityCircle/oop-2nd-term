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
    // Объявили массив указателей на абстрактных зверушек
    Animal* animals[4];
    // Насоздали конкретных зверушек (смотрим в сообщения в консоли, видим цепочки конструкторов)
    //animals[0] = new Animal(); <-- Так теперь нельзя, нельзя создать класс с виртуальным методом
    animals[1] = new Cow();
    animals[2] = new Dog();
    animals[3] = new CrazyDog();

    // Попробовали к ним обращаться (спойлер - теперь работает!)
    for(int i = 1; i < 4; i++) { // <-- от 1-го, так как Animal() более нет
        cout << "Animal[" << i << "] has brain? " << animals[i]->hasBrain() << endl;
        cout << "Animal[" << i << "] says: ";
        animals[i]->say();
        //delete animals[i];
    }

    return 0;
}
