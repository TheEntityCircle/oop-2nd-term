#include <iostream>

using namespace std;

int main()
{
    int* data = new int[10];

    for(unsigned int i = 0; i < 10; i++)
        data[i] = i;

    for(unsigned int i = 0; i < 10; i++)
        cout << data[i] << endl;

    // Ой, забыли
    //delete[] data;

    return 0;
}
