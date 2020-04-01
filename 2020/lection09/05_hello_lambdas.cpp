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
 
// Как будем сравнивать отрезки при сортировке - кто 'больше' и кто 'меньше'
bool compareSegments(const lineSegment& l1, const lineSegment& l2)
{
    return (l1.left < l2.left);
}
 
int main()
{
    // Создаём вектор с отрезками в нём
    vector<lineSegment> lines =  { {6,8}, {1,9}, {2,4}, {4,7} };

    // Сортировка со своей функцией сравнения
    sort(lines.begin(), lines.end(), compareSegments);

    // И ещё раз, теперь функция сравнения задана как лямбда
    sort(lines.begin(), lines.end(), [](const lineSegment& l1, const lineSegment& l2) {
        return (l1.right < l2.right);
    });

    return 0;
}
