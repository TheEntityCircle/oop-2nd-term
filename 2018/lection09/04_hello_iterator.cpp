#include <iostream>
#include <vector>

using namespace std;

const unsigned int N = 5;

int main()
{
    // Создаём вектор
    vector<int> v;

    // Заполняем вектор
    for (unsigned int i = 0; i < N; i++)
        v.push_back(i);

    // Объявляем итератор it
    vector<int>::iterator it;

    // Обходим вектор при помощи итератора.
    // Чтобы уложить эту запись в голове:
    // - нужно вспомнить "настоящее" значение трёх частей for-а
    // - можно считать итератор аналогом указателя (вообще это не так, но на сейчас сойдёт)
    for (it = v.begin(); it != v.end(); it++)
        cout << *it << " ";
    cout << endl;

    // Добавим ещё данных
    for (unsigned int i = 0; i < N; i++)
        v.push_back(i);

    // Вставим значение в середину (по итератору, который возникает "на лету")
    v.insert(v.begin() + N, 42);

    // Снова выводим на экран (переменная итератора уже новая)
    for (vector<int>::iterator it2 = v.begin(); it2 != v.end(); it2++)
        cout << *it2 << " ";
    cout << endl;

    return 0;
}
