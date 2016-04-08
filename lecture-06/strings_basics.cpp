#include <iostream>
#include <string>

using namespace std;

int main()
{
    //  C++ строки
    string s1 = "this is string";
    string s2 = "this is string too";

    // Строка в стиле C
    char s3[20] = "this is string";

    // Сравниваем строки
    cout << "s1 == s2: " << (s1 == s2) << endl;
    cout << "s1 == s2: " << (s1 == s3) << endl;

    // Выполняем конкатенацию
    string s4 = s1 + " + " + s2;
    cout << "s4: " << s4 << endl;

    // Выделяем подстроки
    string subs1 = s1.substr(0, 14);
    string subs2 = s2.substr(0, 14);
    
    string subs4 = s1.substr(8);
    string subs3 = s2.substr(8);
    
    string subs5 = s1.substr(8, 6);
    string subs6 = s2.substr(8, 6);

    cout << "subs1: " << subs1 << endl;
    cout << "subs2: " << subs2 << endl;
    cout << "subs1 == subs2: " << (subs1 == subs2) << endl;

    cout << "subs3: " << subs3 << endl;
    cout << "subs4: " << subs4 << endl;
    cout << "subs3 == subs4: " << (subs3 == subs4) << endl;

    cout << "subs5: " << subs5 << endl;
    cout << "subs6: " << subs6 << endl;
    cout << "subs5 == subs6: " << (subs5 == subs6) << endl;
   
   // Ищем вхождения подстроки
   cout << s1.find("string") << endl;
   cout << s1.find("no such a string") << ", " << string::npos << endl;

    return 0;
}
