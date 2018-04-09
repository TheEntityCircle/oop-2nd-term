#include <iostream>
#include <string>
#include <map>
#include <utility>  // Для std::pair и std::make_pair

using namespace std;

// Вывод map-ы
ostream& operator<<(ostream& os, const map<string,float>& m)
{
    for (map<string,float>::const_iterator it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << ": " << it->second << endl;
    }
    return os;
}

int main()
{
    // Пусть здесь хранятся условные "веса" каких-то ключевых слов
    map<string,float> keywords;

    // Вспомогательная сущность pair, именно с ними работает map внутри
    // Создаём, сразу заполняя значения
    pair<string,float> k1("foo", 0.1);
    // Создаём с помощью make_pair
    pair<string,float> k2;
    k2 = make_pair("bar", 0.2);

    // Вставим значения
    keywords.insert(k1);
    keywords.insert(k2);

    // Можно вставлять и вот так, что часто удобнее
    keywords["baz"] = 0.3;
    // Ну или вот так тоже, конечно, можно
    string word = "azaza";
    float weight = 0.4;
    keywords[word] = weight;

    cout << "Initial map:" << endl;
    cout << keywords;

    // А теперь попробуем вставить ключ, который уже есть,
    // в этот момент получим обновление старого значения
    keywords["foo"] = 99.9;

    cout << "Updated map:" << endl;
    cout << keywords;

    return 0;
}
