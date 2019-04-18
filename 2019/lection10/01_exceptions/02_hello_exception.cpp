#include <iostream>
#include <stdexcept>

using namespace std;

// Считаем, что 0 - код успешного завершения
int func1() {
    // Тут происходит какая-то работа

    // Делаем вид, что всё сломалось
    throw runtime_error("I'm func1. I can not do my work. I'm just too lazy today.");

    // Нормальное завершение работы
    return 0;
}

int main() {
    try {
        func1();

        // Тут идёт какая-то работа дальше

    } catch (const exception& e) {
        cerr << "We failed!" << endl;
        cerr << "Failure reason: " << e.what() << endl;
        return -1;
    }

    return 0;
}
