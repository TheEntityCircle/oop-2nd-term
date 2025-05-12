#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    // Вывод "как обычно".
    cout << "Hello, world!\n";

    // Явный вызов функции, отвечающей за данную операцию.
    // Это почти как:
    //          void say(ostream& os)
    // только:
    //          ostream& operator<<(ostream& os, const char* s)
    operator<<(cout, "Hello, world!\n");

    return 0;
}
