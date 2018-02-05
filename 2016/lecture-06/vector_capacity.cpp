#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv)
{
    // Создаём вектор
    vector<int> v;

    // Определяем количество элементов
    int n = atoi(argv[1]);

    cout << "size: " << v.size() << ", " << "capacity: " << v.capacity() << endl;

    // Заполняем вектор
    for (int  i = 0; i < n; i++)
    {
        v.push_back(i);
        cout << "size: " << v.size() << ", " << "capacity: " << v.capacity() << endl;
    }

    return 0;
}
