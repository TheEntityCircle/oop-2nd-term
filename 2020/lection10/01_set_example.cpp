#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// Вывод set-а строк
ostream& operator<<(ostream& os, const set<string>& s)
{
    for (set<string>::iterator it = s.begin(); it != s.end(); ++it)
        os << "'" << *it << "' ";
    return os;
}

int main()
{
    // Создаём и заполняем set
    set<string> a;
    a.insert("test");
    a.insert("foo");

    // Ицициализация set-а с использованием синтаксиса С++11
    set<string> b = {"foo", "bar", "baz"};

    cout << "Set a: " << a << endl;
    cout << "Set b: " << b << endl;

    // Ищем значения в set
    vector<string> keywords = {"test", "azaza"};
    for(unsigned int i = 0; i < keywords.size(); ++i)
    {
        string keyword = keywords[i];
        if(a.find(keyword) != a.end())
            cout << "Set a contains value: " << keyword << endl;
        else
            cout << "Set a does not contain value: " << keyword << endl;
    }

    return 0; 
}
