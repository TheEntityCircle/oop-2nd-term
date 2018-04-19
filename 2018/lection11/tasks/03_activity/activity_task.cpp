#include <iostream>
#include <string>

using namespace std;

// Нужно реализовать класс Tracker, 
// выдающий сводные показатели активности пользователя
class Tracker
{
public:
    Tracker();

    // При любом действии пользователя вызывается этот метод.
    // Методу передаётся:
    // - какой пользователь совершил действие (username);
    // - когда (timestamp - для простоты условные секунды от начала времён).
    // Внимание: не гарантируется, что timestamp расположены строго по
    // возрастанию, в них может быть любой бардак.
    void click(string username, unsigned long long timestamp);

    // По имени пользователя нужно вернуть, сколько всего было кликов
    unsigned long long getClickCount(string username);

    // Когда был первый клик
    unsigned long long getFirstClick(string username);

    // Когда был последний клик
    unsigned long long getLastClick(string username);
};

int main()
{
    Tracker t;
    t.click("alice", 1000);
    t.click("bob", 1100);
    t.click("alice", 1001);
    t.click("alice", 1200);
    t.click("alice", 1002);
    cout << t.getClickCount("alice") << endl;
    cout << t.getClickCount("bob") << endl;
    cout << t.getFirstClick("alice") << endl;
    cout << t.getFirstClick("bob") << endl;
    cout << t.getLastClick("alice") << endl;
    cout << t.getLastClick("bob") << endl;
    return 0;
}
