#include <iostream>

using namespace std;

int main()
{
    int i = 7;
    const int& cri = i;
    // Так нельзя   
    // cri = 5;
    // А так можно
    int& ri = const_cast<int&>(cri);
    ri = 5;
    cout << "backdoored i is " << i << endl;

    const int ci = 7;
    // Так нельзя
    // ci = 5;
    // А вот так можно, но с нюансом    
    int& backdoor_ci = const_cast<int&>(ci);
    backdoor_ci = 5;
    cout << "backdoored ci is " << ci << endl;

    return 0;
}
