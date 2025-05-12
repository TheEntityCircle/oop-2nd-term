#include <iostream>
#include <chrono>
#include <random>
using namespace std;

int rand_uns(int min, int max) {
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    static std::default_random_engine e(seed);
    std::uniform_int_distribution<int> d(min, max);
    return d(e);
}

int main()
{
    const unsigned long long int N = 50000000;
    int *from = new int[N];
    int *to = new int[N];
    for (unsigned long long int i = 0; i < N; i++)
    {
        from[i] = rand_uns(0, N - 1);
        to[i] = 0;
    }
    auto start = std::chrono::high_resolution_clock::now();

    for(unsigned long long i = 0; i < N; i++)
        to[i] = from[i] + from[from[i]];

    auto end = std::chrono::high_resolution_clock::now();
    auto nsec = end - start;

    int res = 0;
    for (unsigned long long int i = 0; i < N; i++)
        res += to[i];

    cout << res << " " << nsec.count() / (double)N << endl;

    delete[] from;
    delete[] to;
    return 0;
}
