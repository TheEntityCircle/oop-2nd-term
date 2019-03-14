#include <iostream>  // Базовые потоки ввода-вывода
#include <fstream>   // Файловые потоки ввода-вывода
#include <iomanip>   // Для std::setprecision

using namespace std;

int main()
{
    double d;
    // Считаем из стандартного потока ввода
    cin >> d;
    // Выведем в стандартный поток вывода
    cout << "Input was: " << d << endl;
   
    d = 1.2345;
    cout << "Default out: " << d << endl;
    // cin и cout - это объекты, у которых есть своё состояние.
    // Например, укажем cout, сколько хотим знаков при выводе.
    cout << setprecision(4);
    // Выставленное значение применяется для всего ниже.
    // Был выставлен параметр *потоку*, а не конкретной операции.
    cout << "Out with setprecision(4):   " << d << endl;
    cout << "Out with setprecision(4): " << 100 * d << endl;

    // Выставим новые параметры потоку
    cout << setprecision(9);
    cout << fixed;
    cout << "Out with setprecision(9) and fixed:   " << d << endl;
    cout << "Out with setprecision(9) and fixed: " << 100 * d << endl;

    return 0;
}
