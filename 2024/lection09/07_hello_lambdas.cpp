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

ostream& operator<< (ostream& os, const lineSegment& ls)
{
    os << "{ " << ls.left << ", " << ls.right <<"} ";
    return os;
}

ostream& operator<< (ostream& os, const vector<lineSegment>& vls)
{
    os << "{ ";
    for (auto ls : vls)
     os << ls << ", ";
    os << "}" << endl;
    return os;
}
 
// Как будем сравнивать отрезки при сортировке - кто 'больше' и кто 'меньше'
bool compareSegments(const lineSegment& l1, const lineSegment& l2)
{
    return (l1.left < l2.left);
}


// То же самое, но функтором
class compareLineSegments {
public:
    bool operator() (const lineSegment& l1, const lineSegment& l2)
    {
        return (l1.left < l2.left);
    }
};
 
int main()
{
    // Создаём вектор с отрезками в нём
    vector<lineSegment> lines =  { {6,8}, {1,9}, {2,4}, {4,7} };
    cout << "Before sort: " << endl << lines;

    // Сортировка со своей функцией сравнения
    sort(lines.begin(), lines.end(), compareSegments);
    cout << "After sort by left: " << endl << lines;

    // И ещё раз, теперь функция сравнения задана как лямбда
    sort(lines.begin(), lines.end(), [](const lineSegment& l1, const lineSegment& l2) {
        return (l1.right < l2.right);
    });
    cout << "After sort by right: " << endl << lines;

    // А теперь как функтор
    compareLineSegments comparator;
    sort(lines.begin(), lines.end(), comparator);
    cout << "Again sort by left: " << endl << lines;
    // Или прямо при вызове экземпляр создать, вызвав конструктор по умолчанию
    // sort(lines.begin(), lines.end(), compareLineSegments());

    return 0;
}
