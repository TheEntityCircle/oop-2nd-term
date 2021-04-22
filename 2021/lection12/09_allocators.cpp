#include <memory>
#include <iostream>
#include <string>

using std::cout;
using std::endl;

int main()
{
    std::allocator<int> a1;   // default allocator for ints
    int* a = a1.allocate(1);  // space for one int

    a1.construct(a, 7);       // construct the int
    cout << a[0] << endl;
    a1.deallocate(a, 1);      // deallocate space for one int
 
    std::allocator<std::string> a2;
    std::string* s = a2.allocate(2); // space for 2 strings

    a2.construct(s, "foo");
    a2.construct(s + 1, "bar");
 
    cout << s[0] << ' ' << s[1] << endl;
 
    a2.destroy(s);
    a2.destroy(s + 1);
    a2.deallocate(s, 2);

    return 0;
}

/*
 * address, max_size, construct, destroy, operator!= будут удалены в C++20
 * Их заменит allocator_traits
 */

/*
 * Прекрасный рассказ по теме, в том числе написание кастомного аллокатора:
 * https://medium.com/@vgasparyan1995/what-is-an-allocator-c8df15a93ed
 */
