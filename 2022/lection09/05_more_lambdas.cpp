#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
 
// Отрезок на прямой
struct lineSegment
{
    float left;
    float right;
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
        return (l1.right < l2.right);
    });

    cout << "Number of comparisons: " << count << endl;

    return 0;
}
