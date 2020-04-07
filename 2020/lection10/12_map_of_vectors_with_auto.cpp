#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    // Есть map-а с vector-ами в ней
    map<string, vector<int>> map;

    vector<int> v = {1, 2, 3};
    map["one"] = v;

    map["two"] = {4, 5, 6};

    // Обойдём всю конструкцию
    // kv -- элемент map-ы, то есть pair
    for(const auto &kv: map) 
    {
        // Поле kv.first -- ключ в map-е (т.е. строка)
        cout << "Key: " << kv.first << endl;

        // Поле kv.second -- значение в map-e (т.е. вектор)
        // v -- элемент уже вектора
        for(const auto &v: kv.second)
            cout << "Value: " << v << endl;
    }

    return 0;
}
