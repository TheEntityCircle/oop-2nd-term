#include <iostream>
#include <vector>

using namespace std;

const int N = 10;

// Перегруженный оператор вывода содержимого вектора
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
    for (const auto& el: v)
        os << el << " ";
    return os;
}

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
    for (auto it = v.begin(); it != v.end(); it++)
        cout << *it << " ";
    cout << endl;


    // Выводим содержимое вектора при помощи range-for
    for (const auto& el: v)
        cout << el << " ";
    cout << endl;

    cout << endl << "----------------------------" << endl << endl;

    // Изменяем содержимое вектора при помощи доступа к элементу по индексу
    for (int i = 0; i < N; i++)
        v[i] *= 2;

    cout << v << endl;

    // Изменяем содержимое вектора при помощи итератора
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
        *it *= 2;
    
    cout << v << endl;
    
    // Изменяем содержимое вектора при помощи итератора (с auto)
    for (auto it = v.begin(); it != v.end(); it++)
        *it *= 2;

    cout << v << endl;
    
    // Изменяем содержимое вектора при помощи range-for
    for (auto& el: v)
        el *= 2;
    
    cout << v << endl;


    return 0;
}
