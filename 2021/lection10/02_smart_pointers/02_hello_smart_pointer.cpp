#include <iostream>
#include <memory> // для smart pointer-ов

using namespace std;

// Smart pointer-ы появились в C++11.
// Более старые компиляторы это не соберут.

int main()
{
    unique_ptr<int[]> data = unique_ptr<int[]>(new int[10]);

    for(unsigned int i = 0; i < 10; i++)
        data[i] = i;

    for(unsigned int i = 0; i < 10; i++)
        cout << data[i] << endl;

    // Теперь и не надо. За очистку памяти отвечает smart pointer.
    //delete[] data;

    return 0;
}
