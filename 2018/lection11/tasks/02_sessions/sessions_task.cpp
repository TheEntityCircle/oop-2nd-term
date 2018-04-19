#include <iostream>
#include <set>

using namespace std;

// Класс, управляющий пользовательскими сессиями
class SessionManager
{
public:
    // Вход пользователя.
    // Один пользователь может войти несколько раз подряд, 
    // считать его при этом нужно один раз.
    void login(string username);

    // Выход пользователя.
    // Пользователь может выйти несколько раз подряд, 
    // падать при этом не нужно.
    void logout(string username);

    // Сколько сейчас пользователей залогинено.
    int getNumberOfActiveUsers();
};

int main()
{
    SessionManager m;
    m.login("alice");
    cout << m.getNumberOfActiveUsers() << endl;
    m.login("bob");
    cout << m.getNumberOfActiveUsers() << endl;
    m.login("alice");
    cout << m.getNumberOfActiveUsers() << endl;
    m.logout("whoever");
    cout << m.getNumberOfActiveUsers() << endl;
    m.logout("alice");
    cout << m.getNumberOfActiveUsers() << endl;
    m.logout("bob");
    cout << m.getNumberOfActiveUsers() << endl;
    return 0;
}
