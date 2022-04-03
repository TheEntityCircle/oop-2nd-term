#include <iostream>

using namespace std;

// Функция, которая инкрементит свой аргумент
int inc(int x) {
    return x + 1;
}

// Функтор, который делает то же самое
class increment 
{ 
private: 
    // На сколько будем инкрементить
    int num; 

public:
    // Конструктор
    increment(int n) : num(n) {
    }

    // Перегруженный оператор ()
    // Позволяет "вызвать" объект аналогично функции
    int operator() (int x) const { 
        return x + num;
    } 
}; 

int main()
{
    int a = 1;
    // Вызов функции
    cout << "inc(): " << inc(a) << endl;

    // Вызов функтора
    increment inc1(1);
    increment inc2(2);
    cout << "inc1(): " << inc1(a) << endl;
    cout << "inc2(): " << inc2(a) << endl;

    return 0;
}
