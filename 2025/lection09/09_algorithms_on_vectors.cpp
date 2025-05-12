#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Вывод vector-а чисел
ostream& operator<<(ostream& os, const vector<int>& v)
{
    for (vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
        os << *it << " ";
    return os;
}

// Можно сделать функтор, если нужно более сложное поведение
void input(int& a)
{
    cin >> a;
}

int main()
{
    vector<int> v(10);

    for_each(v.begin(), v.end(), input);

    // Ровно то же самое лямбдой
    // for_each(v.begin(), v.end(), [](int& a) { cin >> a; });
    
    cout << "Vector: " << v << endl;

    cout << "Max element: " 
         << *max_element(v.begin(), v.end()) << endl;

    cout << "Count of elements equal to 3: " 
         << count(v.begin(), v.end(), 3) << endl;

    cout << "Count of odd elements: "  
         << count_if(v.begin(), v.end(), [](int i){return i % 2 != 0;}) << endl;

    cout << "Count of even elements: "  
         << count_if(v.begin(), v.end(), [](int i){return i % 2 == 0;}) << endl;
    
    reverse(v.begin(), v.end());
    cout << "Vector after reverse: " << v << endl;

    rotate(v.begin(), next(v.begin()), v.end());
    cout << "Vector after rotate: " << v << endl;
    
    transform(v.begin(), v.end(), v.begin(), [](int i){return i * 2;});
    cout << "Vector after transform: " << v << endl;

    cout << boolalpha;
    cout << "All elements are >10: " 
         << all_of(v.begin(), v.end(), [](int i){return i > 10;}) << endl;

    cout << "All elements are <42: " 
         << all_of(v.begin(), v.end(), [](int i){return i < 42;}) << endl;

    cout << "There are elements >10: " 
         << any_of(v.begin(), v.end(), [](int i){return i > 10;}) << endl;

    cout << "There are elements <42: " 
         << any_of(v.begin(), v.end(), [](int i){return i < 42;}) << endl;
    
    return 0;
}
