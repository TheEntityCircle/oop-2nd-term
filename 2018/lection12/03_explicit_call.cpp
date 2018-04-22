#include <iostream>

using namespace std;

template<typename T>
void print(T x, T y)
{
    cout << x << endl;
    cout << y << endl;
}

int main()
{
    int a = 1;
    long b = 2;

    // Ошибка компиляции
    //print(a, b);

    // Явное указание, какую реализацию вызвать
    // Замечание: это *очень* редко применимо в реальности
    print<long>(a, b);

    return 0;
}
