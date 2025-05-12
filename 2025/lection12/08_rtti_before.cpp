#include <iostream>
#include <typeinfo>

class Person {
public:
    virtual ~Person() = default;
};

class Employee : public Person {
};

using namespace std;

int main() {
    Person p;
    Employee e;

    cout << boolalpha;
    cout << "p is Person: " << (typeid(p) == typeid(Person)) << endl;
    cout << "p is Employee: " << (typeid(p) == typeid(Employee)) << endl;
    cout << "e is Person: " << (typeid(e) == typeid(Person)) << endl;
    cout << "e is Employee: " << (typeid(e) == typeid(Employee)) << endl;

    cout << "e is some subclass of Person: " << (typeid(Person).before(typeid(e))) << endl;
    // Заметка на полях: t1.before(t2), очевидно, сильно медленнее, чем t1 == t2.

    return 0;
}

