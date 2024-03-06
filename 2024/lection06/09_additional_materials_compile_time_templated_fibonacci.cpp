#include <iostream>

// Шаблон для N-го числа,
// компилятор сгенерирует множество структур со значениями внутри
template <unsigned N>
struct Fibonacci
{
    static const unsigned long long value = Fibonacci<N-1>::value + Fibonacci<N-2>::value;
};

// Специализация шаблонов для чисел 0, 1, 2,
// остановка 'компиляторной рекурсии'

template <>
struct Fibonacci<0>
{
    static const unsigned long long value = 0;
};

template <>
struct Fibonacci<1>
{
    static const unsigned long long value = 1;
};

template <>
struct Fibonacci<2>
{
    static const unsigned long long value = 1;
};


int main()
{
    // Это сработает только для значений, которые известны на этапе копиляции
    std::cout << Fibonacci<42>::value << std::endl;

    // Так нельзя, значение num не известно на этапе копиляции
    //unsigned num;
    //std::cin >> num;
    //std::cout << Fibonacci<num>::value << std::endl;

    return 0;
}
