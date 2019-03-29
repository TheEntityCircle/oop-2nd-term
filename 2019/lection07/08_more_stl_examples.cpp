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
bool compareSegments(lineSegment l1, lineSegment l2)
{
    return (l1.left < l2.left);
}
 
int main()
{
    // Создаём вектор с отрезками в нём, здесь используется инициализация из C++11
    vector<lineSegment> lines =  { {6,8}, {1,9}, {2,4}, {4,7} };

    // Сортировка со своей функцией сравнения
    sort(lines.begin(), lines.end(), compareSegments);

    // Вывод на экран
    for (unsigned int i = 0; i < lines.size(); i++)
        cout << "(" << lines[i].left << ", " << lines[i].right << ")" << endl;

    return 0;
}
