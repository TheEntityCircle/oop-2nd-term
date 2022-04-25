// Адаптированный пример с https://www.geeksforgeeks.org/g-fact-33/

#include<iostream>
using namespace std;

class B { /* public: virtual ~B() = default; */ };
class D: public B {};
  
int main()
{
    B *b = new D();
    D *d = dynamic_cast<D*>(b);
    if(d != nullptr)
        cout << "It works" << endl;
    else
        cout << "Cannot cast B* to D*" << endl;

    return 0;
}
