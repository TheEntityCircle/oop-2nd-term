#include <iostream>

using namespace std;

template<typename T>
void myswap(T& x, T& y)
{
    T tmp = x;
    x = y;
    y = tmp;
}

int main()
{
    int a = 1;
    int b = 2;
    myswap(a, b);
    cout << a << " " << b << endl;


    // А теперь получится, потому что функция стала шаблонной.
    // Важно: это не 'функция теперь может работать со всеми типами',
    // это 'компилятор по факту сгенерирует две функции с одним алгоритмом'.

    double c = 1.1;
    double d = 2.2;
    myswap(c, d);
    cout << c << " " << d << endl;


    // Шаблоны - не магия, а автоматическая генерация кода.
    // Например, вот так все еще нельзя.

    // myswap(a, c);

    return 0;
}
