#ifndef ANIMAL_H
#define ANIMAL_H

class Animal
{
protected:
    bool brain;

public:
    Animal();
    virtual ~Animal();

    virtual void say() = 0; // Виртуальный метод, реализация будет в дочерних классах

    // Все эти методы будут доступны в дочерних классах
    bool hasBrain();
};

#endif
