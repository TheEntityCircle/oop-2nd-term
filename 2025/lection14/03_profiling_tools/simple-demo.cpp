#include <iostream>

using namespace std;

const long long N = 1000*1000*1000;

void new_func1()
{
    cout << "Inside new_func1" << endl;

    for(int i = 0; i < N; i++);

    return;
}

void func1()
{
    cout << "Inside func1" << endl;

    for(int i = 0; i < N; i++);

    for(int i = 0; i < 4; i++)
        new_func1();

    return;
}

void func2()
{
    cout << "Inside func2" << endl;

    for(int i = 0; i < N; i++);

    return;
}

int main(void)
{
    cout << "Inside main" << endl;

    for(int i = 0; i < N/10; i++);

    func1();
    func2();

    return 0;
}
