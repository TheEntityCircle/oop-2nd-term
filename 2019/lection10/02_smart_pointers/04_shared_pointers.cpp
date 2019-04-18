#include <iostream>
#include <string>
#include <memory>

using namespace std;

// Smart pointer-ы появились в C++11.
// Более старые компиляторы это не соберут.

class User
{
protected:
    string name;
public:
    User(string name) {
        cout << "Constructor called for " << name << endl;
        this->name = name;
    }

    ~User() {
        cout << "Destructor called for " << this->name << endl;
    }

    string getName() const {
        return this->name;
    }
};

ostream& operator<<(std::ostream& os, const User& u)
{
    os << u.getName();
    return os;
}

shared_ptr<User> getUser()
{
    // Массив указателей (smart pointer-ов) на пользователей
    shared_ptr<User> users[2];
    users[0] = shared_ptr<User>(new User("Alice"));
    users[1] = shared_ptr<User>(new User("Bob"));

    // Работа с массивом
    cout << "The users:" << endl;
    for (int i = 0; i < 2; i++)
        cout << *users[i] << endl;

    // Очень хочется выбрать один элемент и работать с ним отдельно
    // Например, хочется вернуть его из функции
    shared_ptr<User> selected;
    selected = users[0];
    cout << "Selected user: " << *selected << endl;

    return selected;
}

int main()
{
    cout << "Calling getUser()" << endl;
    shared_ptr<User> user = getUser();
    cout << "Returned from getUser()" << endl;
    cout << "Selected user: " << *user << endl;
    return 0;
}
