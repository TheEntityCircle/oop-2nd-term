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

    // Так, очевидно, не получится - функция для int-ов, а не string-ов
    //string c = "abc";
    //string d = "def";
    //myswap(c, d);
    //cout << c << " " << d << endl;
    return 0;
}
