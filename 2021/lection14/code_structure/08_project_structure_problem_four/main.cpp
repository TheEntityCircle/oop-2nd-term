#include <iostream>
#include "stack.hpp"

using namespace std;

int main()
{
    // Стек, содержащий int-ы
    Stack<int> intStack(10);
    // Стек, содержащий char-ы
    Stack<char> charStack(11);

    // Заполняем стеки
    for (int i = 0; i < 10; i++)
    {
        intStack.push(i);
        charStack.push('A'+i);
    }

    // Извлекаем данные из стеков
    for (int i = 0; i < 10; i++)
    {
        cout << intStack.pop() << " " << charStack.pop() << endl;
    }
    
    return 0;
}
