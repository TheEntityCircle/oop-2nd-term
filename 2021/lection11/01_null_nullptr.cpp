#include<iostream>

using namespace std;

// Просто некая функция
int f(int x) {
    cout << "f(int) called" << endl;
}

// И ещё одна (перегрузка по параметрам)
int f(int* p) {
    cout << "f(int*) called" << endl;
}

int main()
{
    f(NULL); // это не скомпилируется, потому что NULL - число и указатель одновременно

    f(nullptr); // а вот здесь всё в порядке

    return 0;
}
