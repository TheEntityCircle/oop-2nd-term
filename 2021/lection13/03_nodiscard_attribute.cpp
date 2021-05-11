#include <iostream>

using std::cout;
using std::endl;

// Внимание! Атрибут [[nodiscard]] - это стандарт C++17 (не C++11).
// Ремарка: пример с [[nodiscard]] для конструктора - https://stackoverflow.com/a/60442940

[[nodiscard]] int enable_missile_safety_mode() {
    // Упс, не вышло перейти в безопасный режим
    cout << "WARN: safety mode NOT activated" << endl;
    return -1;
}

void launch_missiles() {
    cout << "Missiles launched" << endl;
}

void test_missiles() {
    enable_missile_safety_mode();
    launch_missiles();
}

int main() {
    test_missiles();
    return 0;
}
