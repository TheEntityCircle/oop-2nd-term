#include <iostream>
using namespace std;

void f(int& p)
{
    p = 10;
}

int main()
{
    int a = 5;
    int b = a + 3;
    // a + 1 = 6; // Так нельзя
   
    int *p = nullptr;
    // p = &(a + 4); // И так нельзя

    p = new int[30];
    p++; // Можно, но опасно
    int arr[10];
    // arr++; // Так нельзя
    delete[] (p - 1); // Удаление будет с приколами

    f(a); // Так можно
    // f(a + 1); // Так нельзя
    return 0;
}
