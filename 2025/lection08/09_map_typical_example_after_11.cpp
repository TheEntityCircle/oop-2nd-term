#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main()
{
    // Это будет частотный словарь.
    // Ключ - слово, значение - сколько раз оно встретилось.
    map<string,int> words;

    // Эта инициализация вектора специфична для C++11
    vector<string> input = {"hello", "world", "hello", "foo", "bar"};

    for(auto s : input)
    {
        cout << "Adding into map: " << s << endl;
        words[s]++;  // Здесь мы неявно пользуемся тем, 
                            // что контейнер гарантирует нам инит по умолчанию, 
                            // который для int даст 0.
    }

    // Здесь it - итератор по map-е.
    // У элементов map-ы два поля, first - ключ, second - значение.
    for (auto p : words)
    {
        cout << p.first << ": " << p.second << endl;
    }

    return 0;
}
