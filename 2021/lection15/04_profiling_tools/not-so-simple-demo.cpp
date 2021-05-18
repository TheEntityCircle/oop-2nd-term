#include <iostream>
  
using namespace std;

const long long N = 1000*1000*1000;

void work(long long n) {
    for(long long i = 0; i < n; i++);
}

void easy()
{
    cout << "Working easy" << endl;
    work(N);
}

void hard()
{
    cout << "Working hard" << endl;
    work(10*N);
}

int main()
{
    easy();
    hard();
    return 0;
}
