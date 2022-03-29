#include <iostream>
#include <vector>

using namespace std;

int main()
{
    const int N = 10;

    // Создаём вектор
    vector<int> v;

    // Заполняем вектор
    for (int i = 0; i < N; ++i)
        v.push_back(i);

    // Выводим содержимое вектора при помощи итератора (с auto)
    // Это специфично для C++11
    for (auto it = v.begin(); it != v.end(); ++it)
        cout << *it << " ";
    cout << endl;

    // Выводим содержимое вектора при помощи range-for
    // Это тоже специфично для C++11
    for (const auto& el : v)
        cout << el << " ";
    cout << endl;

    return 0;
}
