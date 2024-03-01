#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Строка в стиле C
    char s[20];
    // Класс строки C++
    string s1, s2, s3;

    cout << "C strings" << endl;

    // Читаем и выводим слова
    cin >> s;
    cout << s << endl;
    cin >> s;
    cout << s << endl;

    // Читаем и выводим строку целиком с пробелами
    //cin.getline(s, 20);
    //cout << s << endl;
    
    cout << "C++ strings" << endl;

    // То же самое, но с использованием строк C++
    cin >> s1;
    cout << s1 << endl;
    cin >> s2;
    cout << s2 << endl;

    //getline(cin, s3);
    //cout << s3 << endl;

    return 0;
}
