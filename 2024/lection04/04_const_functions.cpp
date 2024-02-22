#include <iostream>

using namespace std;

void f0(const int val) {
    //val = 5; // это не будет пропущено компилятором из-за const
}

void f1(const int& val) {
    //val = 5; // и это тоже
}

void f2(const int* valptr) {
    //*valptr = 5; // и это
}

void f3(int val) {
    val = 5; // а это будет, но оно не имеет смысла
}

int main()
{
    int i = 42;
    cout << "Before: " << i << endl;
    f0(i);
    f1(i);
    f2(&i);
    f3(i);
    cout << "After: " << i << endl;

/*
    int a_boring_integer = 42, an_alternative_integer = 41;
    int* const const_pointer_to_int = &a_boring_integer;
    const_pointer_to_int = &an_alternative_integer; // нельзя
    *const_pointer_to_int = 666;                    // можно

    int const* pointer_to_const_int = &a_boring_integer;
    // можно писать const int*, работает так же
    pointer_to_const_int = &an_alternative_integer; // можно
    *pointer_to_const_int = 666;                    // нельзя

    int const* const const_pointer_to_const_int = &a_boring_integer;
    const_pointer_to_const_int = &an_alternative_integer; // нельзя
    *const_pointer_to_const_int = 666;                    // и так нельзя
*/

    return 0;
}
