#include <forward_list>
#include <list>
#include <iostream>
#include <algorithm>

using namespace std;

// Какие-то операторы можно просто брать с cppreference

std::ostream& operator<<(std::ostream& ostr, const std::forward_list<int>& list)
{
    for (const int i : list)
        ostr << ' ' << i;
    return ostr;
}

std::ostream& operator<<(std::ostream& ostr, const std::list<int>& list)
{
    for (const int i : list)
        ostr << ' ' << i;
    return ostr;
}

int main()
{
    // Односвязный список, тоже шаблонизированный контейнер.
    // Есть списковая инициализация, если понадобится.
    forward_list<char> chars{'A', 'B', 'C', 'D'};
 
    // Выкидываем элементы спереди по одному. 
    for (; !chars.empty(); chars.pop_front())
        cout << chars.front() << " ";
    cout << endl;

    // Создали два списка интов.
    forward_list<int> list1 = {5, 9, 1, 3, 3};
    forward_list<int> list2 = {8, 7, 2, 3, 4, 4};
 
    // Отсортировали каждый за n log n
    list1.sort();
    list2.sort();
    cout << "list1: " << list1 << '\n';
    cout << "list2: " << list2 << '\n';
    // Вклеили второй список в первый.
    list1.merge(list2);
    cout << "merged:" << list1 << '\n';


    // А это двухсвязный список из интов.
    list<int> l = {7, 5, 16, 8};
 
    // Добавили один элемент вперед.
    l.push_front(25);
    // И один назад.
    l.push_back(13);
 
    // Нашли функцией из <algorithm> итератор элемента
    // со значением 16.
    auto it = find(l.begin(), l.end(), 16);
    // Если там такого нет, то итератор будет указывать на end.
    if (it != l.end())
    // Если есть, то вставляем по итератору новое значение.
        l.insert(it, 42);
 
    // Вывод списка на экран.
    cout << l << endl;

    return 0;
}
