#include <iostream>
#include <thread>
#include <atomic>
#include <random>
using namespace std;

int rand_uns(int min, int max) {
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    static std::default_random_engine e(seed);
    std::uniform_int_distribution<int> d(min, max);
    return d(e);
}

const unsigned long long int N = 50000000;
const unsigned long long int N_threads = 4;
int *from = new int[N];
int *to = new int[N];

void transform(unsigned long long i_begin, unsigned long long i_end)
{
    for(unsigned long long i = i_begin; i < i_end; i++)
        to[i] = from[i] + from[from[i]];
}

int main()
{
    for (unsigned long long int i = 0; i < N; i++)
    {
        from[i] = rand_uns(0, N - 1);
        to[i] = 0;
    }

    auto start = std::chrono::high_resolution_clock::now();


    thread ths[N_threads];
    for (int i = 0; i < N_threads; i++)
        ths[i] = thread(transform, i * N / N_threads, (i + 1) * N / N_threads);

    for (int i = 0; i < N_threads; i++)
        ths[i].join();

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
