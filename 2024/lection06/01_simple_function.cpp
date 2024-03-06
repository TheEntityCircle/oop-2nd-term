#include <iostream>

using namespace std;

void myswap(int& x, int& y)
{
    int tmp = x;
    x = y;
    y = tmp;
}

int main()
{
    int a = 1;
    int b = 2;
    myswap(a, b);
    cout << a << " " << b << endl;


    // Попытка использовать ровно ту же функцию для double
    // в надежде, что оно "само как-нибудь приведет типы"
    // приводит к сложной ошибке. 
    // Разбирать ее детально мы будем позже.

    // double c = 1.1;
    // double d = 2.2;
    // myswap(c, d);
    // cout << c << " " << d << endl;
    return 0;
}
