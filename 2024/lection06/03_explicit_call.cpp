#include <iostream>
#include <iomanip>

using namespace std;

template<typename T>
void print(T x, T y)
{
    cout << x << endl;
    cout << y << endl;
}

int main()
{
    unsigned long int a = 100000000000;
    float b = 2.71;

    // Ошибка компиляции
    //print(a, b);

    // Явное указание, какую реализацию вызвать
    // Замечание: это *очень* редко применимо в реальности
    // Например, в этом примере точность может пострадать 
    //    - хорошо думайте, что и к чему вы приводите

    cout << "As ints:" << endl;
    print<unsigned long int>(a, b);

    cout << endl << endl << "As floats:" << endl;
    cout << fixed;
    cout << setprecision(6);
    print<float>(a, b);

    return 0;
}
