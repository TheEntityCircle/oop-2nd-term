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
    string c = "abc";
    string d = "def";
    myswap(c, d);
    cout << c << " " << d << endl;
    return 0;
}
