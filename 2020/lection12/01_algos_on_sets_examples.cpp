#include <iostream>
#include <iterator>
#include <string>
#include <set>
#include <vector>
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

    // Находим объединение set-ов, вставляем его в новый set с использованием std::inserter.
    // Логически последний параметр: 'куда передать результат операции'.
    // Технически у set_union последний параметр это insert_iterator (итератор, разрешающий запись), 
    // который совершенно не обязан был связан с set-ом, может 'указывать' хоть на экран.
    // Поэтому используется std::inserter - вспомогательная сущность, которая возвращает 
    // insert_iterator для вставки в указанное место указанного контейнера.
    set<string> su;
    set_union(a.begin(), a.end(), b.begin(), b.end(), std::inserter(su, su.end()));
    cout << "Union of a and b: " << su << endl;

    // Находим пересечение set-ов, сохраним его в vector-е на этот раз
    // (алгоритмы получают итераторы, контейнер под ними может быть любым)
    vector<string> si;
    set_intersection(a.begin(), a.end(), b.begin(), b.end(), inserter(si, si.end()));
    cout << "Intersection of a and b: ";

    // Для вывода vector-а на экран можно было бы написать цикл,
    // но давайте используем for_each и лямбду. Просто потому что можем.
    // (Моё личное мнение, что operator<< был бы читаемее и логичнее,
    // но вдруг вот именно сейчас мы хотим разово вывести как-то нестандартно,
    // а писать цикл почему-то не хотим. В общем, этот код здесь просто для примера.)
    for_each(si.cbegin(), si.cend(), [] (const string& s) {cout << "'" << s << "' ";});
    cout << endl;

    // Вычитаем из одного set-а другой
    set<string> sd1;
    set_difference(a.begin(), a.end(), b.begin(), b.end(), inserter(sd1, sd1.end()));
    cout << "Difference of a and b: " << sd1 << endl;

    set<string> sd2;
    set_difference(b.begin(), b.end(), a.begin(), a.end(), inserter(sd2, sd2.end()));
    cout << "Difference of b and a: " << sd2 << endl;

    // Копируем set в массив и добавляем в копию новый элемент
    // (алгоритмы получают просто итераторы, контейнер под ними не важен)
    set<string> c;
    copy(su.begin(), su.end(), inserter(c, c.end()));
    c.insert("hello");
    cout << "New set: " << c << endl;

    // Выводим на экран часть set-а, выбирая строки примерно по словарю,
    // причём без промежуточного контейнера для хранения.
    // Вызов copy получает три параметра: пару обычных итераторов (что копировать) 
    // плюс insert_iterator (куда складывать результат).
    // Первая пара итераторов в данном случае - результаты поиска в set-е.
    // Третий параметр в данном случае - итератор, который указывает напрямую в cout.
    cout << "Selection: ";
    copy(c.lower_bound("c"), c.upper_bound("t"), ostream_iterator<string>(cout, " "));
    cout << endl;

    return 0; 
}
