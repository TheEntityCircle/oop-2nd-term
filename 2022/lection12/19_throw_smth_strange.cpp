#include <iostream>
#include <vector>

using namespace std;

void f1() {
    throw 42;
}

void f2() {
    vector<int> v = {1, 2, 3};
    throw v;
}

void f3() {
    throw 'a';
}

int main ()
{
    try {
        f1();
        f2();
        f3();
    } catch (int e) {
        cout << "An exception occurred. The number is: " << e << endl;
    } catch (vector<int> e) {
        cout << "An exception occurred. Data size: " << e.size() << endl;
        for(auto i : e) {
            cout << i << endl;
        }
    } catch (...) {
        cout << "An exception occurred. And I have no special case for it." << endl;
    }

    return 0;
}

/*
 * Но вообще не надо так. Исключения должны логически описывать проблему.
 * Выдержка из документации по базовым типам:
 * - std::exception : An exception and parent class of all the standard C++ exceptions.
 * - std::logic_error : An exception that theoretically can be detected by reading the code.
 * - std::runtime_error : An exception that theoretically cannot be detected by reading the code.
 */
