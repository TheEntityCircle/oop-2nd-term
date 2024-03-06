#include <iostream>
#include <iomanip>

using namespace std;

template<typename T, typename Y>
void print(T x, Y y)
{
    cout << x << endl;
    cout << y << endl;
}

int main()
{
    unsigned long int a = 100000000000;
    float b = 2.71;

    // Теперь так можно
    print(a, b);

    // И сломать все тоже можно
    // Явный вызов реализации - почти всегда плохая идея
    cout << "Broken::" << endl << fixed << setprecision(2);
    print<float, unsigned long int>(a, b);
    return 0;
}
