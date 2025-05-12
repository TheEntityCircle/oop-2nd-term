#include <iostream>
#include <vector>
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
 
    vector<unsigned int> time_of_push_back(n, 0);
    vector<unsigned int> time_of_push_back_reserve(n, 0);

    // Заполняем вектор и измеряем время
    for (int r = 0; r < repeats; r++)
    {   
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            auto start = std::chrono::high_resolution_clock::now();
            v.push_back(i);
            auto end = std::chrono::high_resolution_clock::now();
            auto nsec = end - start;
            time_of_push_back[i] += nsec.count();
        }
    }

    for (int r = 0; r < repeats; r++)
    {
        vector<int> v;
        v.reserve(n);
        for (int i = 0; i < n; i++)
        {
            auto start = std::chrono::high_resolution_clock::now();
            v.push_back(i);
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
