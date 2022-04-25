#include <iostream>
#include <typeinfo>

using namespace std;

int main()
{
    auto is_even_1 = [](int i) { return 0 == i % 2; };
    auto is_even_2 = [](int i) -> bool { return 0 == i % 2; };

    cout << "type of is_even_1: " << typeid(is_even_1).name() << endl;
    cout << "type of is_even_2: " << typeid(is_even_2).name() << endl;

    return 0;
}

