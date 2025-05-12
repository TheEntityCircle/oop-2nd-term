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

    vector<string> input;
    input.push_back("hello");
    input.push_back("world");
    input.push_back("hello");
    input.push_back("foo");
    input.push_back("bar");

    for(unsigned int i = 0; i < input.size(); ++i)
    {
        cout << "Adding into map: " << input[i] << endl;
        words[input[i]]++;  // Здесь мы неявно пользуемся тем, 
                            // что контейнер гарантирует нам инит по умолчанию, 
                            // который для int даст 0.
    }

    // Здесь it - итератор по map-е.
    // У элементов map-ы два поля, first - ключ, second - значение.
    for (map<string,int>::iterator it = words.begin(); it != words.end(); ++it)
    {
        cout << it->first << ": " << it->second << endl;
    }

    return 0;
}
