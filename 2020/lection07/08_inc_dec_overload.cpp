#include <iostream>

using namespace std;

// Модельный класс, просто хранит одно число
class Number 
{
private:
    int i;

public:
    // Конструктор из int-а
    Number(int i): i(i) {}

    // Конструктор из другого Number-а
    Number(const Number& n): i(n.i) {}

    int getNumber() const {
        return i;
    }

    // prefix ++
    Number& operator++ () {
        i++;
        return *this;
    }

    // postfix ++
    Number operator++ (int) {
        Number result(*this);
        ++(*this);
        return result;
    }

    // prefix --
    Number& operator-- () {
        i--;
        return *this;
    }

    // postfix --
    Number operator-- (int) {
        Number result(*this);
        --(*this);
        return result;
    }
};

std::ostream& operator<<(std::ostream& os, Number& n) {
      os << n.getNumber();
      return os;
}

int main()
{
    Number a(42);
    Number b = a;

    Number c = a++;
    cout << "c = " << c << endl;

    Number d = ++b;
    cout << "d = " << d << endl;
    return 0;
}
