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

    // Такой метод в сортировку просто так не запихнуть
    // Давайте выкручиваться биндингами
    // Это сложно, нештатно и лучше сортировать другими средствами
    bool insideCompare(const lineSegment& l2)
    { 
       return (left > l2.left);
    }
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
 
int main()
{
    // Создаём вектор с отрезками в нём
    vector<lineSegment> lines =  { {6,8}, {1,9}, {2,4}, {4,7} };

    cout << lines << endl;

    // Перепрошитая функция, которая умеет перекидывать методу указатель на this
    auto f_method_binded = std::bind(&lineSegment::insideCompare, placeholders::_1, placeholders::_2); 

    // И эту обертку уже можно запихнуть в sort
    sort(lines.begin(), lines.end(), f_method_binded);

    cout << lines << endl;    

    return 0;
}
