#include <iostream>
#include <vector>

using namespace std;

const unsigned int N = 5;

int main()
{
    // Создаём вектор
    // <int> - это про те самые template-ы, с изнанкой которых будем разбираться позже
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

    // Снова выводим на экран, теперь в обратном порядке
    for (vector<int>::reverse_iterator it2 = v.rbegin(); it2 != v.rend(); it2++)
        cout << *it2 << " ";
    cout << endl;

    return 0;
}
