#include <iostream>
#include <vector>

// Это приехало в стандарте С++20.
// Компилировать надо с флагом -std=c++20
#include <ranges>

// На более старых компиляторах было так.
// И флаг был такой: -std=c++2a
// #include <range/v3/all.hpp>
// Но если хочется работать с новыми стандартами, 
// то лучше поставить более новую версию компилятора.
// Инструкции, как собрать максимально новую версию:
// https://github.com/TheEntityCircle/lfb-2nd-term/tree/main/lab_7#0-сборка-компилятора-из-исходников.

using namespace std;
// Не будем сейчас подключать namespace ranges, 
// чтобы в коде явно было видно, что откуда пришло
//using namespace ranges;
 
int main()
{
    // Данные
    vector<int> data = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    for (int i : data) {
        cout << i << ' ';
    }
    cout << endl;

    // Лямбда-функция, возвращает bool, логически "фильтр"
    auto is_even = [](int i) { return 0 == i % 2; };

    // Лямбда-функция, возвращает значение, логически "преобразователь"
    auto square = [](int i) { return i * i; };
 
    // Используется operator|, логически это "труба с данными":
    // - каждый элемент вектора с данными передаётся фильтру,
    // - результаты фильтрации передаются преобразователю,
    // - результаты преобразования попадают в тело цикла.
    for (int i : data | ranges::views::filter(is_even) | ranges::views::transform(square)) {
        cout << i << ' ';
    }
    cout << endl;

    // Пропустим первые два элемента из данных, а из следующих трёх выведем только чётные
    for (int i : data | ranges::views::drop(2) 
                      | ranges::views::take(3) 
                      | ranges::views::filter(is_even))
    {
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}
