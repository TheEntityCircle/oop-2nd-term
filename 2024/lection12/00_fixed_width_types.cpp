#include <cstdio>  // Вывод на экран С
#include <cstdint> // Типы фиксированной ширины

int main()
{
    int32_t a = -1;
    int64_t b = -2;
    
    uint8_t c = 49;
    uintmax_t d = -1;

    // Для форматированного вывода с явным указанием типа
    // бывает проще взять вывод на экран из С
    printf("-1 as int32_t is %x\n", a);
    printf("-2 as int64_t is %x%x\n", (uint32_t)(b >> 32), (uint32_t)b);
    printf("49 as character in uint8_t is %c\n", c);
    printf("the biggest uint here is %lu bytes\n", sizeof(d));
    return 0;
}

// За полным списком сюда: https://en.cppreference.com/w/cpp/types/integer
