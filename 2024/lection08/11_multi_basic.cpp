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

    // Обойдём весь контейнер
    cout << "All tags per object:" << endl;
    for (auto tag : tags)
        cout << "Object " << tag.first << ": " << tag.second << endl;

    // Поищем значения по ключу. Ожидаем получить диапазон.
    // Милый синтаксис, правда?
    // Вся первая строчка - это тип возвращаемого значения
    // (всего лишь пара итераторов, границы диапазона).
    pair<multimap<int,string>::iterator, multimap<int,string>::iterator> 
        range = tags.equal_range(111);
    // После 11 стандарта можно писать так. 
    // Но можно ли сказать, что это более читаемо, или нет?
    // auto range = tags.equal_range(111);

    // Обойдём найденные значения, но range-based for не сработает
    // for (auto tag : range) 
    for (auto it = range.first; it != range.second; ++it)
        cout << "Found tag for object " << it->first << ": " << it->second << endl;

    return 0; 
}
