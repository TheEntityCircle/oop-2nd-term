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
    // Вся первая строчка - тип возвращаемого значения. :-)
    pair<multimap<int,string>::iterator, multimap<int,string>::iterator>
        range = tags.equal_range(111);

    // Таки обойдём найденные значения
    cout << "==== Object 111 ===" << endl;
    multimap<int,string>::iterator it;
    for (it = range.first; it != range.second; ++it)
        cout << "Tag: " << it->second << endl;

    return 0; 
}
