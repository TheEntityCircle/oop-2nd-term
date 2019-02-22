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
    void say() {
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
};

int main() {
    // Обратите внимание - флаг boolalpha передаётся один раз
    // а влияет на весь последующий вывод в поток cout.
    cout << boolalpha;

    // Создаём зверинец, пробуем с ним пообщаться. Обратите внимание на:
    // (а) цепочки конструкторов, (б) вызов разных реализаций метода say.

    Turtle t;
    cout << "Turtle has brain? " << t.hasBrain() << endl;
    cout << "Turtle says: ";
    t.say();

    cout << "===========================" << endl;
    Cow c;
    cout << "Cow has brain? " << c.hasBrain() << endl;
    cout << "Cow says: ";
    c.say();

    cout << "===========================" << endl;
    Dog d;
    cout << "Dog has brain? " << d.hasBrain() << endl;
    cout << "Dog says: ";
    d.say();

    cout << "===========================" << endl;
    CrazyDog cd;
    cout << "CrazyDog has brain? " << cd.hasBrain() << endl;
    cout << "CrazyDog says: ";
    cd.say();

    return 0;
}
