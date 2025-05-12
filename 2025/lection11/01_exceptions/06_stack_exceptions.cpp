#include <iostream>
using namespace std;

void g(char x, char b) {
    float mas[100];
    throw 100500;
}

void f() {
    int a, b;
    g('a', 48);
}

int main() {
    int a, b;
    try {
        f();
    }
    catch(int a)
    {
        cout << a << endl; 
    }
    return 0;
}
