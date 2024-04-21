#include <iostream>
#include <stdexcept>

using namespace std;

// Функция теперь void, ей не нужно возвращать статус
void func1()
{
    // Тут происходит какая-то работа

    // Делаем вид, что всё сломалось
    throw runtime_error("I'm func1. I can not do my work. I'm just too lazy today.");

    // Если требуется, работаем дальше
}

int main()
{
    try {
        // Вызов функции
        func1();

        // Тут идёт какая-то работа дальше

    // Обработка возможной проблемы
    } catch (const exception& e) {
        cerr << "We failed!" << endl;
        cerr << "Failure reason: " << e.what() << endl;
        return -1;
    }

    return 0;
}
