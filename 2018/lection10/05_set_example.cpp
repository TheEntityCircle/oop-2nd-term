#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// Вывод set-а строк
ostream& operator<<(ostream& os, const set<string>& s)
{
    for (set<string>::iterator it = s.begin(); it != s.end(); it++)
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
    for(unsigned int i = 0; i < keywords.size(); i++)
    {
        string keyword = keywords[i];
        if(a.find(keyword) != a.end())
            cout << "Set a contains value: " << keyword << endl;
        else
            cout << "Set a does not contain value: " << keyword << endl;
    }

    // Находим объединение set-ов, вставляем его в новый set с использованием std::inserter.
    // Логически последний параметр: "куда передать результат операции".
    // Технически последний параметр: OutputIterator (итератор, разрешающий запись), 
    // который совершенно не обязан быть set-ом, может "указывать" хоть на экран.
    // Поэтому используется std::inserter - вспомогательная сущность, которая возвращает 
    // OutputIterator для вставки в указанное место указанного контейнера.
    set<string> su;
    set_union(a.begin(), a.end(), b.begin(), b.end(), std::inserter(su, su.end()));
    cout << "Union of a and b: " << su << endl;

    // Находим пересечение set-ов
    set<string> si;
    set_intersection(a.begin(), a.end(), b.begin(), b.end(), inserter(si, si.end()));
    cout << "Intersection of a and b: " << si << endl;

    // Вычитаем из одного set-а другой
    set<string> sd;
    set_difference(a.begin(), a.end(), b.begin(), b.end(), inserter(sd, sd.end()));
    cout << "Difference of a and b: " << sd << endl;

    // Копируем set, добавляем в копию новые данные
    set<string> c;
    copy(su.begin(), su.end(), inserter(c, c.end()));
    c.insert("hello world");
    c.insert("i");
    c.insert("intersection");
    cout << "New set: " << c << endl;

    // Выводим на экран часть set-а, выбирая строки "по словарю"
    set<string> selection;
    copy(c.lower_bound("c"), --c.upper_bound("i"), inserter(selection, selection.end()));
    cout << "Selection: " << selection << endl;

    return 0; 
}
