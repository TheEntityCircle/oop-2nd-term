#include <iostream>
#include <vector>
#include <algorithm>

#include <chrono>
using namespace std::chrono;

#define SIZE 1000 * 1000 * 1000

int main()
{
    std::vector<double> a = std::vector<double>(SIZE);
    std::fill(a.begin(), a.end(), -1);

    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    double result = 1;
    long i;
    for(i = 0; i < SIZE; i++) {
        result = result * a[i];
    }

    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    duration<double, std::milli> time_span = t2 - t1;
    std::cout << "It took me " << time_span.count() << " milliseconds" << std::endl;

    std::cout << "Res = " << result << std::endl;
    return 0;
}
