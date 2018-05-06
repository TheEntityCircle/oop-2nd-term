#include <iostream>
#include <stdexcept>

using namespace std;

// Опишем свой новый логический exception
class LazyException : public std::runtime_error {
public:
    LazyException() : std::runtime_error("I'm just too lazy today") { }
};

void func1() {
    // Тут происходит какая-то работа

    // Делаем вид, что всё сломалось
    throw LazyException();
    //throw runtime_error("Network is not available! Can not proceed.");

    // Дальше какая-то работа
}

void func2() {
    // Что-то делаем

    func1();

    // Что-то делаем дальше
}

void func3() {
    // Что-то делаем

    func2();

    // Что-то делаем дальше
}

// И так ещё 5 слоёв вызовов.
// Обработка ошибок остаётся полностью:
// (1) на том, кто обнаружил ошибку (бросил exception);
// (2) на том, кто может её обработать (поймал exception).
// Всем слоям между не нужно делать ничего.

int main() {
    try {
        func3();

        // Тут идёт какая-то работа дальше

    } catch (const LazyException& e) {
        cerr << "We failed! Damned function is lazy now. Requires special handling." << endl;
        return -1;
    } catch (const exception& e) {
        cerr << "We failed! And something real happened this time!" << endl;
        cerr << "Failure reason: " << e.what() << endl;
        return -1;
    }

    return 0;
}
