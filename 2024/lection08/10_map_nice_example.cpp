#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// Класс, описывающий человека с именем и возрастом
class Person
{
friend ostream& operator<<(ostream& os, const Person& p);
private:
    string name;
    unsigned int age;

public:
    Person() {}
    Person(const string& name, unsigned int age) : name(name), age(age) {
    }

    string getName() const {
        return name;
    }
};

// Оператор вывода человека
ostream& operator<<(ostream& os, const Person& p) {
    os << "{name: " << p.name << ", age: " << p.age << "}";
    return os;
}


int main()
{
    // Допустим, у нас есть массив людей,
    // которых мы хотим искать по имени.
    vector<Person> input = {{"Alice", 16}, {"Bob", 17}, {"Charlie", 18}};

    // Создадим и заполним map-у для быстрого поиска
    map<string, Person> people;
    for(auto p : input)
    {
        // В качестве ключа используем нужное поле из класса,
        // в качестве значения храним целиком экземпляр класса.
        people[p.getName()] = p;
    }

    vector<string> to_find = {"Alice", "Zorro"};
    for(auto f : to_find)
    {
        cout << "Looking for " << f << endl;
        // Ищем в map-e по имени, получаем итератор
        auto found = people.find(f);

        // Если итератор не end(), он показывает на какой-то элемент, ...
        if(found != people.end()) {
            // ... который можно вывести на экран (значение лежит в поле second), ...
            cout << "\tFound: " << found->second << endl;
        } else {
            // ... а если итератор end(), значит такого ключа в map-е не найдено.
            cout << "\tNot found" << endl;
        }
    }

    return 0;
}
