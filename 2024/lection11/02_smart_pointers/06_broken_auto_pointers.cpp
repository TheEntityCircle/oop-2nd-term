#include <iostream>
#include <string>
#include <memory>

using namespace std;

void f(auto_ptr<int> x)
{
    cout << *x << endl;
}

int main()
{
    auto_ptr<int> a = auto_ptr<int>(new int(100));
    f(a);
    cout << *a << endl;
    return 0;
}
