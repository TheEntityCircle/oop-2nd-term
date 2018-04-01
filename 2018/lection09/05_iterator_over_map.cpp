#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// Этот пример не претендует на нормальный обзор map.
// На данный момент пример здесь с двумя целями:
// - показать итератор на контейнере, отличном от квази-массива,
// - порадовать наличием удобного инструмента для решения задания.
// К подробностям map ещё вернёмся.

int main()
{
    map<string,int> words;
    // Эта инициализация вектора специфична для C++11
    vector<string> input = {"hello", "world", "hello", "foo", "bar"};

    // Без C++11 можно сделать, например, вот так
    //vector<string> input;
    //input.push_back("hello");
    //input.push_back("world");
    //input.push_back("hello");
    //input.push_back("foo");
    //input.push_back("bar");

    for(unsigned int i = 0; i < input.size(); i++)
    {
        cout << "Adding into map: " << input[i] << endl;
        words[input[i]]++;  // Здесь мы неявно пользуемся тем, 
                            // что стандарт гарантирует нам инит по умолчанию, 
                            // который для int даст 0.
    }

    for (map<string,int>::iterator it = words.begin(); it != words.end(); it++)
    {
        cout << it->first << ": " << it->second << endl;
    }

    return 0;
}
