#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
    multimap<int,string> tags;
    tags.insert(make_pair(111, "tag1"));
    tags.insert(make_pair(222, "tag2"));
    tags.insert(make_pair(333, "tag3"));
    tags.insert(make_pair(111, "tag4"));
    tags.insert(make_pair(111, "tag5"));
    tags.insert(make_pair(222, "tag6"));

    // Поищем значения по ключу. Ожидаем получить диапазон.
    // Теперь с использованием auto.
    auto range = tags.equal_range(111);

    // Обойдём найденные значения
    for (auto it = range.first; it != range.second; ++it)
        cout << "Tag: " << it->second << endl;

    return 0; 
}
