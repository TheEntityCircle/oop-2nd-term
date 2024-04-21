#include <cstdint>
#include <iostream>
 
int main()
{
    int i = 7;
 
    // static_cast дает ошибку компиляции
    // std::uintptr_t v1 = static_cast<std::uintptr_t>(&i);
    // а reinterpret_cast позволяет
    std::uintptr_t v1 = reinterpret_cast<std::uintptr_t>(&i);
    std::cout << "The value of &i is " << std::showbase << std::hex << v1 << '\n';
    int* p1 = reinterpret_cast<int*>(v1);
 
    return 0;
}
