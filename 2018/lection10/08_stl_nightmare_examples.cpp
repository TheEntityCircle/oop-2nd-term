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

    // Первый пример ужаса
    //for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it--)
    //    cout << *it << " ";
    //cout << endl;

    // Второй пример ужаса
    //for (vector<int>::iterator it = v.rbegin(); it != v.rend(); it++)
    //    cout << *it << " ";
    //cout << endl;

    return 0;
}
