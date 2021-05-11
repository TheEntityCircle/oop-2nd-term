#include <iostream>

// Наверное, потребуется include-ить всё, что собираемся использовать.
// Теперь оно прикрыто условной компиляцией, поэтому даже соберётся.
// То, что сейчас у нас вышло, вполне используется для header only include-ов.
// Этого недостаточно в общем случае, но сейчас мы видим, что иногда оно работает.
#include "animal.cpp"
#include "cow.cpp"
#include "dog.cpp"
#include "crazy_dog.cpp"

using namespace std;

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
