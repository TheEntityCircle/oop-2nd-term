#include <iostream>
#include <vector>
#include <algorithm>

#include <chrono>
using namespace std::chrono;

#define SIZE 1000 * 1000 * 1000

int main()
{
    double* a = new double[SIZE];
    std::uninitialized_fill(a, a + SIZE, -1.0);

    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    double result = 1;
    long i;
    double x0 = 1;
    double x1 = 1;
    double x2 = 1;
    double x3 = 1;
    double x4 = 1;
    double x5 = 1;

    for (i = 0; i < SIZE - 5; i += 6) {
        x0 = x0 * a[i];
        x1 = x1 * a[i + 1];
        x2 = x2 * a[i + 2]; 
        x3 = x3 * a[i + 3];
        x4 = x4 * a[i + 4];
        x5 = x5 * a[i + 5];
    }
    for (; i < SIZE; i++) {
        x0 = x0 * a[i];
    }
    result = x0 * x1 * x2 * x3 * x4 * x5;

    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    duration<double, std::milli> time_span = t2 - t1;
    std::cout << "It took me " << time_span.count() << " milliseconds" << std::endl;

    std::cout << "Res = " << result << std::endl;

    delete[] a;
    return 0;
}
