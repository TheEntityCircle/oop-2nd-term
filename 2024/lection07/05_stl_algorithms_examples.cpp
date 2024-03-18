#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // Создаём вектор, здесь используется инициализация из C++11
    vector<int> v = { 1, 3, 12, -4, 8, 45, 12, -21 };

    // Выводим вектор на экран
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
        cout << *it << " ";
    cout << endl;

    // Считаем вхождения элемента в вектор
    cout << count(v.begin(), v.end(), 12) << endl;

    // Ищем элемент в векторе
    if(find(v.begin(), v.end(), 5) != v.end())
        cout << "Element found" << endl;
    else
        cout << "Element not found" << endl;

    // Сортируем вектор
    sort(v.begin(), v.end());

    // Выводим вектор на экран
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
        cout << *it << " ";
    cout << endl;

    // Ищем первое вхождение элемента (после сортировки!)
    // Вернёт итератор на первый элемент со значением не меньше заданного
    vector<int>::iterator lb = lower_bound(v.begin(), v.end(), 12);
    cout << "The lower bound is at position: " << lb - v.begin() << endl;

    // Ищем последнее вхождение элемента (после сортировки!)
    // Вернёт итератор на первый элемент со значением больше заданого
    vector<int>::iterator ub = upper_bound(v.begin(), v.end(), 12);
    cout << "The upper bound is at position: " << ub - v.begin() << endl;

    // Переворачиваем вектор
    reverse(v.begin(), v.end());

    // Выводим вектор на экран
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
        cout << *it << " ";
    cout << endl;

    return 0;
}
