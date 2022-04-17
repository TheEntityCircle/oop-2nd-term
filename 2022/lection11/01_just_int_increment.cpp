#include <iostream>

using namespace std;

int main()
{
    int a = 42;
    int b = 42;

    // Постфиксный ++
    // Сначала выполняется присваивание, потом ++
    int c = a++;
    cout << c << endl;

    // Префиксный ++
    // Сначала ++, потом присваивание
    int d = ++b;
    cout << d << endl;
    return 0;
}
