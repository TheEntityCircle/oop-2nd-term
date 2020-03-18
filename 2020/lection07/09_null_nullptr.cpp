#include<iostream>

using namespace std;

int f(int x) {
    cout << "f(int) called" << endl;
}

int f(int* p) {
    cout << "f(int*) called" << endl;
}

int main() {
    f(NULL);
    f(nullptr);
    return 0;
}
