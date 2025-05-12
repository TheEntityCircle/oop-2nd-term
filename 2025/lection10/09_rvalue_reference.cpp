#include <iostream>
using namespace std;

void f(int& p)
{
    p = 10;
}

int global_a = 0; // Например, статическая переменная в большом проекте
void f_lawful_neutral(int& p) // Актуальнее, если не int, а что-то большое
{
    global_a += p;
}

void f_chaotic_neutral(int&& p) // А вот и rvalue-reference
{
    global_a += p;
}

void f_lawful_good(const int& p) // Тоже будет работать с rvalue
{
    global_a += p;
}

int main()
{
    int a = 5;
    f(a); // Так можно
    // f(5); // Так нельзя

    f_lawful_neutral(a); // Так можно
    // f_lawful_neutral(5); // Так нельзя
    cout << global_a << endl;

    f_chaotic_neutral(5); // Теперь так можно
                        // Будет создана временная локальная переменная
    // f_chaotic_neutral(a); // А так теперь нельзя лол

    f_chaotic_neutral(move(a)); // Вот так можно
                              // С точки зрения компилятора, мы должны
                              // явно сказать, что с этой переменной 
                              // можно обращаться как с временной
                              // В том числе, непредсказуемо менять,
                              // так что аккуратнее с этой механикой
    cout << global_a << endl;

    // А вот так сработают оба варианта
    // В данном случае такой подход наиболее правильный
    // Поэтому и работает штатно
    f_lawful_good(a); 
    f_lawful_good(5);
    cout << global_a << endl;
    return 0;
}
