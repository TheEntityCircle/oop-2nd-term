#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Строка в стиле C
    char s[20];
    // Класс строки C++
    string s1, s2;

    cout << "C strings" << endl;

    // Читаем и выводим слово
    cin >> s;
    cout << s << endl;
    cin >> s;
    cout << s << endl;

    // Читаем и выводим строку
    cin.getline(s, 20);
    cout << s << endl;
    
    cout << "C++ strings" << endl;

    // То же самое, но с использованием строк C++
    cin >> s1;
    cout << s1 << endl;
    cin >> s2;
    cout << s2 << endl;

    return 0;
}
