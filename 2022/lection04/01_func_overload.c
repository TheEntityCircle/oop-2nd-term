#include <stdio.h>

// Этот пример можно считать «полиморфизмом в чистом С».
// Есть функция, которая может обрабатывать данные разных типов.
// Фактически для каждого типа своя реализация функции, но интерфейс единый.

// Правда, собирать этот код на С придётся компилятором С++.

void func(char c)
{
    printf("func(char) called\n");
}

void func(int a)
{
    printf("func(int) called\n");
}

void func(int a, float x) {
    printf("func(int,float) called\n");
}

int main()
{
    func(10);
    func('a');
    func(42, 3.1415926);
    return 0;
}
