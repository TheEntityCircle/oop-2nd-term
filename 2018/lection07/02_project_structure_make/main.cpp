#include <iostream>

#include "cow.hpp"
#include "dog.hpp"
#include "crazy_dog.hpp"

using namespace std;

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
        delete animals[i];
    }

    return 0;
}
