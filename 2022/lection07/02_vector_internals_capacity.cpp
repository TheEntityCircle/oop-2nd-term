#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main()
{
    // Создаём вектор
    vector<int> v;

    // Задаём количество элементов
    int n;
    cin >> n;

    // Если сделать resize сразу на нужный размер, то всё будет хорошо.
    // Но сначала стоит посмотреть поведение без resize-а.
    // v.resize(n);

    cout << "size: " << v.size() << ", " << "capacity: " << v.capacity() << endl;

    // Заполняем вектор
    for (int  i = 0; i < n; i++)
    {
        v.push_back(i);
        cout << "size: " << v.size() << ", " << "capacity: " << v.capacity() << endl;
    }

    return 0;
}
