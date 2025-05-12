#include <iostream>
#include <fstream>

using namespace std;

class Animal {
public:
    Animal() {}
    
    // virtual void say(ostream& os) {
    //     os << "(silence)" << endl;
    // }
};

// Заменяем метод для вывода на перегруженный оператор.
ostream& operator<<(ostream& os, const Animal& a)
{
    os << "(silence)" << endl;
    return os;
}

int main()
{
    Animal a;

    cout << a;

    ofstream of;
    of.open("say.txt");
    of << a;
    of.close();

    return 0;
}
