#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
 
// Отрезок на прямой, теперь он стал классом
class lineSegment
{
protected:
    float left;
    float right;

public:
    lineSegment(float left, float right)
    {
        this->left = left;
        this->right = right;
    }

    float getLeft() const
    {
        return left;
    }

    float getRight() const
    {
        return right;
    }

    // Теперь для сравнения будет использоваться перегруженный оператор
    bool operator <(const lineSegment& ls2) const
    {
        return left < ls2.left;
    }
};

// И для вывода тоже перегруженный оператор
std::ostream& operator<<(std::ostream& os, lineSegment& ls)
{
      os << "(" << ls.getLeft() << ", " << ls.getRight() << ")";
      return os;
}
 
int main()
{
    // Создаём вектор с отрезками в нём, здесь используется инициализация из C++11
    vector<lineSegment> lines =  { {6,8}, {1,9}, {2,4}, {4,7} };

    // Сортировка со своей функцией сравнения
    sort(lines.begin(), lines.end());

    // Вывод на экран
    for (unsigned int i = 0; i < lines.size(); ++i)
        cout << lines[i] << endl;

    return 0;
}
