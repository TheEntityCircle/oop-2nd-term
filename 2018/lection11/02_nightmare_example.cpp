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

    // Ооок, понял от конца к началу идём как обычно оператором ++,
    // только границы правильные используем
    for (vector<int>::iterator it = v.rbegin(); it != v.rend(); it++)
        cout << *it << " ";
    cout << endl;

    return 0;
}
