#include <iostream>
#include <vector>

using namespace std;

// Притворимся, что это класс буфера под строку
class String {
public:
    // Этот конструктор выделяет пустой блок памяти заданного размера
    String(int n) {
        cout << "Allocating buffer for " << n << " symbols" << endl;
    };

    // А этот - копирует переданную строку, создав буфер под неё
    String(const char *p) {
        cout << "Allocating buffer to copy " << p << endl;
    };
};

// Аналогичный класс, но конструкторы explicit
class StrictString {
public:
    explicit StrictString(int n) {
        cout << "Allocating buffer for " << n << " symbols" << endl;
    };

    explicit StrictString(const char *p) {
        cout << "Allocating buffer to copy " << p << endl;
    };
};

int main()
{
    // Эти сработают как интуитивно ожидается
    String s1(8);           // OK: direct initialization
    String s2 = 8;          // OK: copy initialization
    String s3 = (String)8;  // OK: explicit cast

    // И этот тоже
    String s4 = "AZAZA";

    // А вот тут будет упс
    String s5 = 'x';

    cout << "===================" << endl;

    StrictString ss1(8);                // OK
    StrictString ss2 = 8;               // Ошибка компиляции
    StrictString ss3 = (StrictString)8; // OK: явный cast превратится в static_cast, который сработает

    StrictString ss4 = "AZAZA";         // Это тоже не компилируется

    StrictString ss5 = 'x';             // И это тоже не компилируется

    return 0;
}
