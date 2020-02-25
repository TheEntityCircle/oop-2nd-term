#include <iostream>
  
using namespace std;

class ClassA {
protected:
    int x;
public:
    ClassA(int a) {
        x = a;
    }

    int getX() const {
        return x;
    }

    void doNothing() { // должен быть const, но это 'забыли'
    }

    int f1() const {
        //x = 0; // это не будет пропущено, this является const
        //doNothing(); // и это не будет, что довольно печально
        return x;
    }

    int f2() const {
        return x;
    }
};

int main() {
    ClassA a(42);
    cout << a.getX() << endl;
    a.f1();
    cout << a.getX() << endl;
    a.f2();
    cout << a.getX() << endl;
    return 0;
}
