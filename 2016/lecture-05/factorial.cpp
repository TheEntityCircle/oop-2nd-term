#include <iostream>

using namespace std;

// Шаблонная функция для вычисления факториала
template<unsigned int n>
unsigned long long int factorial()
{
    return n*factorial<n-1>();
}

// Специализация функции для вычисления факториала
template<>
unsigned long long int factorial<0>()
{
    return 1;
}

int main()
{
    cout << factorial<1>() << endl;
    cout << factorial<2>() << endl;
    cout << factorial<3>() << endl;
    cout << factorial<4>() << endl;
    cout << factorial<5>() << endl;
   
    // Ошибка компиляции!
    // cout << factorial<-1>() << endl;

    return 0;
}
