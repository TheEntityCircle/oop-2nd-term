#include <iostream>
using namespace std;

// Данный пример не работает, падая с Segmentation fault.
// Попробуйте найти ошибку.

class Person
{
protected:
    string name;
public:
    Person(string _name) : name(_name) { }
    ~Person() { }
    string getName() const { return name; }
};

std::ostream& operator<<(std::ostream& os, const Person& p) {
    os << "(" << p.getName() << ")";
    return os;
}

int main()
{
    Person p("Alice");
    cout << p << endl;
    return 0;
}
