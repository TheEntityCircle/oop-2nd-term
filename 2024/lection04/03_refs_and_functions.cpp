#include <iostream>

using namespace std;

// Функция обмена значений переменных, принимающая аргументы по указателю
void pswap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// Функция обмена значений переменных, принимающая аргументы по ссылке
void rswap(int& a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

// Функция обмена значений переменных, принимающая аргументы по значению
void vswap(int a, int b)
{
    int t = a;
    a = b;
    b = t;
}

int main()
{
    int a = 1;
    int b = 2;
    cout << "a: " << a << ", b: " << b << endl;

    // Эта функция не работает! Она меняет значения временных переменных
    vswap(a, b);
    cout << "a: " << a << ", b: " << b << endl;
    
    // Эта работает
    rswap(a, b);
    cout << "a: " << a << ", b: " << b << endl;
    
    // И эта тоже
    pswap(&a, &b);
    cout << "a: " << a << ", b: " << b << endl;

    return 0;
}
