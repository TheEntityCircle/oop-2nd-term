#include <iostream>
#include <vector>

using namespace std;

int main()
{
    const unsigned int N = 5;

    // Создаём вектор
    // <int> - это про те самые template-ы, с изнанкой которых будем разбираться позже
    vector<int> v;

    // Заполняем вектор
    for (unsigned int i = 0; i < N; i++)
        v.push_back(i);

    // Выводим содержимое вектора при помощи доступа к элементу по индексу
    for (unsigned int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;

    // Добавим ещё данных
    for (unsigned int i = 0; i < N; i++)
        v.push_back(i);

    // Изменяем содержимое вектора при помощи доступа к элементу по индексу
    for (unsigned int i = 0; i < v.size(); i++)
        v[i] *= 2;

    // Снова выводим на экран
    for (unsigned int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;

    return 0;
}
