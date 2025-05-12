#include <functional>
#include <iostream>
#include <memory>
#include <random>

using namespace std;

void f(int n1, int n2, int n3, const int& n4, int n5)
{
    std::cout << n1 << ' ' << n2 << ' ' << n3 << ' ' << n4 << ' ' << n5 << '\n';
}

int main()
{
    using namespace std::placeholders;

    cout << "Just calling f: " << endl;
    f(1, 2, 3, 4, 5);
    
    int n = 100500;
    // А это биндинг - обёртка функции под другой интерфейс
    auto f1 = std::bind(f, _2, 42, _1, std::cref(n), n);
    
    cout << "Calling f from bind: " << endl;
    n = 239;
    f1(1, 2, 1001);

    // Очень умная штука - умеет и в лямбды, и в методы
    // Можете сами поэкспериментировать

    // И время работы померить

    return 0;
}
