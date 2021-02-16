// Пример взят с https://www.geeksforgeeks.org/multiple-inheritance-in-c/ и адаптирован/упрощён

#include<iostream>

using namespace std;

// Человек. Просто человек со всеми своими особенностями.
class Person {
protected:
    int a, b, c;
public:
    Person() {
        cout << "Person() called" << endl;
    }
};

// Препод. Содержит внутри себя человека.
class Faculty : virtual public Person {
public:
    Faculty() {
       cout << "Faculty() called" << endl;
    }
};

// Студент. Тоже содержит внутри себя человека.
class Student : virtual public Person {
public:
    Student() {
        cout << "Student() called" << endl;
    }
};

// Старшекур-ментор. Одновременно студент и препод.
class Mentor : public Faculty, public Student  {
public:
    Mentor() {
        cout << "Mentor() called" << endl;
    }
};

int main()  {
    // Теперь проблема шизофрении менторов решена
    Mentor m;
    return 0;
}
