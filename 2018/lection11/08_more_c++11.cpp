#include <iostream>
#include <vector>

using namespace std;

const int N = 10;

int main()
{
    // Создаём вектор
    vector<int> v;

    // Заполняем вектор
    for (int i = 0; i < N; i++)
        v.push_back(i);

    // Выводим содержимое вектора при помощи доступа к элементу по индексу
    for (int i = 0; i < N; i++)
        cout << v[i] << " ";
    cout << endl;
    
    // Выводим содержимое вектора при помощи итератора
    for (vector<int>::const_iterator it = v.cbegin(); it != v.cend(); it++)
        cout << *it << " " ;
    cout << endl;
    
    // Выводим содержимое вектора при помощи итератора (с auto)
    // Это специфично для C++11
    for (auto it = v.begin(); it != v.end(); it++)
        cout << *it << " ";
    cout << endl;

    // Выводим содержимое вектора при помощи range-for
    // Это тоже специфично для C++11
    for (const auto& el : v)
        cout << el << " ";
    cout << endl;

    return 0;
}
