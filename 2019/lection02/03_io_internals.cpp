#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int a = 1;
    float f = 2.0;
    double d = 3.0;

    // «Классический» вывод
    printf("%d %f %f\n", a, f, d);

    // Вывод «в плюсовом стиле» с использованием перегруженных операторов
    cout << a << " " << f << " " << d << endl;

    // Вывод через перегруженный оператор
    cout << "Hello, world!\n";
    // Явный вызов функции, отвечающей за перегрузку оператора
    operator<<(cout, "Hello, world!\n");

    return 0;
}
