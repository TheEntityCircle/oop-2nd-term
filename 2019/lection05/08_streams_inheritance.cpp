#include <iostream>
#include <fstream>

using namespace std;

// Возьмём опять зверя, убрав всё лишнее
class Animal {
public:
    Animal() {}
    
    // Раньше было так, вывод строго в cout
    //virtual void say() {
    //    cout << "(silence)" << endl;
    //}

    // Теперь вывод в переданный поток.
    // Тип параметра - базовый ostream.
    // То есть вывод будет прозрачным образом в любую из его реализаций.
    virtual void say(ostream& os) {
        os << "(silence)" << endl;
    }
};

int main()
{
    Animal a;

    // Просим зверя сказать что-нибудь в cout. Это уже было.
    a.say(cout);

    // Откроем файл
    ofstream of;
    of.open("say.txt");

    // А теперь - в файл. Это как будто какая-то новая хотелка.
    // Но зверь работает с базовым ostream, так что он вообще 
    // не видит разницы между экраном и файлом. И это хорошо.
    a.say(of);

    // Закроем файл
    of.close();

    return 0;
}
