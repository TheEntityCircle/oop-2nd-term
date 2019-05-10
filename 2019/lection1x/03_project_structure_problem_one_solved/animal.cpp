#ifndef ANIMAL_H
#define ANIMAL_H

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

    virtual void say() = 0; // Виртуальный метод, реализация будет в дочерних классах

    // Все эти методы будут доступны в дочерних классах
    bool hasBrain() {
        return brain;
    }
};

#endif
