#include <concepts>
#include <type_traits>

template <typename U>
concept us = std::is_unsigned_v<U>;

template <typename U>
    requires us<U>
U sum(U a, U b)
{
    return a + b;
}

int main()
{
    unsigned int a = 5, aa = 6;
    float b = 6, bb = 7;

    // Это скомпилируется.
    a = sum(a, aa);

    // А это нет. Обратите внимание на текст ошибки.
    // b = sum(b, bb);
    return 0;
}
