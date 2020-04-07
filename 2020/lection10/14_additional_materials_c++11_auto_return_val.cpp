#include <iostream>

using namespace std;

// Это не обязательный материал! Это не обязательно разбирать.
//
// Использовать такое в реальном коде в среднем не очень хорошо, 
// так как резко усложняет его читаемость и повышает вероятность
// поймать плохо отлаживаемые эффекты.

template <typename T, typename E>
auto compose(T a, E b) -> decltype(a+b) // decltype позволяет определить тип на основе входного параметра
{
    return a + b;
}

int main()
{
    auto c = compose(2, 3.14); // c - double
    cout << c << endl;
    return 0;
}
