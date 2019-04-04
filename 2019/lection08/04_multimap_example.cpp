#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
    // Пусть ключ для разнообразия будет int.
    // Например, есть id каких-нибудь объектов, которым заданы тэги.
    multimap<int,string> tags;

    // Заполняем данные, ключи при этом повторяются
    tags.insert(make_pair(111, "tag1"));
    tags.insert(make_pair(222, "tag2"));
    tags.insert(make_pair(333, "tag3"));
    tags.insert(make_pair(111, "tag4"));
    tags.insert(make_pair(111, "tag5"));
    tags.insert(make_pair(222, "tag6"));

    // Посмотрим, сколько значений есть для данного ключа
    cout << "Number of tags for object 111: " << tags.count(111) << endl;

    // Объявим итератор по контейнеру
    multimap<int,string>::iterator it;

    // Обойдём весь контейнер
    cout << "All tags per object:" << endl;
    for (it = tags.begin(); it != tags.end(); ++it)
        cout << "Object " << it->first << ": " << it->second << endl;

    // Поищем значения по ключу. Ожидаем получить диапазон.
    // Офтоп: милый синтаксис, правда?
    // Вся первая строчка - тип возвращаемого значения. :-)
    pair<multimap<int,string>::iterator, multimap<int,string>::iterator> 
        range = tags.equal_range(111);

    // Обойдём найденные значения
    for (it = range.first; it != range.second; ++it)
        cout << "Found tag for object " << it->first << ": " << it->second << endl;

    return 0; 
}
