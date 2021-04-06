#include <iostream>

using namespace std;

// Считаем, что 0 - код успешного завершения
int func1()
{
    // Тут происходит какая-то работа

    // Делаем вид, что всё сломалось
    return -1;
}

int main()
{
    // Вызов функции
    int res = func1();
    // Обработка возможной проблемы
    if(res != 0) {
        cerr << "Calling func1() failed!" << endl;
        return -1;
    }

    // Тут идёт какая-то работа дальше

    return 0;
}
