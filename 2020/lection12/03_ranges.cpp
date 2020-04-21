#include <iostream>
#include <vector>

// Так станет можно для компиляторов с полной поддержкой C++20
// (см. https://en.cppreference.com/w/cpp/compiler_support)
//#include <ranges>

// Пока что так - отдельная библиотека, в ней черновик стандарта
#include <range/v3/all.hpp>

using namespace std;
// Не будем сейчас подключать namespace ranges, 
// чтобы в коде явно было видно, что откуда пришло
//using namespace ranges;
 
int main()
{
    // Данные
    vector<int> data = {0, 1, 2, 3, 4, 5};

    // Лямбда-функция, возвращает bool, логически "фильтр"
    auto even = [](int i) { return 0 == i % 2; };

    // Лямбда-функция, возвращает значение, логически "преобразователь"
    auto square = [](int i) { return i * i; };
 
    // Используется operator|, логически это "труба с данными":
    // - каждый элемент вектора с данными передаётся фильтру,
    // - результаты фильтрации передаются преобразователю,
    // - результаты преобразования попадают в тело цикла.
    for (int i : data | ranges::views::filter(even) | ranges::views::transform(square)) {
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}
