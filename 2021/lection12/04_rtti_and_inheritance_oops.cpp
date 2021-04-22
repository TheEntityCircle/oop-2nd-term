#include <iostream>
#include <typeinfo>

class Person {
public:
    // virtual ~Person() = default;
};

class Employee : public Person {
};

int main() {
    Person person;
    Employee employee;
    Person* ptr = &employee;
    Person& ref = employee;

    std::cout << typeid(person).name() << std::endl;    // Person (statically known at compile-time).
    std::cout << typeid(employee).name() << std::endl;  // Employee (statically known at compile-time).
    std::cout << typeid(ptr).name() << std::endl;       // Person* (statically known at compile-time).
    std::cout << typeid(*ptr).name() << std::endl;      // Expected to be Employee (but it isn't!).
    std::cout << typeid(ref).name() << std::endl;       // Expected to be Employee (but it isn't!).


    return 0;
}
