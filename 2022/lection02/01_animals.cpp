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
    virtual void say() {
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
    // Обратите внимание - флаг boolalpha передаётся один раз
    // а влияет на весь последующий вывод в поток cout.
    cout << boolalpha;

    // Создадим бешенную собаку и пообщаемся с ней
    CrazyDog cd;
    cout << "CrazyDog says: ";
    cd.say();

    cout << "===========================" << endl;
    // А теперь опять создадим бешенную собаку, 
    // но запомним указатель как Animal* - собака же является зверушкой.
    // Это важная фича наследования.
    Animal* a = new CrazyDog();
    cout << "CrazyDog says: ";
    a->say();

    delete a;

    return 0;
}
