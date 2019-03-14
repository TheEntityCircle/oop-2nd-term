#include <iostream>

using namespace std;

void f1(const int& val) {
    //val = 5; // это не будет пропущено компилятором из-за const
}

void f2(const int* valptr) {
    //*valptr = 5; // и это тоже
}

void f3(int val) {
    val = 5; // а это будет, но оно не имеет смысла
}

int main()
{
    int i = 42;
    cout << "Before: " << i << endl;
    f1(i);
    f2(&i);
    f3(i);
    cout << "After: " << i << endl;
    return 0;
}
