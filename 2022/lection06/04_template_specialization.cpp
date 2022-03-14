#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;

// Это уместно делать, если *логически* все реализации делают одно и то же.
// Тогда технический трюк, позволяющий обеспечить нюансы реализации, уместен.
// Если реализации делают принципиально разные вещи, то что-то идёт очень неправильно.

// Общая реализация по умолчанию
template<typename T>
void print(const T& x)
{
    cout << x << endl;
}

// Уточнение, что bool хочется выводить строкой true/false
template<> 
void print<bool>(const bool& x)
{
    cout << std::boolalpha << x << endl;
}

// Группу float / double / long double хочется выводить 
// с большим количеством знаков после запятой
template<> 
void print<double>(const double& x)
{
    const int sigdigits = std::numeric_limits<double>::digits10;
    cout << std::setprecision(sigdigits) << x << endl;
}

template<> 
void print<float>(const float& x)
{
    const int sigdigits = std::numeric_limits<float>::digits10;
    cout << std::setprecision(sigdigits) << x << endl;
}

template<> 
void print<long double>(const long double& x)
{
    const int sigdigits = std::numeric_limits<long double>::digits10;
    cout << std::setprecision(sigdigits) << x << endl;
}

int main()
{
    int a = 1;
    bool b = true;
    char c = 'c';
    double d = 1.123456789;

    cout << "=== Default output ===" << endl;

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << d << endl;

    cout << "=== Custom templated print ===" << endl;

    print(a);
    print(b);
    print(c);
    print(d);

    return 0;
}
