#include <iostream>
#include <string>
#include <cstring> // Нужно только для использования функций "в стиле С"

using namespace std;

int main()
{
    //  C++ строки
    string s1 = "It was night again. The Waystone Inn lay in silence, and it was a silence of three parts.";
    string s2 = "The most obvious part was a hollow, echoing quiet, made by things that were lacking.";

    // Строка в стиле C
    char s3[] = "If there had been a wind it would have sighed through the trees, set the inn’s sign creaking on its hooks, and brushed the silence down the road like trailing autumn leaves.";

    // Сравниваем строки
    cout << "s1 == s2: " << (s1 == s2) << endl;
    cout << "s1 == s3: " << (s1 == s3) << endl;

    // Выполняем конкатенацию
    string s4 = s1 + " " + s2 + " " + s3;
    cout << "s4: " << s4 << endl;

    // Выделяем подстроки
    string subs1 = s1.substr(0, 14);
    string subs2 = s2.substr(0, 14);
    
    string subs3 = s1.substr(8);
    string subs4 = s2.substr(8);
    
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
    cout << "Find #1, pos: " <<  s1.find("string") << endl;
    cout << "Find #2, pos: " << s1.find("no such a string") << endl;
    cout << "Value of npos: " << string::npos << endl;
    if(s1.find("no such a string") == string::npos)
        cout << "Not found" << endl;

    // Перевод строк C/C++
    char cstr[20] = "Test string";
    cout << "Initial C string: " << cstr << endl;
    string cppstr = string(cstr);
    cout << "C++ string: " << cppstr << endl;
    char cstr2[20];
    strcpy(cstr2, cppstr.c_str());
    cout << "Second C string: " << cstr2 << endl;

    return 0;
}
