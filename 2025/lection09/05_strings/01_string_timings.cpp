#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <cstdlib>
#include <chrono>

using namespace std;

int main()
{
    // Задаём количество элементов
    int n;
    cin >> n;
    int repeats;
    cin >> repeats;
 
    deque<unsigned int> time_of_push_back(n, 0);
    deque<unsigned int> time_of_push_back_reserve(n, 0);

    // Заполняем вектор и измеряем время
    for (int r = 0; r < repeats; r++)
    {   
        string s;
        for (int i = 0; i < n; i++)
        {
            auto start = std::chrono::high_resolution_clock::now();
            s += 'A';
            auto end = std::chrono::high_resolution_clock::now();
            auto nsec = end - start;
            time_of_push_back[i] += nsec.count();
        }
    }

    for (int r = 0; r < repeats; r++)
    {
        string s;
        s.reserve(n);
        for (int i = 0; i < n; i++)
        {
            auto start = std::chrono::high_resolution_clock::now();
            s += 'A';
            auto end = std::chrono::high_resolution_clock::now();
            auto nsec = end - start;
            time_of_push_back_reserve[i] += nsec.count();
        }
    }
   
    for (int i = 0; i < n; i++)
    {
        cout << i << ", " << time_of_push_back[i] << ", " << time_of_push_back_reserve[i] << endl;
    }

    return 0;
}
