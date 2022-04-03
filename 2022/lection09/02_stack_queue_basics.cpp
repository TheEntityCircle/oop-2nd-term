#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main()
{
    // Создадим стек и очередь "по умолчанию"
    stack<int> s;
    queue<int> q;

    // Запушим в них одни и те же данные
    cout << "Pushing data: ";
    for (int i = 0; i < 5; ++i) {
        cout << i << " ";
        s.push(i);
        q.push(i);
    }
    cout << endl;

    // Посмотрим содержимое стека
    cout << "Stack data: ";
    for (int i = 0; i < 5; ++i) {
        cout << s.top() << " ";     // "заглянем" в верхний элемент
        s.pop();                    // "вытащим" верхний элемент
    }
    cout << endl;
   
    // Посмотрим содержимое очереди 
    cout << "Queue data: ";
    for (int i = 0; i < 5; ++i) {
        cout << q.front() << " ";   // "заглянем" в головной элемент
        q.pop();                    // "вытащим" головной элемент
    }
    cout << endl;
 
    return 0;
}

