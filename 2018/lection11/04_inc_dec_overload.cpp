#include <iostream>

using namespace std;

class Number 
{
protected:
    int i;

public:
    Number(int i)
    {
        this->i = i;
    }

    Number(const Number& n)
    {
        this->i = n.i;
    }

    int getNumber()
    {
        return i;
    }

    Number& operator++ ()     // prefix ++
    {
        i++;
        return *this;
    }

    Number  operator++ (int)  // postfix ++
    {
        Number result(*this);
        ++(*this);
        return result;
    }

    Number& operator-- ()     // prefix --
    {
        i--;
        return *this;
    }

    Number  operator-- (int)  // postfix --
    {
        Number result(*this);
        --(*this);
        return result;
    }
};

std::ostream& operator<<(std::ostream& os, Number& n)
{
      os << n.getNumber();
      return os;
}

int main()
{
    Number a(42);
    Number b = a;

    Number c = a++;
    cout << c << endl;

    Number d = ++b;
    cout << d << endl;
    return 0;
}
