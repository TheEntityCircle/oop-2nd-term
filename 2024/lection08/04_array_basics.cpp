#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <string>

using namespace std; 

int main()
{
    // Вот так их объявлять и инициализировать
    // Первый аргумент - тип, второй - размер.
    // Как и у С-style статического массива,
    // размер должен задаваться константой.
    array<int, 3> a_stl = {1, 2, 3};

    // Вот аналог из C-style.
    int a_cstyle[3] = {9, 5, 6};

    // Обращение к элементам через оператор []
    cin >> a_stl[1];
    cout << "You typed " << a_stl[1] << endl;

    // Для std::array работают итераторы
    // и алгоритмы STL.
    sort(a_stl.begin(), a_stl.end());

    cout << "Sorted std::array: ";
    for (array<int, 3>::iterator it = a_stl.begin(); it != a_stl.end(); ++it)
        cout << *it << " ";
    cout << endl;
    cout << "Sorted std::array via rbf: ";
    for (auto x : a_stl)
        cout << x << " ";
    cout << endl;

    // Вообще-то для обычных массивов и 
    // сырых указателей тоже сработает.
    // Но не все, не всегда, и выглядит сильно иначе.
    sort(a_cstyle, a_cstyle + 3);

    cout << "Sorted C-style array: ";
    for (int i = 0; i < 3; i++)
        cout << a_cstyle[i] << " ";
    cout << endl;
    cout << "Sorted C-style via rbf: ";
    for (auto x : a_cstyle)
        cout << x << " ";
    cout << endl;

    // Инициализация по умолчанию.
    array<int, 5> a_zeroes{}; // все нули
    array<int, 5> a_one_and_zeroes{1, 2, 3}; // вначале единичка, потом нули
    array<int, 5> a_uninitialized; // неинициализированный массив

    // Если мы хотим идти по трем контейнерам сразу, 
    // итераторы использовать не очень удобно.
    // А range-based for вообще не вариант.
    for (int i = 0; i < 5; i++)
        cout << a_zeroes[i] << '\t' << a_one_and_zeroes[i] << '\t' << a_uninitialized[i] << endl;
    cout << endl;
    
    return 0;
}
