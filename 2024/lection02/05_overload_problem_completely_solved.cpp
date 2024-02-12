#include <iostream>

using namespace std;

// Базовый класс «зверушка»
class Animal {
protected:
    bool brain;

public:
    Animal() {
        cout << "Animal created" << endl;
        this->brain = true;
    }

    // Все эти методы будут доступны в дочерних классах

    virtual void say() { // Виртуальный метод, но есть реализация по умолчанию
        cout << "(silence)" << endl;
    }

    bool hasBrain() {
        return brain;
    }
};

// Дочерний класс «черепашка», наследуется от класса «зверушка»
class Turtle: public Animal {
public:
    Turtle() {
        cout << "Turtle created" << endl;
    }
};

// Дочерний класс «корова», наследуется от класса «зверушка»
class Cow: public Animal {
public:
    Cow() {
        cout << "Cow created" << endl;
    }

    // Корова имеет свою точку зрения на то, как надо разговаривать
    void say() {
        cout << "Moo" << endl;
    }
};

// Дочерний класс «собака», наследуется от класса «зверушка»
class Dog: public Animal {
public:
    Dog() {
        cout << "Dog created" << endl;
    }

    void say() {
        cout << "Woof!" << endl;
    }
};

// Дочерний класс «ненормальная собака»,
// наследуется не от зверушки, а от обычной собаки
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
