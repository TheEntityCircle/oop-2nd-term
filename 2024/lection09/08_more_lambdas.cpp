#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
 
// Отрезок на прямой
struct lineSegment
{
    float left;
    float right;

    // Такой метод в сортировку не запихнуть
    // Можно выкручиваться внутренними функторами или биндингами
    // Но это сложно, нештатно и лучше сортировать другими средствами
    // bool insideCompare(const lineSegment& l2)
    //{ 
    //   return (left < l2.left);
    //}
};

// Опять дублируем поведение функтором
class compareLineSegments {
public:
    unsigned long count;
    bool operator() (const lineSegment& l1, const lineSegment& l2)
    {
        count++;
        // cout << "comparator called" << endl;
        return (l1.left < l2.left);
    }
};
 
int main()
{
    // Создаём вектор с отрезками в нём
    vector<lineSegment> lines =  { {6,8}, {1,9}, {2,4}, {4,7} };

    unsigned long count = 0;

    // Функция сравнения задана как лямбда,
    // теперь она "захватывает" переменную count, причём по референсу
    sort(lines.begin(), lines.end(), [&count](const lineSegment& l1, const lineSegment& l2) {
        count++;
        return (l1.left < l2.left);
    });

    cout << "Number of comparisons by lambda " << count << endl;

    // Именованная лямбда, так тоже можно
    unsigned long count_again = 0;
    // А что бы тут было вместо auto...
    auto l = [&count_again](const lineSegment& l1, const lineSegment& l2) {
        count_again++;
        return (l1.left > l2.left);
    };

    sort(lines.begin(), lines.end(), l);

    cout << "Number of comparisons by named lambda " << count_again << endl;

    // Буквально то же самое, но функтором - не работает
    // Попробуйте понять и допилить
    compareLineSegments comparator{0};
    sort(lines.begin(), lines.end(), comparator);
    
    cout << "Number of comparisons by functor: " << comparator.count << endl;

    return 0;
}
