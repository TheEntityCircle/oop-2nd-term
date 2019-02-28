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

    // Эти методы будут доступны в дочерних классах
    virtual void say() { // Виртуальный метод, но есть реализация по умолчанию
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
    cout << boolalpha;

    // Объявили массив указателей на абстрактных зверушек
    Animal* animals[4];
    // Насоздали конкретных зверушек (смотрим в сообщения в консоли, видим цепочки конструкторов)
    animals[0] = new Animal(); // Так теперь снова можно
    animals[1] = new Cow();
    animals[2] = new Dog();
    animals[3] = new CrazyDog();

    // Попробовали к ним обращаться (спойлер - теперь работает!)
    for(int i = 0; i < 4; i++) {
        cout << "Animal[" << i << "] has brain? " << animals[i]->hasBrain() << endl;
        cout << "Animal[" << i << "] says: ";
        animals[i]->say();
        delete animals[i];
    }

    return 0;
}
